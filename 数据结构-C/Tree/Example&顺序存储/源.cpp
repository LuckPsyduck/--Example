#pragma warning (disable:4996)
#include"BinartTree.h"
void main()
{
	Status i;
	int j;
	position p;
	TElemType e;
	SqBiTree T, s;
	InitBiTree(T);
	CreateBiTree(T);
	printf("��������������Ϊ����%d��1 �գ�0 �ǿգ����������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));

	i = Root(T, e);
	if (i!=-1)
		printf("�������ĸ�Ϊ: %2d\n", e);
	else
		printf("���գ��޸�\n");

	printf("�������������:\n");
	LevelOrderTraverse(T, visit);

	printf("�������������:\n");
	InOrderTraverse(T, visit);

	printf("�������������:\n");
	PostOrderTraverse(T, visit);

	printf("��������޸Ľ��Ĳ�ţ��������:\n");
	scanf("%d %d", &p.level, &p.order);
	e = Value(T, p);
	printf("���޸Ľ���ԭֵΪ%d,��������ֵ:\n", e);
	scanf("%d", &e);
	Assign(T, p, e);
	printf("�������������:\n");
	PreOrderTraverse(T, visit);

	printf("���%d��˫��Ϊ%d\n", e, Parent(T, e));
	printf("���Һ��ӷֱ�Ϊ:%d %d\n", LeftChild(T, e), RightChild(T, e));
	printf("�����ֵڷֱ�Ϊ:%d %d\n", LeftSibling(T, e), RightSibling(T, e));

	InitBiTree(s);
	printf("����������Ϊ�յ���s:\n");
	CreateBiTree(s);
	printf("��s�嵽��T�У���������T������˫�׽��sΪ��0���ң�1������:\n");
	scanf("%d %d", &e, &j);
	InsertChild(T, e, j, s);

	print(T);
	printf("ɾ���������������������˫�׽�㣬����j��ֵȷ����s��e�����������:\n");
	scanf("%d %d %d", &p.level, &p.order, &j);
	DeleteChild(T, p, j);
	print(T);
	InitBiTree(T);//ɾ��,ͬ������
	printf("ɾ������������Ϊ����%d��1 �գ�0 �ǿգ����������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
	i = Root(T, e);
	if (i!=-1)
		printf("�������ĸ�Ϊ:%d\n", e);
	else
		printf("���գ��޸�\n");
}