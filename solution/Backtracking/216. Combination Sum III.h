#include "../global.h"
/*
 * 不存在重复的数字，解集不能包含重复的组合。
 */
class Solution {
public:

    void dfs(vector<vector<int>>& ans, vector<int>& nums, int num, int sum, int k, const int& target)
    {
        if(k == 0)
        {
            if(sum == target)
                ans.push_back(nums);
            return;
        }
        if(num > 9)
            return;

        //不选择
        dfs(ans, nums, num+1, sum, k, target);

        //选择
        nums.push_back(num);
        dfs(ans, nums, num+1, sum+num, k-1, target);
        nums.pop_back();

    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> nums;

        dfs(ans, nums, 1, 0, k, n);

        return ans;
    }
};
