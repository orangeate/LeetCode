#include "../global.h"
class Solution {
public:
    /*
    int solution(vector<int>& citations)
    {
        int size = citations.size();
        int i;
        for(int i = 0; i < size; i++)
        {
            if(citations[size-1-i] >= i+1)
                continue;
            else
                return i;
        }
        return i;
    }
    */
    int solution(vector<int>& citations)
    {
        int pivot = 0, size = citations.size();
        int left = 0, right = size -1;

        // 需要比较 size-pivot 和 citations[pivot] 的大小
        while(right >= left)
        {
            pivot = left + (right-left)/2;
            if(size - pivot == citations[pivot])
                return size - pivot;
            else if(size - pivot > citations[pivot])
                left = pivot + 1;
            else
                right = pivot - 1;
        }
        return size - left;
    }

    int hIndex(vector<int>& citations)
    {
        return solution(citations);
    }
};
