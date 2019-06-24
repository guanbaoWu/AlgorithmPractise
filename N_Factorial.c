#include <stdio.h>

const int max = 4000;

void Print_Factorial(int a[], int p)
{
    int i = 0;
    
    /**
    * 需要逆序输出
    **/
    for(i = p; i > 1; --i)
        printf("%d", a[i]);
    
    printf("%d\n", a[1]);
}

/**
* @brief:计算N的阶乘(大数问题)
* input :n(求n的阶乘)
* output: -1 --失败 0 --成功
**/
int N_Factorial(int n)
{
    /**
    * 定义一个保存结果的数组,每一个元素保存数值中的一位
    **/
    int a[max];
    
    /**
    * p表示数值的个数,h进位值
    **/
    int p = 1, h = 0;
    int i = 0, j = 0;
    
    /**
    * 初始值为1
    **/
    a[1] = 1;
    
    if (n < 0)
        return -1;
    
    if (n == 0)
        Print_Factorial(a, 1);
    
    for (i = 2; i <= n; ++i)
    {
        for (j = 1; j <= p; ++j)
        {
            /**
            * 计算一个位的乘积,并加上上一位的进位,才是正确的
            **/
            a[j] =  a[j] * i + h;
            
            /**
            * 检查是否需要进位
            **/
            h = a[j] / 10;
			a[j] = a[j] % 10;
        }
        
        /**
        * 存在进位,需要进位
        **/
        while(h > 0)
        {
            a[j] = h % 10;
            h = h / 10;
            ++j;
        }
        
        /**
        * 设置目前的位数
        **/
        p = j - 1;
    }
    
    /**
    * 打印结果
    **/
    Print_Factorial(a, p);
    
    return 0;
}

int main()
{
    int n = 0;
    
    while(scanf("%d", &n) != EOF && n > 0)
    {
        N_Factorial(n);
    }
    
    return 0;
}
