#include "../global.h"
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int temp = 0; // 能达到的位置
        for(int i = 0; i < nums.size(); i++)
        {
            if(i <= temp)
                temp = max(temp, i + nums[i]);
            else
                return false;
        }
        return true;
    }
};
