#include "../global.h"
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end(), greater());
        int i;
        for(i = 0; i < citations.size(); i++)
        {
            if(citations[i] >= i+1)
                continue;
            else
                return i;
        }
        return i;
    }
};
