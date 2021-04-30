class Solution {
public:

    void dfs(const int& n, const int& k, int index, vector<vector<int>>& ans, vector<int>& st)
    {
        if(st.size() == k)
        {
            ans.push_back(st);
            return;
        }
        if(index == n)
            return;

        dfs(n, k, index+1, ans, st);

        st.push_back(index+1);
        dfs(n, k, index+1, ans, st);
        st.pop_back();
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> st;

        dfs(n, k, 0, ans, st);
        return ans;
    }
};
