#include "../global.h"
class Solution {
public:
    unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };

    void backtrack(string digits, int index, vector<string>& ans, string& str)
    {
        if(index == digits.size())
        {
            ans.push_back(str);
            return;
        }

        string alp = phoneMap[digits[index]];
        for(auto c : alp)
        {
            str.push_back(c);
            backtrack(digits, index+1, ans, str);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string str;

        if(digits.size() == 0)
            return ans;

        backtrack(digits, 0, ans, str);

        return ans;
    }
};
