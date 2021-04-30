#include "../global.h"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int sum = m + n - 1;
        int i, j;
        for(i = m-1, j = n-1; i>=0 && j >= 0; sum--)
        {
            if(nums1[i] > nums2[j])
                nums1[sum] = nums1[i--];
            else
                nums1[sum] = nums2[j--];
        }

        while(i >= 0)
            nums1[sum--] = nums1[i--];
        while(j >= 0)
            nums1[sum--] = nums2[j--];

    }
};
