#include <stdio.h>

#define true  1
#define false 0

int DuplicateArry(int a[], int len)
{
    int i = 0;
    int j = 0;
    
    if (NULL == a || len <= 0)
    {
        return false;
    }
    
    for(i=0; i < len && a[i] < len && a[i] >= 0; i++)
    {
        /**
        * 将数组元素放置在下标一致的位置上
        **/
        while(a[i] != i)
        {
            /**
            * 判断将要放置的位置是否已经存在元素
            **/
            j = a[i];
            if (a[j] == j)
            {
                return true;
            }
            
            /**
            * 没有则交换两个数字
            **/
            a[i] ^= a[j];
            a[j] ^= a[i];
            a[i] ^= a[j];
        }

    }
    
    return false;
}

int main()
{
	int a[] = {1,2,3,5,5,0};
	
	if (DuplicateArry(a, sizeof(a)/sizeof(a[0])))
	{
		printf("exit Duplicate Arry item");
	}
	
	return 0;
}

