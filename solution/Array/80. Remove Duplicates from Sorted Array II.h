#include "../global.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int l = 0;
        for(int r = 0; r < nums.size(); r++)
        {
            if(l < 2 || nums[l-2] < nums[r])
            {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};
