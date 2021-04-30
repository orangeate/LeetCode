#include "../global.h"
/*
 * 包含重复数字的序列
 */
class Solution {
public:
    void backtrack(vector<int> nums, vector<vector<int>>& ans, int k)
    {
        if(k == nums.size())
        {
            ans.emplace_back(nums);
            return;
        }

        for(int i = k; i < nums.size(); i++)
        {
            if(i != k && nums[i]==nums[k])
                continue;
            swap(nums[k], nums[i]);
            backtrack(nums, ans, k+1);
            //swap(nums[k], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        backtrack(nums, ans, 0);

        return ans;
    }
};
