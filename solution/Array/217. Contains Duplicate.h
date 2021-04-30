#include "../global.h"
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int, int> my_map;
        for(auto i : nums)
        {
            my_map[i]++;
            if(my_map[i] > 1)
                return true;
        }
        return false;
    }
};
