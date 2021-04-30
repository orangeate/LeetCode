#include "../global.h"
class Solution {
public:
    /* ---- 回溯（超时） ----
    void dfs(vector<int>& nums, int index, int sum, bool last, int& ans)
    {
        if(index == nums.size())
        {
            if(sum > ans)
                ans = sum;
            return;
        }
        if(last == true)
            dfs(nums, index+1, sum, false, ans);
        else
        {
            // 不偷
            dfs(nums, index+1, sum, false, ans);

            // 偷
            sum += nums[index];
            dfs(nums, index+1, sum, true, ans);
            sum -= nums[index];
        }
    }
    int rob(vector<int>& nums)
    {
        int ans = 0;
        dfs(nums, 0, 0, false, ans);
        return ans;
    }
    */

    /* ---- 动态规划，递归（超时）【自上而下】 ----
    // 状态转移方程： f[x] = max(f[x-2] + nums[i], f[x-1])
    int f(int x, const vector<int>& nums)
    {
        if(x < 1)
            return 0;
        if(x == 1)
            return nums[x-1];
        if(x == 2)
            return max(nums[x-1], nums[x-2]);

        return max(f(x-2, nums) + nums[x-1], f(x-1, nums));
    }
    int rob(vector<int>& nums)
    {
        return f(nums.size(), nums);
    }
    */

    /* ---- 动态规划，使用数组dp记录【自下而上】 ----
    // 状态转移方程： f[x] = max(f[x-2] + nums[i], f[x-1])
    int rob(vector<int>& nums)
    {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];

        vector<int> dp = vector<int>(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        return dp[dp.size()-1];
    }
    */

    /* ---- （优化） ----*/
    int rob(vector<int>& nums)
    {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];

        int first = nums[0], second = max(nums[0], nums[1]);
        first = nums[0];
        second = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++)
        {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }

        return second;
    }
};