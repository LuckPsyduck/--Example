/*******************************ջ��˳��洢**********************/
#include<stdio.h>                  
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#define ERROR -1
#define OK 1

typedef int SElemType;
typedef int Status;

/*********************************˳��ջ�洢�ṹ************************/
#define STACK_INIT_SIZE 10//��ʼ������
#define STACK_INCREMENT 2//��������
struct SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;//�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
};
/************************************************************************/
void InitStack(SqStack &S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(EXIT_FAILURE);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{
	free(S.base);
	S.top = S.base = NULL;
	S.stacksize = 0;
}

Status ClearStack(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}

Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}

int StackLength(SqStack S)
{
	return S.top - S.base;
}
/****************************����ջ��Ԫ��***********************/
Status GetTop(SqStack S, SElemType &e)
{
	if (S.top > S.base)
	{
		e = *(S.top - 1);
		return OK;
	}
	else
		return ERROR;
}

void Push(SqStack &S, SElemType e)
{
	if (S.top - S.base == S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof(SElemType));
		if (!S.base)
			exit(EXIT_FAILURE);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*(S.top)++ = e;
}

Status Pop(SqStack &S, SElemType &e)
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}

void StackTraverse(SqStack S, void(*visit)(SElemType))
{
	while (S.top>S.base)
	{
		visit(*S.base++);
	}
	printf("\n");
}
