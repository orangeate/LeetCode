#include "../global.h"
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();
        int i = 0;

        while (i < n)
        {
            int sumOfGas  = 0;
            int SumOfCost = 0;
            int count = 0;

            while(count < n)
            {
                int j = (i + count) % n;
                sumOfGas += gas[j];
                SumOfCost += cost[j];
                if(SumOfCost > sumOfGas)
                {
                    break;
                }
                count++;
            }
            if(count == n)
                return i;
            else
                i = i + count +1;
        }
        return -1;
    }
};
