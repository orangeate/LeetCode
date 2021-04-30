#include "../global.h"
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> ans;

        for(int i = 1; i <= rowIndex+1; i++)
        {
            vector<int> row(i);
            row[0] = 1;
            row[i-1] = 1;

            for(int j = 1; j < i-1; j++)
            {
                row[j] = ans[i-2][j-1] + ans[i-2][j];
            }
            ans.push_back(row);
        }

        return ans[rowIndex];
    }
};