#include "../global.h"
class Solution {
public:
    /* ---- set ----
    int findDuplicate(vector<int>& nums)
    {
        unordered_set<int> uset;
        for(auto num : nums)
            if(uset.find(num) != uset.end())
                return num;
            else
                uset.insert(num);

        return -1;
    }
    */
    /* ---- sort + 遍历 ---- */
    int findDuplicate(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int pre = -1;
        for(auto num : nums)
        {
            if(pre == num)
                return num;
            else
                pre = num;
        }
        return -1;
    }
};
