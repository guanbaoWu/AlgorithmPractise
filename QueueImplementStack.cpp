#include<stdio.h>
#include <iostream>
#include <queue>

using namespace std;

/**
* 全局的两个队列实现栈的操作
**/
queue<int> Q1;
queue<int> Q2;

/**
* 入栈操作
**/
int StackPush(int value)
{
	/**
	* 入队列加入到不为空的队列中
	**/
	queue<int> &PushQ = Q1.empty() ? Q2 : Q1;
	
	PushQ.push(value);
	
	return 0;
}

/**
* 出栈操作
**/
int StackPop()
{
	int element = -1;
	
	queue<int> &PopQ = Q1.empty() ? Q2 : Q1;
	queue<int> &EmptyQ = Q1.empty() ? Q1 : Q2;
	
	/**
	* 将不为空的队列中的元素添加到空队列中
	* 直到队列中只剩余要返回的元素
	**/
	while(PopQ.size() > 1)
	{
		EmptyQ.push(PopQ.front());
		PopQ.pop();
	}
	
	if (PopQ.size() == 1)
	{
		element = PopQ.front();
		PopQ.pop();
	}
	
	return element;
	
}

int main()
{
	int i = 1;
	for(i = 1; i < 10; ++i)
	{
		StackPush(i);
	}
	
	for(i = 1; i < 10; ++i)
	{
		cout << i << " pop value: " << StackPop() << endl;
	}
	
	return 0;
}
