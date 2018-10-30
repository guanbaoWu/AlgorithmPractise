#include <iostream>
#include <string>

using namespace std;

/**
* 判断一串字符串是否可以表示为数值,形如：+100、+123.12e-12、3.14、.123e2
* 而:12e、1.2.3则不属于数值字符串
* 可以表示数值的字符串可以概括为:A[.B[(e|E)C]] | .B[(e|E)C]
**/
class Solution
{
public:

    /**
    * 判断是否是无符号的整数
    **/
    bool bIsUnsignedInter(const char **str)
    {
        bool isnum = false;
        
        if (NULL == str)
        {
            return false;
        }
        
        while(*(*str) != '\0' && *(*str) >= '0' && *(*str) <= '9')
        {
            isnum = true;
            ++(*str);
        }
        
        return isnum;
    }
    
    /**
    * 判断是否是有符号的整数
    **/
    bool bIsInter(const char **str)
    {
        if (NULL == str)
        {
            return false;
        }
        
        if (*(*str) == '+' || *(*str) == '-')
        {
            ++(*str);
        }
        
        return bIsUnsignedInter(str);
    }
    
    bool bIsnumeric(const char *str)
    {
        if (NULL == str)
        {
            return false;
        }
        
        /**
        * 判断开头的数字是否是有符号整数
        **/
        bool bnumeric = bIsInter(&str);
        
        if (*str == '.')
        {
            ++str;
            
            /**
            * 小数点后部分,只能为不带符号的整数,整数部分可以为空
            **/
            bnumeric = bIsUnsignedInter(&str) || bnumeric;
        }
        
        if (*str == 'e' || *str == 'E')
        {
            ++str;
            
            /**
            * 指数的前部分必须存在数值
            **/
            bnumeric = bnumeric && bIsInter(&str);
        }
        
        /**
        * 字符串结束并且字符串部分符合才算是数值字符串
        **/
        return bnumeric && *str == '\0';
        
    }
};

int main()
{
    string s;
    
    cout << "please input test string: " << endl;
    cin >> s;
    
    cout << "test string: " << s << endl;

    Solution a;
    
    cout << "test string: " << s << " " << "result: " << (a.bIsnumeric(s.c_str()) ? "yes" : "no") << endl;
    
    return 0;
}
