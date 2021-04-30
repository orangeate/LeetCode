#include "../global.h"
/*
 * 将空间优化为O(n) todo
 */
class Solution {
public:
    // f(0) = triangle[0][0]
    // f(x+1, y+1) = triangle[x+1][y+1] + min(cost[x][y], cost[x][y+1]);

    int minimumTotal(vector<vector<int>>& triangle)
    {
        int size = triangle.size();
        if(size == 0)
            return 0;

        vector<vector<int>> cost(size, vector<int>(size));
        cost[0][0] = triangle[0][0];

        for(int i = 1; i < triangle.size(); i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j-1 < 0)
                    cost[i][j] = triangle[i][j] + cost[i-1][j];
                else if(j == i)
                    cost[i][j] = triangle[i][j] + cost[i-1][j-1];
                else
                    cost[i][j] = triangle[i][j] + min(cost[i-1][j-1], cost[i-1][j]);
            }
        }

        int ans = INT_MAX;
        for(int i : cost[size-1])
            ans = min(ans, i);

        return ans;
    }
};