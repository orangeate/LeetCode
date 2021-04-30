#include "../global.h"
/*
 * 找出和为给定目标正整数的组合的个数。回溯超时。动态规划有序完全背包问题。
 */
class Solution {
public:
    /*        --------- 回溯(超时)-------------
    void dfs(vector<int>& candidates, int target, int sum, int index, int& ans, int& st)
    {
        if(sum == target)
        {
            ans++;
            return;
        }
        if(index == candidates.size() || sum > target)
            return;

        //不选择
        dfs(candidates, target, sum, index+1, ans, st);

        //选择
        st += candidates[index];
        dfs(candidates, target, sum + candidates[index], 0, ans, st);
        st -= candidates[index];
    }

    int combinationSum4(vector<int>& nums, int target)
    {
        int ans = 0;
        int st = 0;

        dfs(nums, target, 0, 0, ans, st);

        return ans;
    }
    */

    /*  0-1 背包问题 动态规划 有序完全背包问题
        状态转移方程：
        dp[i]: i为要得到的数字
        -------------------------
        nums = [1, 2, 4]
        target = 5

        dp[5] = dp[5-1] + dp[5-2] + dp[5-4] = dp[4] + dp[3] + d[1] = 6 + 3 + 1 = 10
        dp[4] = dp[4-1] + dp[4-2] + dp[4-4] = dp[3] + dp[2] + dp[0] = 3 + 2 + 1 = 6
        dp[3] = dp[3-1] + dp[3-2] = dp[2] + dp[1] = 1 + 2 = 3
        dp[2] = dp[2-1] + dp[2-2] = 1 + 1 = 2
        dp[1] = dp[1-1] = dp[0] = 1
        dp[0] = 1
        -------------------------
        dp[i] = dp[i] + dp[i-num[0]] + ... + dp[i-num[num.size()-1]]
        dp[0] = 1;
        for(int i = 1; i <= target; i++)
            for(auto i :nums)
                dp[i] += i;
    */

    int combinationSum4(vector<int>& nums, int target)
    {
        if(nums.size() == 0)
            return 0;

        vector<unsigned long long> dp(target + 1);
        for(auto i : dp)
            i = 0;
        dp[0] = 1;

        sort(nums.begin(), nums.end());

        for(int i = 1; i <= target; i++)
            for(auto num :nums)
                if(i >= num)
                    dp[i] += dp[i-num];
        return dp[target];
    }
};
