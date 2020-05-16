#pragma once
#include<iostream>
#include<iomanip>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;


typedef char Status;
typedef char SElemType;

//typedef char Status;
//typedef char SElemType;

#define ERROR 0
#define EQUAL 1

#define STACKSIZE 100
#define STACKINCREMENT 10

class CStack
{
public:
	CStack() {};
	~CStack() {};
private:
	SElemType *base;
	SElemType *top;
	int stacksize; 

public:
	//����һ����ջS
	Status InitStack(CStack  **S);

	//ջ������ջ������
	Status DestroyStack();

	//ջ��������Ϊ��ջ
	Status ClearStack();

	//ջ�����򷵻�true,����false
	bool StackEmpty();

	// ջ�����򷵻�ջ��Ԫ�ظ���,��ջ�ĳ���
	int StackLength();

	//ջ�����ҷǿ��򷵻�ջ��ջ��Ԫ��
	SElemType GetTop();

	// ջ���������Ԫ��eΪ�µ�ջ��Ԫ��
	Status Push(SElemType e);

	// ջ�����ҷǿ���ɾ��ջ��ջ��Ԫ�ز���e������ֵ
	SElemType Pop(SElemType *e);

	// ջ�ı���
	void StackTraverse(void(*visit)(SElemType *));
};

