#include "../global.h"
/*
    方法一：空间局部优化
    方法二：空间最优，操作局部优化（双指针）
    方法三：最优解
 */
class Solution {
public:
    /* ---- 冒泡 ----
        void moveZeroes(vector<int>& nums)
      {
          for(int i = nums.size()-1; i >=0 ; i--)
          {
              for(int j = 1; j < nums.size(); j++)
              {
                  if(nums[j-1] == 0)
                  {
                      nums[j-1] = nums[j];
                      nums[j] = 0;
                  }
              }
          }
      }
      */
    void moveZeroes(vector<int>& nums)
    {
        int i = 0, j = 0;

        while(i < nums.size())
            if(nums[i] != 0)
                nums[j++] = nums[i++];
            else
                i++;

        while(j < nums.size())
            nums[j++] = 0;

    }
};
