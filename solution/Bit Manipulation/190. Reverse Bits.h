#include "../global.h"
class Solution {
public:

    /* ---- 逐位颠倒 ----
        检索整数 n 中最右边的位 : n%2, n&1
        组合运算 2^a + 2^b, 2^a | 2^b      2^a = 2 << a
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0, power = 31;

        while(n != 0)
        {
            ans |= (n&1) << power;

            n = n >> 1;
            power--;
        }
        return ans;
    }
    */

    /* ---- 带记忆化的按字节颠倒 ----
        8位反转: (byte * 0x0202020202 & 0x010884422010) % 1023

    uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t> cache)
    {
        if(cache.find(byte) != cache.end())
            return cache[byte];

        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        cache.insert({byte, value});
        return value;
    }

    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0, power = 24;
        map<uint32_t, uint32_t> cache;

        while(n != 0)
        {
            // n & 0xff 右面8位数
            ans += reverseByte(n & 0xff, cache) << power;
            n = n >> 8;
            power -= 8;
        }
        return ans;
    }
    */

    /* ---- 分治 ----
    uint32_t reverseBits(uint32_t n)
    {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
    */

    /* ---- 逐位颠倒简洁代码 ----*/
    uint32_t reverseBits(uint32_t n)
    {
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            ans = ans << 1;
            ans |= n&1;
            n = n >> 1;
        }
        return ans;
    }
};