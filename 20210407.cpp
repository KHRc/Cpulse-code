#define _CRT_SECURE_NO_WARNINGS 1
//编写函数,采用顺序存储实现栈的初始化、入栈、出栈操作
#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define Stack_Size 50
#define MAXSIZE 50
typedef struct//顺序栈
{
	int elem[Stack_Size];
	int top;
}SeqStack;
typedef struct node//链栈
{
	int data;
	struct node *next;
}LinkStackNode;
typedef LinkStackNode *LinkStack;
typedef struct Node
{
	int data;
	struct Node *next;
}LinkQueueNode;
typedef struct//链队列
{
	LinkQueueNode* front;
	LinkQueueNode* rear;

}LinkQueue;
typedef struct//顺序队列
{
	int elem[Stack_Size];
	int front;
	int rear;
}SeqQueue;




void InitSeqStack(SeqStack *s)  //顺序栈初始化
{
	s->top = -1;
}
int Push_SeqStack(SeqStack *s, int x)//顺序栈进栈操作
{
	if (s->top == Stack_Size - 1)
	{
		printf("栈满了！\n");
		return(FALSE);
	}
	s->top++;
	s->elem[s->top] = x;
	printf("操作成功！\n");
	printf("操作后，顺序栈为：\n");
	int i = s->top;
	while (i != -1)
	{
		printf(" %2d ", s->elem[i]);
		i--;
	}
	printf("\n");
	return(TRUE);
}

int Pop_SeqStack(SeqStack *s, int*x)//顺序栈出栈操作
{
	if (s->top == -1)
	{
		printf("此栈为空栈！");
		*x = -1;
		return(FALSE);

	}
	else
	{
		*x = s->elem[s->top];
		s->top--;
		printf("操作成功\n");
		printf("操作后，顺序栈为：\n");
		int i = s->top;
		while (i != -1)
		{
			printf(" %2d ", s->elem[i]);
			i--;
		}
		printf("\n");
		return(TRUE);
	}
}
//编写函数,采用链式存储实现栈的初始化、入栈、出栈操作
void Init_LinkStackNode(LinkStack L)//链栈初始化
{
	L->next =NULL;
}

int Push_LinkStackNode(LinkStack top, int x)//链栈入栈操作
{
	LinkStackNode*temp;
	temp = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (temp == NULL)
	{
		printf("temp开创空间失败！");
		return(FALSE);
	}
	temp->data = x;
	temp->next = top->next;
	top->next = temp;
	printf("操作成功！\n");
	return(TRUE);
}

int Pop_LinkStackNode(LinkStack top, int *x)//链栈出栈
{
	LinkStackNode*temp;
	temp = top->next;
	if (temp == NULL)
	{
		printf("temp指针为空，创建失败！");
		*x = -1;
		return(FALSE);
	}
	top->next = temp->next;
	*x = temp->data;
	free(temp);
	printf("操作成功！\n");
	return(TRUE);
}
//编写函数,采用链式存储实现队列的初始化、入队、出队操作
int InitLinkQueue(LinkQueue*Q)//链式队列初始化
{
	Q->front = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (Q->front != NULL)
	{
		Q->rear = Q->front;
		Q->front->next = NULL;
		return(TRUE);
	}
	else
	{
		printf("队列溢出！");
		return(FALSE);
	}
}
int EnterLinkQueue(LinkQueue*Q, int x)//链式队列入队
{
	LinkQueueNode*NewNode;
	NewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL)
	{
		NewNode->data = x;
		NewNode->next = NULL;
		Q->rear->next = NewNode;
		Q->rear = NewNode;
		printf("操作成功！\n");
		return(TRUE);
	}
	else 
	{
		printf("入队操作失败！");
		return(FALSE);
	}
}
int DeleteLinkQueue(LinkQueue*Q, int *x)//链队列出队
{
	LinkQueueNode*p;
	if (Q->front == Q->rear)
	{
		printf("此队列是空队列\n");
		*x = -1;
		return(FALSE);
	}
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
		*x = p->data;
		free(p);
		printf("出队操作成功！\n");
		return(TRUE);

	
	return(FALSE);
}
//编写函数,采用顺序存储实现队列的初始化、入队、出队操作
int InitSeqQueue(SeqQueue*S)//顺序队列初始化
{
	S->front = S->rear = 0;
	return(TRUE);
}

int EnterSeqQueue(SeqQueue* S, int x)//顺序队列入队
{
	if ((S->rear + 1) % MAXSIZE == S->front)
	{
		printf("队伍已满！");
		return(FALSE);
	}
	S->elem[S->rear] = x;
	S->rear = (S->rear + 1) % MAXSIZE;
	printf("操作成功！\n");
	return(TRUE);
	
}
int DeleteSeqQueue(SeqQueue*Q, int *x)//顺序队列出队
{
	if (Q->front == Q->rear)
	{
		printf("队列为空！");
		*x = -1;
		return (FALSE);
	}
	*x = Q->elem[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return(TRUE);
}

void menu()
{
	printf("\n************菜单****************\n\n");
	printf("********1、顺序栈初始化*********\n"); 
	printf("********2、顺序入栈操作*********\n"); 
	printf("********3、顺序栈出栈操作*******\n"); 
	printf("********4、链式队列初始化*******\n");
	printf("********5、链栈入栈操作*********\n"); 
	printf("********6、链栈出栈操作*********\n"); 
	printf("********7、链式队列初始化*******\n");
	printf("********8、链式队列入队*********\n");
	printf("********9、链队列出队***********\n");
	printf("********10、顺序队列初始化******\n");
	printf("********11、顺序队列入队********\n");
	printf("********12、顺序队列出队********\n");
	printf("********************************\n");
	printf("********************************\n\n\n");
	printf("  请输入对应数字进行操作:");
}

int main()
{
	SeqStack A;
	SeqStack*a = &A;
	LinkStack B=(LinkStack)malloc(sizeof(LinkStackNode));
	LinkQueue C;
	LinkQueue*c = &C;
	SeqQueue D;
	SeqQueue*d = &D;
	int flag = 1;
	int x1 = 0;
	int*x2 = &x1;
	while (flag)
	{
	menu();
	int x = 0;
	scanf("%d",&x);
	switch (x)
	{
	case 1:
		InitSeqStack(a);
		break;
	case 2:
		
		scanf("%d", &x1);
		Push_SeqStack(a, x1);
		break;
	case 3:
		
		Pop_SeqStack(a, x2);
		if (*x2 != -1)
		{
			printf("出栈的数为：%d\n", *(x2));
		}
	case 4:
		Init_LinkStackNode(B);
		break;
	case 5:
		scanf("%d", &x1);
		Push_LinkStackNode(B, x1);
		break;
	case 6:
		Pop_LinkStackNode(B, x2);
		if (*x2 != -1)
		{
			printf("出栈的数为：%d\n", *(x2));
		}
		break;
	case 7:
		InitLinkQueue(c);
		break;
	case 8:
		scanf("%d", &x1);
		EnterLinkQueue(c, x1);
		break;
	case 9:
		DeleteLinkQueue(c, x2);
		if (*x2 != -1)
		printf("出队的数为：%d\n", *(x2));
		break;
	case 10:
		InitSeqQueue(d);
		break;
	case 11:
		scanf("%d", &x1);
		EnterSeqQueue(d, x1);
		break;
	case 12:
		DeleteSeqQueue(d, x2);
		if (*x2 != -1)
		printf("出队的数为：%d\n", *(x2));
		break;
	default:
		printf("输入错误！\n");
		break;
	}
	printf("\n是否继续（输入0就停止）：");
	scanf("%d", &flag);
	}
}