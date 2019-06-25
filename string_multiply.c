#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxLength = 110;

void Print_num(char* num, int size)
{
    int i = 0;
    
    if (NULL == num || 0 >= size)
        return;
        
    for (i = size - 1; i > 0; --i)
    {
        printf("%d", num[i]);
    }
    
    printf("%d\n", num[0]);
}

char * multiply(char * num1, char * num2)
{
    int num1_size = 0;
    int num2_size = 0;
    int i =0, j = 0, p = 0, h = 0;
    
    char *result = NULL;
    
    if (NULL == num1 || NULL == num2)
    {
        return NULL;
    }
    
    num1_size = strlen(num1);
    num2_size = strlen(num2);
    if (num1_size <= 0 || num2_size <= 0)
    {
        return NULL;
    }
    
    /**
    * 分配一个存储结果的数组
    **/
    result = (char*)malloc(maxLength * 2 + 1);
    memset(result, 0, maxLength * 2 + 1);
    
    /**
    * 两个字符串开始相乘
    **/
    for(i = num1_size - 1; i >= 0; --i)
    {
        for (j = num2_size - 1; j >= 0; --j)
        {
            result[p] = result[p] + (num1[i] - '0') * (num2[j] - '0') + h;
            
            /**
            * 获取是否有进位
            **/
            h = result[p] / 10;
            result[p] = result[p] % 10;
            
            ++p;
        }
        
        /**
        * 还有进位
        **/
        while(h > 0)
        {
            result[p] = h % 10;
            h = h / 10;
            ++p;
        }
        
        p = p - 1;
    }
    
    Print_num(result, p+1);
    
    return result;
    
}

int main()
{
    char num1[maxLength];
    char num2[maxLength];
    
    while(fgets(num1, maxLength, stdin) != NULL && fgets(num2, maxLength, stdin) != NULL)
    {
        num1[strlen(num1)-1] = '\0';
        num2[strlen(num2)-1] = '\0';
        multiply(num1, num2);
    }

	return 0;
}
