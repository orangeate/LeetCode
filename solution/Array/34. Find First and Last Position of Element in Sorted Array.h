#include "../global.h"
class Solution {
public:
    /* ---- 二分查找 ----
        时间复杂度要求: O(logn)
    */
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if(nums.size() == 0)
            return {-1, -1};

        int left = 0;
        int right = nums.size()-1;

        int mid = 0;
        while(left <= right)
        {
            mid = left + (right - left) / 2;

            if(nums[mid] == target)
                break;
            if(nums[mid] < target)
                left = mid +1;
            else
                right = mid -1;
        }

        if(nums[mid] != target)
            return {-1, -1};

        left = right = mid;
        while(left-1 >= 0 && nums[left-1] == target)
            left--;
        while(right+1 < nums.size() && nums[right+1] == target)
            right++;

        return {left, right};
    }
};
