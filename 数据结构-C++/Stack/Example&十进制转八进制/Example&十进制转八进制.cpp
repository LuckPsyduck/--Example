// ʮ����ת�˽���.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "Stack.h"

void conversion()
{
	CStack *S;
	SElemType e;
	int n;
	S->InitStack(&S);
	printf("����ʮ������:");
	cin >> n;
	if (n<0)
	{
		printf("\n�����������!\n");
		return;
	}
	if (!n)
		S->Push(0);
	while (n)
	{
		S->Push(n % 8);//����ȡ��
		n = n / 8;
	}
	printf("�����:");
	while (!S->StackEmpty())
	{
		S->Pop(&e);
		printf("%d", e);
	}
	cout << endl;
}
void main()
{
	printf("convert.cpp���н��:\n");
	conversion();
	getchar();
}

