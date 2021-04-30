#include "../global.h"
/*
排序后返回中位数
摩尔投票法
使用经典的分治算法递归求解，直到所有的子问题都是长度为 1 的数组。长度为 1 的子数组中唯一的数显然是众数，直接返回即可。如果回溯后某区间的长度大于 1，我们必须将左右子区间的值合并。如果它们的众数相同，那么显然这一段区间的众数是它们相同的值。否则，我们需要比较两个众数在整个区间内出现的次数来决定该区间的众数。
 */
class Solution {
public:
    /*
    int solution(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return(nums[nums.size() / 2]);
    }
    */
    int solution(vector<int>& nums)
    {
        int maj = nums[0];
        int count = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(count == 0)
            {
                maj = nums[i];
                count++;
                continue;
            }
            if(nums[i] == maj)
                count++;
            else
                count--;
        }
        return maj;
    }
    int majorityElement(vector<int>& nums)
    {
        return solution(nums);
    }
};
