#include "../global.h"
class Solution {
public:
    /* ---- 额外数组 ---- */
    void solution(vector<int>& nums, int k)
    {
        int size = nums.size();
        vector<int> ans(size);
        for(int i = 0; i < size; i++)
        {
            ans[(i+k)%size] = nums[i];
        }
        nums.assign(ans.begin(), ans.end());
    }

    /* ---- 反转 ----
    void solution(vector<int>& nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
    */

    /* ---- 双循环【超时】 ----
    void solution_3(vector<int>& nums, int k)
    {
        int size = nums.size();
        k = k % size;
        for(int i = 0; i < k; i++)
        {
            int temp = nums[size-1];
            for(int j = size-1; j>0; j--)
            {
                nums[j] = nums[j-1];
            }
            nums[0] = temp;
        }
    }
    */
    void rotate(vector<int>& nums, int k)
    {
        solution(nums, k);
    }
};

