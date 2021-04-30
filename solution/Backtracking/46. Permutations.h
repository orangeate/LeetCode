#include "../global.h"
/*
 * 没有重复数字的序列
 */
class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int k)
    {
        if(k == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i = k; i < nums.size(); i++)
        {
            swap(nums[k], nums[i]);
            backtrack(nums, ans, k+1);
            swap(nums[k], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;

        backtrack(nums, ans, 0);

        return ans;
    }
};
