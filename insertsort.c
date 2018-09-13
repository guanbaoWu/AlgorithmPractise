#include <stdio.h>

void InsertSort(int a[], int size)
{
    int i = 1;
    int j = 0;
    int k = 0;
    int temp = 0;
    
    if (a == NULL || size <= 0)
    {
        return;
    }
    
    for(i=1; i < size; ++i)
    {
        for(j=0; j < i; j++)
        {
            /**
            * 查找比a[i]大的元素位置进行插入
            **/
            if (a[j] >= a[i])
            {
                break;
            }
        }
        
        /**
        * 0~i-1存在比第i个元素大的元素
        * 在插入元素之前需要进行移动
        **/
        if (j < i)
        {
            temp = a[i];
            for(k=i; k > j; --k)
            {
                a[k] = a[k-1];
            }
            
            a[j] = temp;
        }
    }
    
}

void print(int a[], int size)
{
	int i = 0;
	
	for(i=0; i<size; ++i)
	{
		printf("a[%d]=%d\n", i, a[i]);
	}
}

int main()
{
	int a[8] = {2,1,5,7,6,9,77,66};
	
	InsertSort(a, 8);
	
	print(a,8);
	
	return 0;
}