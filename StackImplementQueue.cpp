#include<stdio.h>
#include <iostream>
#include <stack>

using namespace std;

/**
* 全局的两个栈实现队列的操作
**/
stack<int> S1;
stack<int> S2;

/**
* 入队列操作
**/
int QueuePush(int value)
{
	/**
	* 入队列加入到栈S1中
	**/
	S1.push(value);
	
	return 0;
}

/**
* 出队列操作
**/
int QueuePop()
{
	int element = -1;
	
	/**
	* 栈S2不为空,则弹出S2的元素
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
