#include "../global.h"
class Solution {
public:

    //f(m, n) = f(m-1,n) + f(m, n-1);
    //f(1, 1) = 1;

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if(obstacleGrid.size() == 0)
            return 1;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n));

        if(obstacleGrid[0][0] == 1)
            return 0;

        bool block = false;
        for(int i = 0; i < m; i++)
        {
            if(obstacleGrid[i][0] == 0 && !block)
                f[i][0] = 1;
            else
            {
                f[i][0] = 0;
                block = true;
            }
        }
        block = false;
        for(int i = 0; i < n; i++)
        {
            if(obstacleGrid[0][i] == 0 && !block)
                f[0][i] = 1;
            else
            {
                f[0][i] = 0;
                block = true;
            };
        }

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    f[i][j] = 0;
                else
                    f[i][j] = f[i-1][j] + f[i][j-1];
            }

        return f[m-1][n-1];
    }
};
