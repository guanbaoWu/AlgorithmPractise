#include <stdio.h>

/**
* 采用递归的方式
*   iR --数组下标右边界 
*   iL --数组下标左边界 
*   a[] --待排序整形数组
**/
int QuickSort(int iR, int iL, int *a)
{
    int i = iR, j = iL;
    
    /**
    * 选定一个初始的值
    **/
    int iTemp = a[iR];


    /**
    * 只有一个元素时不需要排序,递归结束
    **/
    if (iR >= iL)
    {
        return 0;
    }
    
    while(i < j)
    {
        /**
        * 先移动左边界,找出左边比初始值小的元素
        **/
        while(j > i)
        {
            if (a[j] < iTemp)
            {
                break;
            }
            --j;
        }
        
        /**
        * 移动右边界找出比初始值大的元素
        **/
        while(i < j)
        {
            if (a[i] > iTemp)
            {
				
        		a[i]^=a[j];
        		a[j]^=a[i];
        		a[i]^=a[j];
                break;
            }
            ++i;
        }
        
    }
    
    /**
    * 把初始值移动到中间
    **/
    a[iR]^=a[i];
    a[i]^=a[iR];
    a[iR]^=a[i];
    
    QuickSort(iR, i-1, a);
    QuickSort(i+1, iL, a);
    
    return 0;
}

int main()
{
	int i = 0;
	int a[10] = {8,1,3,5,2,0,9,1,12,7};
	
	QuickSort(0, 9, a);
	
	for(i=0; i < 10; ++i)
	{
		printf("a[%d]=%d\n", i, a[i]);
	}
	
	return 0;

}
