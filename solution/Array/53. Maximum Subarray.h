#include "../global.h"
/*
    动态规划
    贪心算法
    分治
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int pre_sum = 0;
        int max = INT_MIN;

        for(int i = 0; i < nums.size(); i++)
        {
            if(pre_sum < 0) pre_sum = 0;
            pre_sum += nums[i];
            if(pre_sum > max)
                max = pre_sum;
        }
        return max;
    }
};
