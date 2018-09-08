#include <stdio.h>
#include <stdlib.h>

typedef struct st_list{
    int value;
    struct st_list *next;
}List;

//typedef struct st_list List;

int ReverseList(List *pList)
{
    List *pFirst = NULL;
    List *pTemp  = NULL;
    
    if (!pList || !pList->next)
    {
        return 0;
    }
    
    pFirst = pList->next;
    while(pFirst->next)
    {
        pTemp = pFirst->next;
        pFirst->next = pTemp->next;
        
        pTemp->next = pList->next;
        
        pList->next = pTemp;
    }
    
    return 0;
}

int createList(List *pHead)
{
	int i = 0;
	List *Node = NULL;
	
	if (NULL == pHead)
	{
		return -1;
	}
	
	for(i=0; i<10; ++i)
	{
		Node = malloc(sizeof(List));
		if (Node != NULL)
		{
			Node->value = i;
			Node->next = pHead->next;
			pHead->next = Node;
		}
	}
	
	return 0;
}

void freeList(List *pHead)
{
	List *Temp = NULL;
	List *Node = NULL;
	
	if (NULL == pHead)
	{
		return;
	}
	
	Node = pHead->next;
	while(Node)
	{
		Temp = Node;
		Node = Temp->next;
		free(Temp);
	}
}

void printList(List *pHead)
{
	List *Node = NULL;
	
	if (NULL == pHead)
	{
		return;
	}
	
	Node = pHead->next;
	while(Node)
	{
		printf("Node:%p,value:%d\n", Node, Node->value);
		Node = Node->next;
	}
}

int main()
{
	List stList = {-1, NULL};
	
	if (0 != createList(&stList))
	{
		return -1;
	}
	
	printList(&stList);
	
	ReverseList(&stList);
	
	printList(&stList);
	
	return 0;
	
}
