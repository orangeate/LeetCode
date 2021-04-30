#include "../global.h"
class Solution {
public:
    /* ---- 双for循环 ----
    int maxArea(vector<int>& height)
    {
        int ans = 0;
        for(int i = 0; i < height.size()-1; i++)
        {
            for(int j = i+1; j < height.size(); j++)
            {
                int v = (j - i) * min(height[i], height[j]);
                if(v > ans)
                    ans = v;
            }
        }
        return ans;
    }
    */
    /* ---- 双指针 ----*/
    int maxArea(vector<int>& height)
    {
        int ans = 0;

        int begin = 0;
        int end = height.size()-1;

        while(begin != end)
        {
            int h = min(height[begin], height[end]);
            int v = (end-begin) * h;
            ans = max(ans, v);

            height[begin] > height[end] ? end-- : begin++;
        }
        return ans;
    }
};
