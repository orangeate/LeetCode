#include "../global.h"
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        if(nums.size() < 2)
            return nums;

        vector<int> ans;

        int maj_1 = 0, maj_2 = 1;
        int count_1 = 0, count_2 = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(maj_1 == nums[i])
                count_1++;
            else if(maj_2 == nums[i])
                count_2++;
            else if(count_1 == 0)
            {
                maj_1 = nums[i];
                count_1++;
            }
            else if(count_2 == 0)
            {
                maj_2 = nums[i];
                count_2++;
            }
            else
            {
                count_1--;
                count_2--;
            }

        }
        count_1 = 0, count_2 = 0;
        for(auto num : nums)
        {
            if(num == maj_1)
                count_1++;
            if(num == maj_2)
                count_2++;
        }

        if(count_1 > nums.size() / 3)
            ans.push_back(maj_1);
        if(count_2 > nums.size() / 3)
            ans.push_back(maj_2);

        return ans;
    }
};
