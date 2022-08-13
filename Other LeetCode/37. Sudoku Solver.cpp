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










