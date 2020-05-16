#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int Status;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

//�������Ķ�������洢��ʾ

typedef char TElemType;

typedef struct BiNode
{
	TElemType data;
	struct BiNode *lchild, *rchild;
} BiNode, *BiTree;


//ջ��˳��洢�ṹ
#define STACK_INIT_SIZE 100      //�洢�ռ��ʼ������
#define STACKINCREMENT 10       //�洢�ռ��������

typedef struct
{
	BiTree *base;
	BiTree *top;
	int stacksize;
} Stack;
