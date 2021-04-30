#include "../global.h"
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() <= 1)
            return 0;
        int min = prices[0];
        int ans = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min)
                min = prices[i];

            if (prices[i] - min > ans)
                ans = prices[i] - min;
        }

        return ans;
    }
};

