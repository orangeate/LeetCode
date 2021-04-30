#include "../global.h"
/*
 * `candidates` 中的数字可以无限制重复被选取。选择后index不增加。
 */
class Solution {
public:
    void dfs(vector<int>& candidates, int target, int sum, int index, vector<vector<int>>& ans, vector<int>& st)
    {
        if(sum == target)
        {
            ans.emplace_back(st);
            return;
        }
        if(index == candidates.size() || sum > target)
            return;

        //不选择
        dfs(candidates, target, sum, index+1, ans, st);

        //选择
        st.emplace_back(candidates[index]);
        dfs(candidates, target, sum + candidates[index], index, ans, st);
        st.pop_back();

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> st;

        dfs(candidates, target, 0, 0, ans, st);

        return ans;
    }
};
