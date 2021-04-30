#include "../global.h"
class Solution {
public:
    /*     ---- 超时 ---- 回溯
        int f(int m, int n)
        {
            //f(m, n) = f(m-1,n) + f(m, n-1);
            //f(1, 1) = 1;

            if(m == 1 && n == 1)
                return 1;
            if(m == 0 || n == 0)
                return 0;
            return f(m-1, n) + f(m, n-1);
        }
    */

    // f(m, n) = f(m-1, n) + f(m, n-1);
    // f(1, 1) = 1;
    //     ---- 动态规划 ----
    //     ---- 空间换时间 ----
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> f(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        {
            f[i][0] = 1;
        }
        for(int i = 0; i < n; i++)
        {
            f[0][i] = 1;
        }

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
            {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }

        return f[m-1][n-1];
    }

};