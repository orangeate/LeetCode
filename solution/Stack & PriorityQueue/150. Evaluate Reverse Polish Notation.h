#include "../global.h"
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;

        for(auto s : tokens)
        {
            if(s == "+" || s == "-" || s == "*" || s == "/")
            {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();

                if(s == "+") st.push(num2 + num1);
                if(s == "-") st.push(num2 - num1);
                if(s == "*") st.push(num2 * num1);
                if(s == "/") st.push (num2 / num1);
            }
            else
                st.push(stoi(s));
        }
        return st.top();
    }
};