#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxLength = 110;

char * multiply(char * num1, char * num2)
{
    int num1_size = 0;
    int num2_size = 0;
    int i =0, j = 0;
    
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
    
    if ((num1_size == 1 && num1[0] == '0') || (num2_size == 1 && num2[0] == '0'))
        return "0";
        
    /**
    * 分配一个存储结果的数组,初始化为'0'
    **/
    result = (char*)malloc(num1_size + num2_size + 1);
    memset(result, '0', num1_size + num2_size);
    result[num1_size + num2_size] = '\0';
    
    /**
    * 两个字符串开始相乘,从低位(数组结尾至前)
    **/
    for(i = num1_size - 1; i >= 0; --i)
    {
        for (j = num2_size - 1; j >= 0; --j)
        {
            result[i+j+1] = (result[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0');
            
            /**
            * 进位放在前面
            **/
            result[i+j] = (result[i+j] - '0') + result[i+j+1] / 10 + '0';
            result[i+j+1] = result[i+j+1] % 10 + '0';            
        }
    }
    
    /**
    * 去掉前导'0'
    **/
    for(i=0; i < num1_size + num2_size + 1; ++i)
    {
        if (result[i] != '0') 
            break;
    }
    
    if (i == num1_size + num2_size + 1)
        return "0";
    
    memmove(result, &result[i], num1_size + num2_size + 1 - i);
    
    printf("%s\n", result);
    
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
