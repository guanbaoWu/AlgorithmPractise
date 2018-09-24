#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

/**
* @待排序数组的元素范围为[0,99]
* @ arry：待排序的数组
* @ length：数组长度
**/
void SortLittleElement(int arry[], int length)
{
	assert(arry != NULL || length <= 0);
	
	/**
	* 构建一个额外的数组,其数组的范围取决于待排序数组的大小,一般使用小的元素
	**/
	const int range = 99;
	int timesofArry[range+1] = {0};
	
	memset(timesofArry, 0, sizeof(timesofArry)/sizeof(timesofArry[0]));
	
	/**
	* 统计待排序数组的数组元素出现次序
	**/
	int a = 0;
	for (int i=0; i < length; ++i)
	{
		a = arry[i];
		if (a > range || a < 0)
		{
			return;
		}
		++timesofArry[a];
	}
	
	/**
	* 按照数组元素出现次数的数组进行排序
	**/
	int index = 0;
	for (int i=0; i <= range; ++i)
	{
		for (int j=0; j<timesofArry[i] && index < length; ++j)
		{
			arry[index] = i;
			++index;
		}
	}
}

int main()
{
	int a[] = {0,2,3,1,5,4,11,2,99,77,0,4};
	
	SortLittleElement(a, sizeof(a)/sizeof(a[0]));
	
	for (unsigned int i=0; i < sizeof(a)/sizeof(a[0]); ++i)

	{
		cout << "index[" << i << "]" << "=" << a[i] << endl;
	}
	
	return 0;
}
