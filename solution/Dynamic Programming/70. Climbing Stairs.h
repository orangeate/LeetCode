#include "../global.h"
class Solution {
public:
    int climbStairs(int n)
    {
        // p = f(x-1)   f(0) = 1
        // q = f(x-2)   f(1) = 1
        int p = 1, q = 1;
        int now = q;
        for(int i = 2; i <=n ; i++)
        {
            now = p + q;
            p = q;
            q = now;
        }

        return now;
    }

};