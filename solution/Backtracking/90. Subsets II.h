#include "../global.h"
/*
 * dfs回溯 不包含重复的子集
 */
class Solution {
public:
    void dfs(vector<int>& nums, int index, vector<int>& st, vector<vector<int>>& ans)
    {
        if(index == nums.size())
        {
            ans.push_back(st);
            return;
        }

        dfs(nums, index+1, st, ans);

        st.push_back(nums[index]);
        dfs(nums, index+1, st, ans);
        st.pop_back();

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> st;

        dfs(nums, 0, st, ans);

        return ans;

    }
};
