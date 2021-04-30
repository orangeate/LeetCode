#include "../global.h"
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size() - needle.size();
        for(int i = 0; i <= n; i++)
        {
            int j = 0;
            while(j < needle.size())
            {
                if(haystack[i+j] != needle[j])
                    break;
                j++;
            }
            if(j == needle.size())
                return i;
        }
        return -1;
    }
};