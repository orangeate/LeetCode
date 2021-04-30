#include "../global.h"
/*
 * `candidates` 中的每个数字在每个组合中只能使用一次。选择后index增加。
 */
class Solution {
public:
    void dfs(vector<pair<int, int>>& candidates, int target, int sum, int index, vector<vector<int>>& ans, vector<int>& st)
    {
        // candidates first : 数字
        // candidates second : 出现的次数

        if(sum == target)
        {
            ans.push_back(st);
            return;
        }
        if(index == candidates.size() || sum > target)
            return;

        // 选择
        if(candidates[index].second >= 1)
        {
            candidates[index].second--;
            st.push_back(candidates[index].first);
            dfs(candidates, target, sum + candidates[index].first, index, ans, st);
            st.pop_back();
            candidates[index].second++;
        }
        // 不选择
        dfs(candidates, target, sum, index+1, ans, st);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> st;

        // 将相同的数放在一起进行处理
        sort(candidates.begin(), candidates.end());

        vector<pair<int, int>> umap;
        // 统计数组中每个数出现的次数
        // unordered_map<int, int> umap;
        for(auto i : candidates)
        {
            if(umap.empty() || umap.back().first != i)
                umap.push_back({i, 1});
            else
                umap.back().second++;
        }

        dfs(umap, target, 0, 0, ans, st);

        return ans;
    }
};
