#include "../global.h"
class Solution {
public:

    /* ---- ----
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        if (nums.size() == 0)
            return false;
        if (nums.size() <= k)
            k = nums.size() -1;

        unordered_set<int> my_set;

        for (int i = 0; i <= k; i++)
        {
            if(my_set.find(nums[i]) != my_set.end())
                return true;
            else
                my_set.insert(nums[i]);
        }

        for(int j = k+1, i = 0; j < nums.size(); j++)
        {
            my_set.erase(nums[i++]);
            if(my_set.find(nums[j]) != my_set.end())
                return true;
            else
                my_set.insert(nums[j]);
        }

        return false;
    }
    */

    /*---- 散列表 + 滑动窗口 ----*/
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> nmap;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nmap.find(nums[i]) == nmap.end())  // nmap.count(nums[i]) == 0
                nmap[nums[i]] = i;
            else if(i - nmap[nums[i]] <= k)
                return true;
            else
                nmap[nums[i]] = i;
        }
        return false;
    }
};
