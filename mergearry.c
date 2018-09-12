#include <stdio.h>

void MergeArry(int a[], int srclen, int srcsize, int b[], int dstlen)
{
	int i = srclen + dstlen - 1;
	int j = dstlen - 1;
	int k = srclen - 1;
	
    if (NULL == a || NULL == b)
    {
        return;
    }
	
	if (i > srcsize)
	{
		return;
	}
	
	while(j >=0)
	{
		/**
		* k小于0的情况表示长的数组已经遍历完，可以将短数组全部插入
		**/
		if (k < 0 || b[j] >= a[k])
		{
			a[i] = b[j];
			--j;
		}
		else
		{
			a[i] = a[k];
			--k;
		}
		
		--i;
		
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
	int a[16] = {2,3,5,7,11,32,66,77,-1,-1,-1,-1,-1,-1,-1,-1};
	int b[5] = {0,0,1,1,1};
	
	MergeArry(a, 8, 16, b, 5);
	
	print(a,16);
	
	return 0;
}
