#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

/**
* @�����������Ԫ�ط�ΧΪ[0,99]
* @ arry�������������
* @ length�����鳤��
**/
void SortLittleElement(int arry[], int length)
{
	assert(arry != NULL || length <= 0);
	
	/**
	* ����һ�����������,������ķ�Χȡ���ڴ���������Ĵ�С,һ��ʹ��С��Ԫ��
	**/
	const int range = 99;
	int timesofArry[range+1] = {0};
	
	memset(timesofArry, 0, sizeof(timesofArry)/sizeof(timesofArry[0]));
	
	/**
	* ͳ�ƴ��������������Ԫ�س��ִ���
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
	* ��������Ԫ�س��ִ����������������
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
