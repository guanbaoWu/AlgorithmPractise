#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

/**
* 输入一串括号字符串,括号包括()\[]\{},判断该字符串的括号是否能够正确匹配
**/
class Solution
{
public:
    bool BracketsIsMatch(char c1, char c2)
    {
        if (c1 == '(' && c2 == ')')
            return true;
        if (c1 == '[' && c2 == ']')
            return true;
        if (c1 == '{' && c2 == '}')
            return true;
        return false;
    }
    
    bool BracketsMatch(string &s)
    {
        vector<char> vecLeft  = {'(','[','{'};
        
        /**
        * 创建一个栈进行保存
        **/
        stack<char> m_stack;
       
        for (unsigned int i = 0; i < s.length(); ++i)
        {
            if (vecLeft.end() != find(vecLeft.begin(), vecLeft.end(), s[i]))
            {
                m_stack.push(s[i]);
            }
            else
            {
                if (m_stack.empty() || !BracketsIsMatch(m_stack.top(), s[i]))
                    return false;
                    
                m_stack.pop();
            }
        }
       
        return m_stack.empty();

    }
};


int main()
{
    string a = {'(', '(', ')', ')', '[', ']', '{', '}'};
    
    Solution s;
    
    const char *result = s.BracketsMatch(a) ? "YES" : "NO";
    
    cout << "the result is:" << result << endl;
    
    return 0;
}


