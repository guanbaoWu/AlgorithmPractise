#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int size = str.size();
        int sign = 1;
        int re = 0;
        long long oldvalue = 0;
        
        if (size == 0 || ((str[0] < '0' || str[0] > '9') && (str[0] != '-' && str[0] != '+' && str[0] != ' ')))
            return 0;
        
        while(str[i] == ' ' && i < size)
        {
            ++i;
            continue;
        }
        
        if (i == size)
            return 0;
        
        /**
        * 负数
        **/
        if (str[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else if(str[i] == '+')
        {
            sign = 1;
            ++i;
        }
        
        
        /**
        * 开始遍历字符
        **/
        for (; i < size; ++i)
        {       
            int value = 0;
            
            if (str[i] >= '0' && str[i] <= '9')
            {
                value = str[i] - '0';
                oldvalue = oldvalue * 10 + value;
                re = oldvalue;
            }
            else
            {
                break;
            }
            
            /**
            * 检测是否溢出
            **/
            if (oldvalue != (long long)re)
            {
                return sign < 0 ? INT_MIN : INT_MAX;
            }
        }
        
        return sign * re;
        
        
    }
};

int main()
{
    string a;
    Solution s;
    
	while(cin >> a)
	{
    	cout << s.myAtoi(a) << endl;;
	}
       
    return 0;
}
