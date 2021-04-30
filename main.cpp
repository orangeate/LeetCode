#include "solution/Array/11. Container With Most Water.h"
int main()
{
    Solution *s = new Solution();
    vector<int> temp = {1,2,6,10,11,3,4};
    int ans = s->maxArea(temp);
    cout << ans;

    delete(s);
    return 0;
}
