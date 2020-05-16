#pragma once
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<strstream>

typedef float ElemType;

const int LEN = 40;
typedef struct Stack {
	ElemType data;
	struct Stack *next;
}StackNode;//�����������


class CLinkStack
{
public:
	CLinkStack();
	~CLinkStack() {};
private:
	StackNode *top;//ָ��ջ����ָ��
	int size;// ��ջ�Ľ�����
public:

	//��ʼ��ջ,����洢�ռ䲢�ÿ�
	void InitStack(int);

	//�������������ջ
	void CreateStack(int, int m = LEN, int mark = 0);

	//���ض�ջ�Ľ�����
	int StackSize();

	//���ջ
	void ClearStack();

	//ɾ��ջ
	void DeleteStack();

	//���ջ�Ƿ�Ϊ��
	bool StackEmpty();

	//��ȡջ��Ԫ��
	ElemType Peek();

	//��ջ�в���Ԫ��
	void Push(const ElemType&);

	//��ջ��ɾ��Ԫ��
	ElemType Pop();

	//���ջ�Ƿ�����
	bool StackFull(ElemType m = LEN);

	//ջ�����
	void StackPrint(ElemType m = LEN);
};

