/**
* 输入一个整数,判断其二进制中的1的个数
**/

class Solution
{
public:
	int Count(int i)
	{
		int num = 0;
		
		while(i != 0)
		{
			++num;
			
			/**
			* i & (i-1)时最右边的1变成0,其余位为1
			**/
			i = i & (i-1);
		}
		
		return num;
	}
};