#include "stdafx.h"
#include "LinkStack.h"

using namespace std;

//���캯��
CLinkStack::CLinkStack()
{
	top = NULL;
	size = 0;
}

//��ʼ��ջ,����洢�ռ䲢�ÿ�
void CLinkStack::InitStack(int L)
{
	top = new StackNode[L];
	size = 0;
}

//�������������ջ
void CLinkStack::CreateStack(int n, int m, int mark)
{
	ElemType x, a[LEN / 2];
	srand(n);
	for (int i = 0; i<m; i++)
		a[i] = rand() % 100;
	for (int i = 0; i<m - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j<m; j++)
			if (a[k]>a[j]) 
				k = j;
		if (k != i)
		{
			x = a[k]; 
			a[k] = a[i]; 
			a[i] = x;
		}
	}

	for (int i = 0; i<m; i++)
		if (mark == 1) 
			Push(a[m - 1 - i]);//����
		else
			if (mark == -1)
				Push(a[i]);//����
			else 
				Push(rand() % 100);//����
}

int CLinkStack::StackSize()
{
	return size;
}

//���ջ
void CLinkStack::ClearStack()
{ 
	size = 0;
}

//ɾ��ջ
void CLinkStack::DeleteStack()
{
	delete top;
}

//���ջ�Ƿ�Ϊ��
bool CLinkStack::StackEmpty() 
{
	return size == 0;
}

//��ȡջ��Ԫ��
ElemType CLinkStack::Peek()
{
	return top->data;
}

//��ջ�в���Ԫ��
void CLinkStack::Push(const ElemType& item)//����
{
	StackNode *newNode = new StackNode;
	newNode->data = item;
	newNode->next = top;
	top = newNode;
	size++;
}

//��ջ��ɾ��Ԫ��
ElemType CLinkStack::Pop()
{
	if (size == 0) 
	{
		cerr << "ջΪ��!" << endl; 
		exit(1);
	}
	StackNode *p = top->next;//����
	ElemType data = top->data;
	delete top;
	size--;
	top = p;
	return data;
}

//���ջ�Ƿ�����
bool CLinkStack::StackFull(ElemType m)
{
	return size == m;
}

//ջ�����
void CLinkStack::StackPrint(ElemType m)
{
	for (int i = 0; i<m; i++)
		cout << setw(3) << Pop();
}