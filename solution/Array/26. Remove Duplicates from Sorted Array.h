#include "../global.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() < 2)
            return nums.size();

        int k = 0;
        int size = nums.size();

        for(int i = 1; i < size; i++)
        {
            if(nums[k] != nums[i])
                nums[++k] = nums[i];
        }

        return k+1;
    }
};
