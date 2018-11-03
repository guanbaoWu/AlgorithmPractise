#include <iostream>
#include <string>

using namespace std;

/**
* 给定一个整形数组,要求奇数在前,偶数在后
* 如：1 3 2 5 8 10 12 ==> 1 3 5 2 8 10 12
**/

class Solution
{
public:
    void ReOrderOddEven(int *pArry, unsigned int length)
    {
        if (NULL == pArry)
        {
            return;
        }
        
        /**
        * O(n^2)的解法,遍历数组,偶数元素取出,移动后面的数字,将该元素放置在空位
        **/
        int even = 0;
        int i = 0;
        int size = length;
        while(size > 0)
        {
            --size;
            
            /**
            * 偶数,移动该数字后的数字
            **/
            if ((pArry[i]%2) == 0)
            {
                even = pArry[i];
                
                for(int j = i; j < length - 1; ++j)
                {
                    pArry[j] = pArry[j+1]; 
                }
                
                pArry[j] = even;
                
                continue;
            }
            
            ++i;
        }
        
    }
};

int main()
{
    int a[7] = {1,3,2,5,8,11,12};
    
    Solution s;
    
    s.ReOrderOddEven(a, sizeof(a)/sizeof(a[0]));
    
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
    {
        printf("[%d]:%d\n", i, a[i]);
    }
    
    return 0;
}

