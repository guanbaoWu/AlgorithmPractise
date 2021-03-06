#include <iostream>
#include <stdexcept>

using namespace std;

/**
*@ 题目：存在一个m*n的矩阵,其某个机器人从坐标(0,0)的位置开始出发,要求机器人经过的坐标的数字之和
		 不大于某个数(18),如坐标(35,37),其数字之和3+5+3+7<=18则满足要求,(35,38)则不满足
**/
class Solution
{
public:
	/**
	* @ 返回满足小于要求的左边之和的格子数
	* @ matrix：路径矩阵
	* @ sum：要求坐标之和
	**/
	int movingCount(int row,int col, int sum)
	{
		if (row <= 0 || col <= 0)
		{
			return 0;
		}
		
		/**
		* 创建一个用于标志走过路径的二维数组
		**/
		bool *visited = new bool[row*col];
		for (int i = 0; i < row*col; ++i)
		{
			visited[i] = false;
		}
		
		/**
		* 从坐标(0,0)开始搜索
		**/
		int count = Search(row, col, 0, 0, sum, visited);
		
		delete [] visited;
		
		return count;

	}
	
	int Search(int rows, int cols, int rowIndex, int colIndex, int sum, bool *visited)
	{
		if (rows <= 0 || cols <= 0 || NULL == visited)
		{
			return 0;
		}
		
		/**
		* 确定上下左右四个方向
		**/
		int direct[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
		
		/**
		* 未访问过,且满足条件,移动
		**/
		int count = 0;
		if (IsRight(rows, cols, rowIndex, colIndex, sum) && !visited[rowIndex*cols+colIndex])
		{
			visited[rowIndex*cols+colIndex] = true;
			
			count += 1;
			for (int i = 0; i < 4; ++i)
			{
				count += Search(rows, cols, 
							rowIndex + direct[i][0], colIndex + direct[i][1], sum, visited);
			}
		}
		
		return count;
	}

	bool IsRight(int rows, int cols, int rowIndex, int colIndex, int sum)
	{
		
		if (rowIndex >= 0 && rowIndex < rows && colIndex >= 0 && colIndex < cols
			&& getSum(rowIndex) + getSum(colIndex) <= sum)
		{
			return true;
		}
		
		return false;
	}
	
	int getSum(int number)
	{
		int sum = 0;
		while(number > 0)
		{
			sum += number%10;
			number /= 10;
		}
		
		return sum;
	}
};

int main()
{
	int matrix[][4] = {{0,1,2,3},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int k = 0;
	
	Solution s;
	
	cout << "input number:" << endl;
	cin >> k;
	
	cout << "k=" << " " << k << " " << "path count:" << " " << s.movingCount(4,4,k);
	
	return 0;
	
}
