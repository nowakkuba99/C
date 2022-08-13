/*
    First solution uses sets to store cureent numbers
    It is slower in solving 9x9 sudoku since looping thorugh 9 values is not long 
    However such solution can be converted to bigger boards
*/

#include<vector>
#include<unordered_set>
using namespace std;

class Solution_with_sets {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //Allocate memory for sets
        vector<unordered_set<char>> rowSet(9);
        vector<unordered_set<char>> colSet(9);
        vector<vector<unordered_set<char>>> boxSet(3,vector<unordered_set<char>>(3));
        //Create sets
        createSets(board,rowSet,colSet,boxSet);
        //Solve from left upper corner down
        tryToSolve(board,0,0,rowSet,colSet,boxSet);
    }
private:

    //Function to initialize sets
    void createSets(vector<vector<char>>& board,vector<unordered_set<char>>& rowSet,vector<unordered_set<char>>& colSet,
                    vector<vector<unordered_set<char>>>& boxSet)
    {
        for(int row = 0; row<9; row++)          //Iterate through all rows
        {
            for(int col = 0; col<9; col++)      //Iterate through all cols
            {
                char ch = board[row][col];
                if( ch != '.')                  //If place is not empty
                {
                    rowSet[row].insert(ch);             //Add to rowSet
                    colSet[col].insert(ch);             //Add to colSet
                    boxSet[row/3][col/3].insert(ch);    //Add to boxSet
                }
            }
        }
    }
    //Function to check if adding number is ok
    bool checkIfValid(vector<vector<char>>& board,int row, int col,char ch,vector<unordered_set<char>>& rowSet,vector<unordered_set<char>>& colSet,
                    vector<vector<unordered_set<char>>>& boxSet)
    {
        if(rowSet[row].find(ch) == rowSet[row].end()                        //Not in rowSet
          && colSet[col].find(ch) == colSet[col].end()                      //Not in colSet
          && boxSet[row/3][col/3].find(ch) == boxSet[row/3][col/3].end())   //Not in boxSet
            return true;            //Return true
        return false;           //Else return false
    }
    void addGuess(vector<vector<char>>& board,int row, int col,char guess,vector<unordered_set<char>>& rowSet,vector<unordered_set<char>>& colSet,vector<vector<unordered_set<char>>>& boxSet)
    {
        board[row][col] = guess;
        rowSet[row].insert(guess);             //Add to rowSet
        colSet[col].insert(guess);             //Add to colSet
        boxSet[row/3][col/3].insert(guess);    //Add to boxSet
    }
    void deleteGuess(vector<vector<char>>& board,int row, int col,char guess,vector<unordered_set<char>>&       rowSet,vector<unordered_set<char>>& colSet, vector<vector<unordered_set<char>>>& boxSet)
    {
        board[row][col] = '.';
        rowSet[row].erase(guess);             //Delete from rowSet
        colSet[col].erase(guess);             //Delete from colSet
        boxSet[row/3][col/3].erase(guess);    //Delete from boxSet
    }
    //Recursive function to call
    bool tryToSolve(vector<vector<char>>& board,int rowStart, int colStart,vector<unordered_set<char>>& rowSet,vector<unordered_set<char>>& colSet,vector<vector<unordered_set<char>>>& boxSet)
    {
        //Main loop
        for(int row = rowStart; row<9; row++)           //Start from given row to the end
        {
            for(int col = colStart; col<9; col++)       //Strat from given column to the end
            {
                char ch = board[row][col];      //Save current chat to variable
                if(ch == '.')                   //If current place is not filled
                {
                    for(int guess = 1; guess<10; guess++)       //Try all guesses from 1 till 9
                    {
                        if(checkIfValid(board,row,col,guess+'0',rowSet,colSet,boxSet))      //If guess is valid
                        {
                            addGuess(board,row,col,guess+'0',rowSet,colSet,boxSet);         //Add to the sets and board
                            if(tryToSolve(board,(row+((col+1)/9)),(col+1)%9,rowSet,colSet,boxSet))  //Try to solve new board
                                return true;                                                        //If successfull then return true
                            deleteGuess(board,row,col,guess+'0',rowSet,colSet,boxSet);      //If no success delte guess
                        }
                    }
                    return false;           //All guesses made and no return
                }
            }
            colStart=0;         //If iterated through all columns, reset starting value for columns
        }
        return true;            //After reaching the end return true
    }
};





class Solution_with_for_loops {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);                                                              //Start solving in left up corner
    }
private:
    bool checkIfValid(vector<vector<char>>& board, char guess, int row, int col)        //Check if given guess can be inserted at row,col
    {
        for(int rowIt = 0; rowIt<9; rowIt++)            //Check column
            if(board[rowIt][col] == guess)
                return false;
        for(int colIt = 0; colIt<9; colIt++)            //Check row
            if(board[row][colIt] == guess)
                return false;
        int boxRow = (row/3)*3, boxCol = (col/3)*3;     //Get box start indexies
        for(int rowIt = 0; rowIt<3; rowIt++)            //Check box
        {
            for(int colIt = 0; colIt<3; colIt++)
            {
                if(board[boxRow + rowIt][boxCol + colIt] == guess)
                    return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int rowStart, int colStart)                //Recursive call function
    {
        for(int row = rowStart; row<9; row++)                                           //Iterate through rows
        {
            for(int col = colStart; col<9; col++)                                       //Itarate through cols
            {
                char ch = board[row][col];                                              //Save char to variable
                if(ch == '.')                                                           //If empty
                {
                    for(char guess = '1'; guess <='9'; guess++)                         //Try guessing 1-9
                    {
                        if(checkIfValid(board,guess,row,col))                           //Check if guess can be placed on board
                        {
                            board[row][col] = guess;                                    //Place guess on board
                            if(helper(board,row+(col+1)/9,(col+1)%9))                   //If solved then return true
                                return true;
                            board[row][col] = '.';                                      //Else remove guess and move on
                        }
                    }
                    return false;                                                       //If all guesses 0-9 not possible return false     
                }
            }
            colStart = 0;                                                               //If all columns passed, zero colStart
        }
        return true;
    }
};




