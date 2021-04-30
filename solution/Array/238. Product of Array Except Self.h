#include "../global.h"
class Solution {
public:
    /*
        left[i]: i左侧元素的乘积
        right[i]: i右侧元素的乘积
        nums[i] = left[i] * right[i];
        空间复杂度 O(n)
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> left(size, 0), right(size, 0);

        left[0] = 1;
        for(int i = 1; i < size; i++)
            left[i] = left[i-1] * nums[i-1];

        right[size-1] = 1;
        for(int i = size - 2; i >= 0; i--)
            right[i] = right[i+1] * nums[i+1];

        for(int i = 0; i < size; i++)
            nums[i] = left[i] * right[i];

        return nums;
    }
    */
    /*
        输出数组不被视为额外空间
        使用输入数组作为left,由输入的nums计算right
    */
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int size = nums.size();
        // 输出数组：
        vector<int> ans(size, 0);

        ans[0] = 1;
        for(int i = 1; i < size; i++)
            ans[i] = ans[i-1] * nums[i-1];

        int right = 1; // 右侧所有元素的乘积
        for(int i = size - 1; i >= 0; i--)
        {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};
