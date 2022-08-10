#include <vector>
using namespace std;
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(),result=0;
        //vector<int> maxRow,maxCol(n,0);
        vector<int> maxRow(n,0),maxCol(n,0);
        /*
        for(int i = 0;i<n;i++)
        {
            maxRow.push_back(*max_element(grid[i].begin(),grid[i].end()));
        }
        */
        for(int i = 0; i<n;i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j]>maxCol[j])
                    maxCol[j] = grid[i][j];
                if(grid[i][j]>maxRow[i])
                    maxRow[i] = grid[i][j];
            }
        }
        for(int i = 0; i<n;i++)
        {
            for(int j = 0; j<n; j++)
            {
                    result += min(maxRow[i],maxCol[j]) - grid[i][j];
            }
        }
        
        return result;
    }
};