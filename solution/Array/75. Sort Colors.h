#include "../global.h"
class Solution {
public:
    /* ---- 单指针 ----*/
    void sortColors(vector<int>& nums)
    {
        int left = 0, right = nums.size()-1;

        for(int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            if(nums[i] == 0)
            {
                nums[i] = nums[left];
                nums[left++] = temp;
            }
        }

        for(int i = nums.size()-1; i >= 0; i--)
        {
            int temp = nums[i];
            if(nums[i] == 2)
            {
                nums[i] = nums[right];
                nums[right--] = temp;
            }
        }
    }
};
