#include "../global.h"
class Solution {
public:
    /* ---- ----
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> ans;
        if(nums.size() == 0)
            return ans;

        int pre = nums[0];
        int begin = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == pre+1)
                pre++;
            else
            {
                if(begin == pre)
                    ans.push_back(to_string(begin));
                else
                    ans.push_back(to_string(begin) + "->" + to_string(pre));
                pre = nums[i];
                begin = pre;
            }
        }
        if(begin == pre)
            ans.push_back(to_string(begin));
        else
            ans.push_back(to_string(begin) + "->" + to_string(pre));

        return ans;
    }
    */
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0;
        int n = nums.size();

        while (i < n)
        {
            int begin = i;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1)
                i++;
            int end = i - 1;

            string str = to_string(nums[begin]);
            if (begin < end)
            {
                str.append("->");
                str.append(to_string(nums[end]));
            }
            ans.push_back(move(str));
        }
        return ans;
    }
};
