#include "../global.h"
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        unordered_multiset<int> my_set;

        for(auto i : nums1)
        {
            my_set.insert(i);
        }
        for(auto i : nums2)
        {
            if(my_set.find(i) != my_set.end())
            {
                ans.push_back(i);
                my_set.erase(my_set.find(i));
            }
        }
        return ans;
    }
};
