#include "../global.h"
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        unordered_set<int> my_set;

        for(auto i : nums1)
        {
            if(my_set.find(i) == my_set.end())
                my_set.insert(i);
        }
        for(auto i : nums2)
        {
            if(my_set.find(i) != my_set.end())
            {
                ans.push_back(i);
                my_set.erase(i);
            }
        }
        return ans;
    }
};
