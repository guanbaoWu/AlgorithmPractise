#include<stdio.h>
#include <iostream>
#include <stack>

using namespace std;

/**
* ȫ�ֵ�����ջʵ�ֶ��еĲ���
**/
stack<int> S1;
stack<int> S2;

/**
* ����в���
**/
int QueuePush(int value)
{
	/**
	* ����м��뵽ջS1��
	**/
	S1.push(value);
	
	return 0;
}

/**
* �����в���
**/
int QueuePop()
{
	int element = -1;
	
	/**
	* ջS2��Ϊ��,�򵯳�S2��Ԫ��
	**/
	if (S2.empty())
	{
		while(!S1.empty())
		{
			S2.push(S1.top());
			S1.pop();
		}
	}
	
	element = S2.top();
	S2.pop();

	return element;
}

int main()
{
	int i = 1;
	for(i = 1; i < 10; ++i)
	{
		QueuePush(i);
	}
	
	for(i = 1; i < 10; ++i)
	{
		cout << "pop value: " << QueuePop() << endl;
	}
	
	return 0;
}
