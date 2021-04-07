#define _CRT_SECURE_NO_WARNINGS 1
//��д����,����˳��洢ʵ��ջ�ĳ�ʼ������ջ����ջ����
#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define Stack_Size 50
#define MAXSIZE 50
typedef struct//˳��ջ
{
	int elem[Stack_Size];
	int top;
}SeqStack;
typedef struct node//��ջ
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
typedef struct//������
{
	LinkQueueNode* front;
	LinkQueueNode* rear;

}LinkQueue;
typedef struct//˳�����
{
	int elem[Stack_Size];
	int front;
	int rear;
}SeqQueue;




void InitSeqStack(SeqStack *s)  //˳��ջ��ʼ��
{
	s->top = -1;
}
int Push_SeqStack(SeqStack *s, int x)//˳��ջ��ջ����
{
	if (s->top == Stack_Size - 1)
	{
		printf("ջ���ˣ�\n");
		return(FALSE);
	}
	s->top++;
	s->elem[s->top] = x;
	printf("�����ɹ���\n");
	printf("������˳��ջΪ��\n");
	int i = s->top;
	while (i != -1)
	{
		printf(" %2d ", s->elem[i]);
		i--;
	}
	printf("\n");
	return(TRUE);
}

int Pop_SeqStack(SeqStack *s, int*x)//˳��ջ��ջ����
{
	if (s->top == -1)
	{
		printf("��ջΪ��ջ��");
		*x = -1;
		return(FALSE);

	}
	else
	{
		*x = s->elem[s->top];
		s->top--;
		printf("�����ɹ�\n");
		printf("������˳��ջΪ��\n");
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
//��д����,������ʽ�洢ʵ��ջ�ĳ�ʼ������ջ����ջ����
void Init_LinkStackNode(LinkStack L)//��ջ��ʼ��
{
	L->next =NULL;
}

int Push_LinkStackNode(LinkStack top, int x)//��ջ��ջ����
{
	LinkStackNode*temp;
	temp = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (temp == NULL)
	{
		printf("temp�����ռ�ʧ�ܣ�");
		return(FALSE);
	}
	temp->data = x;
	temp->next = top->next;
	top->next = temp;
	printf("�����ɹ���\n");
	return(TRUE);
}

int Pop_LinkStackNode(LinkStack top, int *x)//��ջ��ջ
{
	LinkStackNode*temp;
	temp = top->next;
	if (temp == NULL)
	{
		printf("tempָ��Ϊ�գ�����ʧ�ܣ�");
		*x = -1;
		return(FALSE);
	}
	top->next = temp->next;
	*x = temp->data;
	free(temp);
	printf("�����ɹ���\n");
	return(TRUE);
}
//��д����,������ʽ�洢ʵ�ֶ��еĳ�ʼ������ӡ����Ӳ���
int InitLinkQueue(LinkQueue*Q)//��ʽ���г�ʼ��
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
		printf("���������");
		return(FALSE);
	}
}
int EnterLinkQueue(LinkQueue*Q, int x)//��ʽ�������
{
	LinkQueueNode*NewNode;
	NewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL)
	{
		NewNode->data = x;
		NewNode->next = NULL;
		Q->rear->next = NewNode;
		Q->rear = NewNode;
		printf("�����ɹ���\n");
		return(TRUE);
	}
	else 
	{
		printf("��Ӳ���ʧ�ܣ�");
		return(FALSE);
	}
}
int DeleteLinkQueue(LinkQueue*Q, int *x)//�����г���
{
	LinkQueueNode*p;
	if (Q->front == Q->rear)
	{
		printf("�˶����ǿն���\n");
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
		printf("���Ӳ����ɹ���\n");
		return(TRUE);

	
	return(FALSE);
}
//��д����,����˳��洢ʵ�ֶ��еĳ�ʼ������ӡ����Ӳ���
int InitSeqQueue(SeqQueue*S)//˳����г�ʼ��
{
	S->front = S->rear = 0;
	return(TRUE);
}

int EnterSeqQueue(SeqQueue* S, int x)//˳��������
{
	if ((S->rear + 1) % MAXSIZE == S->front)
	{
		printf("����������");
		return(FALSE);
	}
	S->elem[S->rear] = x;
	S->rear = (S->rear + 1) % MAXSIZE;
	printf("�����ɹ���\n");
	return(TRUE);
	
}
int DeleteSeqQueue(SeqQueue*Q, int *x)//˳����г���
{
	if (Q->front == Q->rear)
	{
		printf("����Ϊ�գ�");
		*x = -1;
		return (FALSE);
	}
	*x = Q->elem[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return(TRUE);
}

void menu()
{
	printf("\n************�˵�****************\n\n");
	printf("********1��˳��ջ��ʼ��*********\n"); 
	printf("********2��˳����ջ����*********\n"); 
	printf("********3��˳��ջ��ջ����*******\n"); 
	printf("********4����ʽ���г�ʼ��*******\n");
	printf("********5����ջ��ջ����*********\n"); 
	printf("********6����ջ��ջ����*********\n"); 
	printf("********7����ʽ���г�ʼ��*******\n");
	printf("********8����ʽ�������*********\n");
	printf("********9�������г���***********\n");
	printf("********10��˳����г�ʼ��******\n");
	printf("********11��˳��������********\n");
	printf("********12��˳����г���********\n");
	printf("********************************\n");
	printf("********************************\n\n\n");
	printf("  �������Ӧ���ֽ��в���:");
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
			printf("��ջ����Ϊ��%d\n", *(x2));
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
			printf("��ջ����Ϊ��%d\n", *(x2));
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
		printf("���ӵ���Ϊ��%d\n", *(x2));
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
		printf("���ӵ���Ϊ��%d\n", *(x2));
		break;
	default:
		printf("�������\n");
		break;
	}
	printf("\n�Ƿ����������0��ֹͣ����");
	scanf("%d", &flag);
	}
}