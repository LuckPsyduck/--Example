// ˳��ѭ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Queue.h"

void main()
{
	CQueue MyQueue;
	int i, x, m, a[3];
	printf("��������������������m:");
	scanf("%d", &m);
	srand(m);
	printf("����˳��ѭ������MyQueue:\n");
	for (i = 0; i<QueueSize;)
	{
		x = rand() % 1000;
		if (100 <= x&&x <= 999)
		{
			MyQueue.enqueue(x); 
			i++;
		}
	}
	printf("��˳��ѭ������MyQueue�ĳ���:");
	printf("%d\n", MyQueue.QueueLength());
	printf("���˳��ѭ������MyQueue:\n");
	printf("ͬʱ����һ����λ���Ƿ�Ϊ������.\n");
	while (!MyQueue.queueempty())
	{
		x = MyQueue.dequeue();
		printf("%4d", x);
		a[0] = x % 10;
		x = x / 10; 
		a[1] = x % 10;
		x = x / 10; 
		a[2] = x;
		if (a[0] != a[2]) 
			printf("���ǻ�����!\n");
		if (a[0] == a[2])
			printf("�ǻ�����!\n");
	}
	cin.get(); 
	cin.get();
}
