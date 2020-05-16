/**********************������******************************/
#include<stdio.h>                  
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#define ERROR -1
#define OK 1

#define STACK_INIT_SIZE 10//��ʼ������
#define STACK_INCREMENT 2//��������

typedef int Status;

typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	QNode *next;
}*QueuePtr;

struct LinkQueue
{
	QueuePtr front, rear;
};

void InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));//ͷ���
	if (!Q.front)
		exit(EXIT_FAILURE);
	Q.front->next = NULL;
}

void DestroyQueue(LinkQueue &Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

void ClearQueue(LinkQueue &Q)
{
	DestroyQueue(Q);
	InitQueue(Q);
}

Status QueueEmpty(LinkQueue Q)
{
	if (Q.front->next == NULL)
		return true;
	else
		return false;
}

int QueueLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p = Q.front;
	while (Q.rear!=p)
	{
		i++;
		p = p->next;
	}
	return i;
}
/******************���ض�ͷԪ��**********************/
Status GetHead(LinkQueue Q, QElemType &e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;//��ͷԪ��
	e = p->data;
	return OK;
}
/*******************�����βԪ��***************************/
void EnQueue(LinkQueue &Q, QElemType e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(EXIT_FAILURE);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;//p���β���
}
/********************ɾ����ͷԪ�أ���e����***************************/
Status DeQueue(LinkQueue &Q, QElemType &e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;//�൱�ڵڶ���
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}

void QueueTraverse(LinkQueue Q, void(*visit)(QElemType))
{
	QueuePtr p = Q.front->next;//��ͷ���
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}


