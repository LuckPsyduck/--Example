#include"Stack.h"
void print(SElemType c)
{
	printf("%d ", c);
}

void main()
{
	int j;
	SqStack s;

	SElemType e;
	InitStack(s);

	for (j = 1; j <= 12; j++)
		Push(s, j);
	printf("ջ��Ԫ������Ϊ:");
	StackTraverse(s, print);

	Pop(s, e);
	printf("������ջ��Ԫ��e=%d\n", e);

	printf("ջ�շ�?%d(1 �� 0 ��),", StackLength(s));
	GetTop(s, e);
	printf("ջ��Ԫ��e=%d,ջ�ĳ���Ϊ%d\n", e, StackLength(s));

	ClearStack(s);
	printf("���ջ��ջ�Ƿ�Ϊ�գ�%d(1 �� 0 ��)\n", StackEmpty(s));
	DestroyStack(s);
	printf("����ջ��,s.top=%p,s.base=%p,s.stacksize=%d\n", s.top, s.base, s.stacksize);
}