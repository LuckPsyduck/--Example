#include"BinaryTree.h"
#define CHAR 1
//#define CHAR 0

void visit(TElemType e)
{
	printf("%2c", e);
}

void main()
{
	int i;
	BiTree T, p, c;
	TElemType e1, e2;
	InitBiTree(T);

	printf("����ն����������շ�%d(1 �� 0 ��)���������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
	e1 = Root(T);
	if (e1 != Nil)
		printf("�������ĸ�Ϊ%c\n", e1);
	else
		printf("���գ��޸�\n");
#if CHAR
	printf("�밴���������������\n");//char
#else
	printf("�밴���������������\n");//int
#endif

	CreateBiTree(T);
	printf("��������������Ϊ�շ�%d(1 �� 0 �ǿ�)���������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
	e1 = Root(T);
	if (e1 != Nil)
		printf("�������ĸ�Ϊ%c\n", e1);
	else
		printf("���գ��޸�\n");

	printf("�������������:\n");
	InOrderTraverse(T, visit);

	printf("\n�������������:\n");
	PostOrderTraverse(T, visit);
	printf("\n");

	printf("������һ������ֵ:");
	getchar();
	scanf("%c", &e1);
	p = Point(T, e1);

	printf("����ֵΪ %c \n", Value(p));

	printf("���ı�˽���ֵ����������ֵ:");
	getchar();
	scanf("%c", &e2);
	getchar();
	Assign(p, e2);

	printf("�����������:\n");
	LevelOrderTraverse(T, visit);

	e1 = Parent(T, e2);
	if (e1 != Nil)
		printf("%c��˫����%c ", e2, e1);
	else
		printf("%cû��˫�� ", e2);
	e1 = LeftChild(T, e2);
	if (e1 != Nil)
		printf("������%c ", e1);
	else
		printf("û������");

	e1 = RightChild(T, e2);
	if (e1 != Nil)
		printf("�Һ�����%c ", e1);
	else
		printf("û���Һ��� ");

	e1 = LeftSibling(T, e2);
	if (e1 != Nil)
		printf("���ֵ���%c ", e1);
	else
		printf("û�����ֵ� ");

	e1 = RightSibling(T, e2);//�������Ľ��������
	if (e1 != Nil)
		printf("���ֵ���%c ", e1);
	else
		printf("û�����ֵ� ");

	InitBiTree(c);
	printf("\n");
	printf("�빹��һ��������Ϊ�յĶ�����c:\n");
#if CHAR
	printf("�밴�������������(�ո�):\n");
#else
	printf("�밴�������������(0):\n");
#endif

	CreateBiTree(c);
	printf("����ݹ����������c:\n");
	InOrderTraverse(c, visit);
	printf("\n");

	printf("��c�嵽��T�У�������T����c��˫�׽����0���ң�1������:");
	getchar();
	scanf("%c %d", &e1, &i);
	getchar();
	p = Point(T, e1);

	InsertChild(p, i, c);
	printf("����ݹ����������:\n ");
	PreOrderTraverse(T, visit);
	printf("\n");

	printf("ɾ���������������ɾ��������˫�׽�㣬��0���ң�1������:");
	//getchar();
	scanf("%c %d", &e1, &i);
	p = Point(T, e1);
	DeleteChild(p, i);

	printf("����ݹ����������:\n");
	PreOrderTraverse(T, visit);
	printf("\n");
	printf("����ǵݹ����������:\n");
	InOrderTraverse1(T, visit);
	printf("\n");
	printf("����ǵݹ����������:\n");
	InOrderTraverse2(T, visit);
	DestroyBiTree(T);
}