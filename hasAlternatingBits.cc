#include <iostream>

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int i = 0;
        
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        
        i = (n ^ (n<<1));
        
        return (i & (long)(i + 1) == 0) ? true : false;
        
    }
};

int main()
{
    Solution s;
    s.hasAlternatingBits(5);
    
    return 0;
}