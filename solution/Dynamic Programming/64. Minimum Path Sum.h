#include "../global.h"
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = 0;
        if(row > 0) col = grid[0].size();

        vector<vector<int>> path(row, vector<int>(col));
        path[0][0] = grid[0][0];
        for(int i = 1; i < row; i++)
            path[i][0] = grid[i][0] + path[i-1][0];
        for(int j = 1; j < col; j++)
            path[0][j] = grid[0][j] + path[0][j-1];

        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
                path[i][j] = min(path[i-1][j], path[i][j-1]) + grid[i][j];

        return path[row-1][col-1];
    }
};
