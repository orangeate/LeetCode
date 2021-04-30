#include "../global.h"
class Solution {
public:

    void backtrack(int n, vector<string>& ans, string& str, int flag)
    {
        if(n == 0 && flag == 0)
        {
            ans.push_back(str);
            return;
        }
        // (
        if(n != 0)
        {
            str.push_back('(');
            backtrack(n-1, ans, str, flag+1);
            str.pop_back();
        }
        // )
        if(flag > 0)
        {
            str.push_back(')');
            backtrack(n, ans, str, flag-1);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string str;
        int flag = 0;

        backtrack(n, ans, str, 0);
        return ans;
    }
};
