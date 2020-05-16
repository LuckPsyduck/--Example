#pragma once
#include<iostream>
#include<iomanip>

using namespace std;

typedef char ElemType;//������������ݲ�ͬ�����巢���仯

const int LEN = 40;
class CStack
{
private:
	ElemType stack[LEN];
	int top;
public:
	//���캯��
	CStack() { top = 0; }

	//��������
	~CStack() {}

	//�������������ջ
	void CreateStack(int, int m = LEN, int mark = 0);

	//���ջ
	void ClearStack();

	//���ջ�Ƿ�Ϊ��
	bool StackEmpty();

	//��ȡջ��Ԫ��
	ElemType Peek();

	//��ջ�в���Ԫ��
	void Push(const ElemType&, int m = LEN);

	//��ջ��ɾ��Ԫ��
	ElemType Pop();

	//���ջ�Ƿ�����
	bool StackFull(int m = LEN);

	//ջ�����
	void StackPrint(int m = LEN);
};

