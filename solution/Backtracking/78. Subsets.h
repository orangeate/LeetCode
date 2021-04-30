#include "../global.h"
/*
 * dfs回溯 不包含重复的子集
 */
class Solution {
public:
    void dfs(vector<int>& nums, int index, vector<int> st, vector<vector<int>>& ans)
    {
        // 到达叶子节点
        if(index == nums.size())
        {
            ans.push_back(st);
            return;
        }
        // 不选择index
        dfs(nums, index+1, st, ans);
        // 选择index
        st.push_back(nums[index]);
        dfs(nums, index+1, st, ans);
        // 状态重置
        st.pop_back();

    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        if(nums.size() == 0)
            return ans;

        vector<int> st;
        dfs(nums, 0, st, ans);

        return ans;
    }
};
