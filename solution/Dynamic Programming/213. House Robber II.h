#include "../global.h"
class Solution {
public:
    // 状态转移方程： f[x] = max(f[x-2] + nums[i], f[x-1])
    // f[n+1] = max(f(n), f(n−1) + num)
    int my_rob(vector<int>& nums)
    {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];

        int first = nums[0];
        int second = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++)
        {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }

        return second;
    }

    int rob(vector<int>& nums)
    {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];

        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());

        return max(my_rob(v1), my_rob(v2));
    }
};