#include "../global.h"
class Solution {
public:
    /* ---- 排序 ----
    int solution(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int min = 0;
        for(auto i : nums)
        {
            if(i < 1)
                continue;
            if(i - min > 1)
            {
                return min + 1;
            }
            min = i;
        }
        return min + 1;
    }
    */
    /* ---- 哈希 ---- */
    int solution_2(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= 0)
                nums[i] = INT_MAX;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(abs(nums[i]) <= nums.size() && nums[abs(nums[i])-1] > 0)
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0) return i+1;
        }
        return nums.size()+1;
    }

    int firstMissingPositive(vector<int>& nums)
    {
        return solution(nums);
    }
};
