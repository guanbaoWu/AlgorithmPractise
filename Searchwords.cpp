/**
* 假设二维矩阵：M*N
* 字典存在的单词数：K
* 最长单词的字母数: L
* 时间复杂度：O(K * (M * N) * L^8)
* 空间复杂度: 二维矩阵的空间O(M*N)
**/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	/**
	* @Brief:查找字母矩阵中存在于字典的单词
	**/
	vector<string> SearchWords(vector<vector<char>>& matrix, vector<string>& words)
	{
		if (matrix.size() <= 0 || words.size() <= 0)
		{
			return m_vecResult;
		}
		
		for(vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
		{
			if (exit(matrix, *it))
			{
				m_vecResult.push_back(*it);
			}
		}
		
		return m_vecResult;
	}
	
	/**
	* @Brief:判断单词是否存在于矩阵中
	* @matrix：二维字母矩阵
	* @word：需要匹配的单词
	**/
	bool exit(vector<vector<char>>& matrix, string word)
	{
		if (matrix.size() <= 0 || word.size() <= 0)
		{
			return false;
		}
		
		int m = matrix.size();
		int n = matrix[0].size();
		
		vector<vector<int>> visited(m, vector<int>(n,0));
		
		for(int i= 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				/**
				* 首字母匹配,继续匹配后续字母
				**/
				if (matrix[i][j] == word[0])
				{
					visited[i][j] += 1;
					
					/**
					* 匹配完成,返回
					**/
					if (word.size() == 1 || search(i, j, matrix, word.substr(1), visited))
					{
						return true;
					}
					
					visited[i][j] -= 1;
				}
			}
		}
			
		return false;
		
	}
	
	/**
	* @Brief:递归判断单词的字母是否能够匹配矩阵中的字母
	* @i j: 矩阵初始的下标
	* @matrix：二维字母矩阵
	* @word：需要匹配的单词
	* @visited：遍历路径记录
	**/
	bool search(int i, int j, vector<vector<char>>& matrix, string word, vector<vector<int>>& visited)
	{
		if (word.size() <= 0)
		{
			return true;
		}
		
		/**
		* 建立可移动的8个方向
		**/
		int m = matrix.size();
		int n = matrix[0].size();
		int direct[][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
		
		/**
		* 分别移动8个方向查找匹配
		**/
		for(unsigned int k = 0; k < sizeof(direct)/sizeof(direct[0]); ++k)
		{
			int row = i + direct[k][0];
			int col = j + direct[k][1];
			
			if ((row >= 0 && row < m) && (col >= 0 && col < n)
				&& (m_Maxvisited > visited[row][col]) && (matrix[row][col] == word[0]))
			{
				visited[row][col] += 1;
				
				if (word.size() == 1 || search(row, col, matrix, word.substr(1), visited))
				{
					return true;
				}
				
				visited[row][col] -= 1;
			}
		}
		
		return false;
	}
	
private:
	static int m_Maxvisited;
	vector<string> m_vecResult;
};

/**
* 最多只能递归查找二维矩阵某一位置的次数
**/
int Solution::m_Maxvisited = 2;

int main()
{
	vector<vector<char>> matrix = {{'H','T','Q','Z','A'},
								   {'F','E','O','H','P'},
								   {'O','M','L','M','B'},
								   {'C','S','O','L','Q'},
								   {'H','X','D','K','O'}};
								   
    vector<string> dict = {"HELLO", "MOMOSO", "TOET", "TOETOET", "BOY"};
	
	Solution s;
	
	vector<string> result = s.SearchWords(matrix, dict);
	
	for(vector<string>::const_iterator it = result.begin(); it != result.end(); ++it)
	{
		cout << "\"" << *it << "\"" << endl;
	}
	
	return 0;
}


