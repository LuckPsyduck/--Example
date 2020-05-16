#include"Queue.h"

void print(QElemType c)
{
	printf("%3d", c);
}
void main()
{
	int i;
	QElemType d;
	LinkQueue q;
	InitQueue(q);
	printf("�ɹ��ع�����һ���ն���\n");
	printf("�Ƿ�ն��У�%d(1 �� 0 �ǿ�),", QueueEmpty(q));
	printf("���еĳ���Ϊ%d\n", QueueLength(q));

	EnQueue(q, -5);
	EnQueue(q, 5);
	EnQueue(q, 10);

	printf("����3��Ԫ��(-5,5,10)�󣬶��еĳ���Ϊ:%3d\n", QueueLength(q));
	printf("�Ƿ�ն���?%d(1 �� 0 �ǿ�),", QueueEmpty(q));
	printf("���е�Ԫ������Ϊ\n");

	QueueTraverse(q, print);
	i = GetHead(q, d);
	if (i == OK)
		printf("��ͷԪ����%d", d);

	ClearQueue(q);
	printf("��ն��к�q.front=%p,q.rear=%p,q.front->next=%p\n", q.front, q.rear, q.front->next);

	DestroyQueue(q);
	printf("���ٶ��к�q.front=%p,q.rear=%p\n", q.front, q.rear);
}