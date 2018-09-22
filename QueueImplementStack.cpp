#include<stdio.h>
#include <iostream>
#include <queue>

using namespace std;

/**
* ȫ�ֵ���������ʵ��ջ�Ĳ���
**/
queue<int> Q1;
queue<int> Q2;

/**
* ��ջ����
**/
int StackPush(int value)
{
	/**
	* ����м��뵽��Ϊ�յĶ�����
	**/
	queue<int> &PushQ = Q1.empty() ? Q2 : Q1;
	
	PushQ.push(value);
	
	return 0;
}

/**
* ��ջ����
**/
int StackPop()
{
	int element = -1;
	
	queue<int> &PopQ = Q1.empty() ? Q2 : Q1;
	queue<int> &EmptyQ = Q1.empty() ? Q1 : Q2;
	
	/**
	* ����Ϊ�յĶ����е�Ԫ����ӵ��ն�����
	* ֱ��������ֻʣ��Ҫ���ص�Ԫ��
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
