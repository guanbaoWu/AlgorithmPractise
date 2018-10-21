#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/**
* 打印从1到最大的n位数
**/

class Solution
{
public:

	/**
	* @brief:打印从1到最大的n位数,如n=3时,将1至999打印出来
	* @n:位数
	* 考察点:1、大数问题(转换为字符串) 2、字符串数字的答应问题
	**/
	int printMaxNumberofN(int n)
	{
		if (n <= 0)
		{
			return -1;
		}
	
		/**
		* 创建n+1位的数组表示n位最大的数字,剩下的一位用于保存'\0'
		**/
		char *number = new char[n+1];
		memset(number, '0', n);
		number[n] = '\0';
		
		/**
		* 实现字符串表示的整数相加
		**/
		while(!Increment(number))
		{
			PrintNumber(number);
		}
		
		delete [] number;
		
		return 0;
	}
	
	bool Increment(char *number)
	{
		if (NULL == number)
		{
			logic_error ex("invalid args");
			throw new exception(ex); 
		}
		
		/**
		* 当第一位发生进位时表明此时的数字已经为最大
		**/
		bool isover = false;
		int nTakeOver = 0;
		int nLength = strlen(number);
		
		/**
		* 从最左边开始
		**/
		for(int i = nLength-1; i >= 0; --i)
		{
			int sum = number[i] - '0' + nTakeOver;
			if (i == nLength-1)
				sum++;
			
			/**
			* 发生了进位
			**/
			if (sum >= 10)
			{
				/**
				* 表示N位数字的第一位发生了进位,表示已经到达最大的数字
				*/
				if (i == 0)
				{
					isover = true;
					break;
				}
				else
				{
					/**
					* 发生进位的位归零,并进位到下一位
					**/
					nTakeOver = 1;
					sum -= 10;
					number[i] = '0' + sum;				
				}
			}
			else
			{
				number[i] = '0' + sum;
				break;
			}
		}
		
		return isover;
	}
	
	void PrintNumber(char* number)
	{
		if (NULL == number)
		{
			return;
		}
		
		/**
		* 最右边的0不打印
		**/
		bool bExit0 = true;
		int nLength = strlen(number);
		
		for (int i = 0; i < nLength; ++i)
		{
			/**
			* 只要存在一个大于0的数字,则该数字后面的数字都需要打印出来
			**/
			if (bExit0 && number[i] != '0')
				bExit0 = false;
				
			if (!bExit0)
			{
				printf("%c", number[i]);
			}
			
		}
		
		printf("\n");
	}
	
};


int main()
{
	Solution s;
	
	int n = 0;
			
	cout << "input a number: " << endl;
	cin >> n;

	s.printMaxNumberofN(n);
	
	return 0;
}
