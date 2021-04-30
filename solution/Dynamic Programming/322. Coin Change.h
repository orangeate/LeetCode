#include "../global.h"
class Solution {
public:
    // 动态规划

    /* ---- 自上而下 ----
    //  状态转移方程 F(x) = F(x−C)+1
    int f(vector<int>& coins, int x, vector<int>& count)
    {
        if(x < 0) return -1;
        if(x == 0) return 0;
        if (count[x-1] != 0) return count[x-1];

        int min = INT_MAX;
        for(int i = 0; i < coins.size(); i++)
        {
            int val = f(coins, x - coins[i], count) + 1;
            if(val > 0 && val < min)
                min = val;
        }

        count[x-1] = min == INT_MAX ? -1 : min;
        return count[x-1];
    }

    int coinChange(vector<int>& coins, int amount)
    {
        if (amount < 1) return 0;
        vector<int> count;
        count.resize(amount);
        return f(coins, amount, count);
    }
    */

    /* ---- 自下而上 ----*/
    // 状态转移方程 F(x) = min(F(x-coins[0]), F(x-coins[1], ... , F(x-coins[size-1])) + 1
    int coinChange(vector<int>& coins, int amount)
    {
        int max = amount + 1;
        vector<int> dp(amount + 1, max);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(coins[j] <= i)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};