#include <iostream>

using namespace std;

class Solution
{
public:
	
	/**
	* @ 查找旋转数组的最小元素
	* @ arry：旋转数组
	* @ length：数组长度
	**/
	int MinElement(int arry[], int length)
	{
		int start = 0, end = length-1, min = 0;
		
		if (NULL == arry || 0 <= length)
		{
			throw new exception("invalid args");
		}
		
		/**
		* 特殊情况:数组旋转0,此时应当直接返回首元素
		**/
		min = start;
		
		while(arry[start] >= arry[end])
		{			
			if (end - start == 1)
			{
				min = end;
				break;
			}
			
			
			min = (end + start) >> 2;
			
			/**
			* 三个元素相同,此时无法确认中间元素归属于那个递增子数组,只能遍历查找
			**/
			if (arry[start] == arry[min] && arry[end] == arry[min])
			{
				return MinTraverse(arry, start, end);
			}
			/**
			* 中间元素还在第一个递增子数组中,移动start
			**/
			else if (arry[min] >= arry[start])
			{
				start = min;
			}
			/**
			* 中间元素还在第二个递增子数组中,移动end
			**/
			else if(arry[min] >= arry[end])
			{
				end = min;
			}
		}
		
		return arry[min];
	}
	
	int MinTraverse(int arry[], int start, int end)
	{
		int min = 0;
		
		if (NULL == arry)
		{
			throw new exception("invalid args");
		}
		
		
		min = arry[start];
		for(int i=start+1; i<=end; ++i)
		{
			if (arry[i] < min)
			{
				min = arry[i];
			}
		}
		
		return min;

	}
};