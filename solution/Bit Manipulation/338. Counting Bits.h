#include "../global.h"
class Solution {
public:
    /* ---- 直接计算每个数 ----
    int countOnes(int x)
    {
        int ans = 0;
        while(x > 0)
        {
            x = x & (x-1);
            ans++;
        }
        return ans;
    }
    vector<int> countBits(int num)
    {
        vector<int> ans(num+1);
        for(int i = 0; i <= num; i++)
        {
            ans[i] = countOnes(i);
        }
        return ans;
    }
    */

    /* ---- dp 最高有效位 ----
        公式: bits[x] = bits[x-highBit]+1
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1, 0);
        int highBit = 0;
        for(int i = 1; i <= num; i++)
        {
            if((i & (i-1)) == 0)
                highBit = i;
            ans[i] = ans[i - highBit] + 1;
        }
        return ans;
    }
    */

    /* ---- dp 最低有效位 ----
        公式:
            if x%2 == 0 :
                bits[x] = bits[x/2]
            if x%2 == 1 :
                bits[x] = bits[x/2]+1
            ---> bits[x] = bits[x/2] + x%2
            ---> bits[x] = bits[x>>1] + (x&1)
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1, 0);
        int highBit = 0;
        for(int i = 1; i <= num; i++)
        {
            ans[i] = ans[i>>1] + (i&1);
        }
        return ans;
    }
    */

    /* ---- dp 最低设置位 ----
        定义正整数x的「最低设置位」为i的二进制表示中的最低的1所在位
        令 y = x&(x-1)，则y为将x的最低设置位从1变成0之后的数
        公式：
            bits[x] = bits[x&(x−1)] + 1
    */
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1, 0);
        int highBit = 0;
        for(int i = 1; i <= num; i++)
        {
            ans[i] = ans[i&(i-1)] + 1;
        }
        return ans;
    }
};