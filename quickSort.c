#include <stdio.h>

/**
* ���õݹ�ķ�ʽ
*   iR --�����±��ұ߽� 
*   iL --�����±���߽� 
*   a[] --��������������
**/
int QuickSort(int iR, int iL, int *a)
{
    int i = iR, j = iL;
    
    /**
    * ѡ��һ����ʼ��ֵ
    **/
    int iTemp = a[iR];


    /**
    * ֻ��һ��Ԫ��ʱ����Ҫ����,�ݹ����
    **/
    if (iR >= iL)
    {
        return 0;
    }
    
    while(i < j)
    {
        /**
        * ���ƶ���߽�,�ҳ���߱ȳ�ʼֵС��Ԫ��
        **/
        while(j > i)
        {
            if (a[j] < iTemp)
            {
                break;
            }
            --j;
        }
        
        /**
        * �ƶ��ұ߽��ҳ��ȳ�ʼֵ���Ԫ��
        **/
        while(i < j)
        {
            if (a[i] > iTemp)
            {
				
        		a[i]^=a[j];
        		a[j]^=a[i];
        		a[i]^=a[j];
                break;
            }
            ++i;
        }
        
    }
    
    /**
    * �ѳ�ʼֵ�ƶ����м�
    **/
    a[iR]^=a[i];
    a[i]^=a[iR];
    a[iR]^=a[i];
    
    QuickSort(iR, i-1, a);
    QuickSort(i+1, iL, a);
    
    return 0;
}

int main()
{
	int i = 0;
	int a[10] = {8,1,3,5,2,0,9,1,12,7};
	
	QuickSort(0, 9, a);
	
	for(i=0; i < 10; ++i)
	{
		printf("a[%d]=%d\n", i, a[i]);
	}
	
	return 0;

}
