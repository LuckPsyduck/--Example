/**********************ѭ������******************************/
/*********�洢�ռ�ΪMAX_QSIZE��ѭ�������У����ֻ�ܴ��MAX_QSIZE-1��Ԫ��********/
/*���пյ������Ƕ�βָ����ڶ�ͷָ�룬��������������Ϊ����βָ��+1����MAX_QSIZE���� ���ڶ�ͷָ��*/
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

#define MAX_QSIZE 5//ʵ�������г���Ϊ MAX_QSIZE+1

struct SqQueue
{
	QElemType *base;//��ʼ���Ķ�̬����洢�ռ�
	int front;//ͷָ��,ָ�����ͷԪ��
	int rear;//βָ�룬ָ�����βԪ�ص���һ��λ��
};


void InitQueue(SqQueue &Q)
{
	Q.base = (QElemType *)malloc(MAX_QSIZE*sizeof(QElemType));//ͷ���
	if (!Q.base)
		exit(EXIT_FAILURE);
	Q.front = Q.rear = 0;
}

void DestroyQueue(SqQueue &Q)
{
	if (Q.base)
		free(Q.base);
	Q.base = NULL;
	Q.front = Q.rear = 0;
}

void ClearQueue(SqQueue &Q)
{
	Q.front = Q.rear = 0;
}

Status QueueEmpty(SqQueue Q)
{
	if (Q.front==Q.rear)
		return true;
	else
		return false;
}

/******************���ض�ͷԪ��**********************/
Status GetHead(SqQueue Q, QElemType &e)
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	return OK;
}
/***************************ȡ���Ŀ���ǽ�ֵ�޶���0��MAX_QSIZE-1��**************************/

/*******************�����βԪ��***************************/
Status EnQueue(SqQueue &Q, QElemType e)
{
	if ((Q.rear + 1) % MAX_QSIZE == Q.front)//������
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAX_QSIZE;
	return OK;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAX_QSIZE) % MAX_QSIZE;
}
/********************ɾ����ͷԪ�أ���e����***************************/
Status DeQueue(SqQueue &Q, QElemType &e)
{
	if (Q.front == Q.rear)//
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAX_QSIZE;//�ƶ�ͷָ��
	return OK;
}

void QueueTraverse(SqQueue Q, void(*visit)(QElemType))
{
	int i = Q.front;
	while (i != Q.rear)
	{
		visit(Q.base[i]);
		i = (i + 1) % MAX_QSIZE;
	}
	printf("\n");
}


