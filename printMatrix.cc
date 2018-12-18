#include <iostream>
#include <string>

using namespace std;
/**
* 给定一个二维数组,要求顺时针从外至内将该二维数组的数字打印
* 如：
* 10 20 30 40 50
* 61 71 81 91 11
* 21 31 41 51 61
* 12 22 32 42 52
* 13 33 43 53 63
* 输出: 10 20 30 40 50 11 61 52 63 53 43 33 13 12 21 61 71 81 91 51 42 32 22 31 41

* 实现原理:
* 1、首先实现顺时针按圆圈打印,发现圆圈的打印起始处都是由坐标[i,i]开始
* 2、起点开始后，先右前进，当 x >= (col - start)停止
* 3、向右前进停止后，向下前进(row > i条件满足才能前进)，当 Y >= (row - i)停止
* 4、先下前进停止后，向左一定能前进，当X <= i 停止
* 5、向左前进停止后，向上前进(row - i > 1条件满足才能前进),当 Y >= i 时停止
**/
class Solution
{
public:

    /**
    * 向右，下，左，上前进，分别打印
    **/
    void CircleLoopPrint(int (*a)[5], int start, int row, int col)
    {
        int i = 0;
        int endx = col - start - 1;
        int endy = row - start - 1;
        
        if (NULL == a)
            return;
        
        /**
        * 向右前进
        **/
        for (i = start; i <= endx; ++i)
        {
            cout << a[start][i] << " ";
        }
        
        /**
        * 向下前进
        **/
        if (row > start)
        {
            for (i = start + 1; i <= endy; ++i)
            {
                cout << a[i][endx] << " ";
            }
        }
        
        /**
        * 向左前进
        **/
        if (endx > start && endy > start)
        {
            for (i = endx - 1; i >= start; --i)
            {
                cout << a[endy][i] << " ";
            }
        }
        
        /**
        * 向上前进
        **/
        if (endx > start &&  endy-1 > start)
        {
            for (i = endy - 1; i > start; --i)
            {
                cout << a[i][start] << " ";
            }
        }
        
    }
    
    void PrintMatrix(int (*a)[5], int row, int col)
    {
        int i;
        
        if (NULL == a)
            return;
            
        /**
        * 先打印圆圈
        **/
        for(i = 0; 2*i < row && 2*i < col; ++i)
        {
            CircleLoopPrint(a, i, row, col);
        }
        
        cout << endl;
    }
};

int main()
{
    int a[5][5] = {{10,20,30,40,50},
                   {61,71,81,91,11},
                   {21,31,41,51,61},
                   {12,22,32,42,52},
                   {13,33,43,53,63}
                  };
                  
    int b[4][5] = {{10,20,30,40,50},
                   {61,71,81,91,11},
                   {21,31,41,51,61},
                   {12,22,32,42,52}
                  };
                  
    
    
    Solution s;
    
    s.PrintMatrix(a, 5, 5);
    s.PrintMatrix(b, 4, 5);
    
    return 0;
}
