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
        unsigned int i = 0;
		unsigned int j = 0;
        unsigned int size = length;
        while(size > 0)
        {
            --size;
            
            /**
            * 偶数,移动该数字后的数字
            **/
            if ((pArry[i]%2) == 0)
            {
                even = pArry[i];
                
                for(j = i; j < length - 1; ++j)
                {
                    pArry[j] = pArry[j+1]; 
                }
                
                pArry[j] = even;
                
                continue;
            }
            
            ++i;
        }
        
    }
    
    /**
    * O(n)的解法
    **/
    bool bIsEven(int num)
    {
        if (num & 1)
        {
            return true;
        }
        
        return false;
    }
    void ReOrderOddEven(int *pArry, unsigned int length, bool boptimal)
    {
        if (NULL == pArry)
        {
            return;
        }
        
        /**
        * O(n)的解法,增加两个指针,一个指向头,一个指向尾巴,当不满足要求时,既进行交换
        **/
        int *start = &pArry[0];
        int *end = &pArry[length - 1];
        
        while(start < end)
        {
            while(end > start && !bIsEven(*end)) --end;
            while(start < end && bIsEven(*start)) ++start;
            
            if (start < end)
            {
                int temp = *start;
                *start = *end;
                *end = temp;
            }
        }
    }
};

int main()
{
    int a[7] = {1,3,2,5,8,11,12};
    int b[7] = {1,32,11,24,8,11,12};
    
    Solution s;
    
    s.ReOrderOddEven(a, sizeof(a)/sizeof(a[0]));
    s.ReOrderOddEven(b, sizeof(b)/sizeof(b[0]), true);
    
    for(unsigned int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
    {
        printf("[%d]:%d\n", i, a[i]);
    }
    
    for(unsigned int i = 0; i < sizeof(b)/sizeof(b[0]); ++i)
    {
        printf("[%d]:%d\n", i, b[i]);
    }
    
    return 0;
}

