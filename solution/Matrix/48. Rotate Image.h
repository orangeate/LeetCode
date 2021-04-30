#include "../global.h"
class Solution {
public:
    /* ---- 先水平，再沿对象线 ----*/
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        if(n <= 1)
            return ;

        // 水平
        for(int i = 0; i < n/2; i++)
            for(int j = 0; j < n; j++)
                swap(matrix[i][j], matrix[n-i-1][j]);

        // 对角线
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};