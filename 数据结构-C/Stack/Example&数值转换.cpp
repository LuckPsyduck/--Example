/**********************ʮ����תn����********************/

#include"Stack.h"
#define N 8    //�����ת���Ľ��� N��2-9��

void conversion()
{
	SqStack s;
	unsigned n;
	SElemType e;
	InitStack(s);

	printf("��ʮ��������nת��Ϊ%d�������������룺n��>=0��=", N);
	scanf("%u", &n);
	while (n)
	{
		Push(s, n%N);
		n = n / N;
	}
	while (!StackEmpty(s))
	{
		Pop(s, e);
		printf("%d", e);
	}
	printf("\n");
}

void main()
{
	conversion();
}
