#include "../global.h"
class Solution {
public:
    // 动态规划
    // 状态转移方程： f(n) = min(f(n), f(n-square(1))+1, f(n-square(2))+1, ...);
    int numSquares(int n)
    {
        vector<int> count(n+1, n+1);
        count[0] = 0;

        int nums_size = sqrt(n) + 1;
        vector<int> square_nums(nums_size);
        for(int i = 1; i < nums_size; i++)
        {
            square_nums[i] = i * i;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < square_nums.size(); j++)
            {
                if(i < square_nums[j]) break;
                count[i] = min(count[i], count[i - square_nums[j]]+1);
            }
        }

        return count[n];
    }
};