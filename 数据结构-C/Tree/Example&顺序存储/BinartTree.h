/*******************************��������˳���ʾ**********************/
#include<stdio.h>                  
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ERROR -1
#define OK 1


#define CHAR 0
/***************************�������ѡ��*************************************/
#if CHAR
typedef  char TElemType;
TElemType Nil = ' ';
#else
typedef int TElemType;
TElemType Nil = 0;
#endif // CHAR

void visit(TElemType e)
{
	/*printf("%c", e);*/
	printf("%2d", e);
}
/****************************************************************/

//
typedef int Status;
#define MAX_TREE_SIZE 100
typedef TElemType SqBiTree[MAX_TREE_SIZE];


struct position
{
	int level;//��
	int order;//��ţ��������������㣩//�������λ����ţ�1��ʼ��
};

/*******************/
#define ClearBiTree InitBiTree
#define DestroyBiTree InitBiTree

void InitBiTree(SqBiTree T)
{
	int i;
	for (i = 0; i < MAX_TREE_SIZE; i++)
		T[i] = Nil;
}

/**********************����������������������ֵ****************/
void CreateBiTree(SqBiTree T)
{
	int i = 0;
	InitBiTree(T);
#if CHAR//ֵΪ���㣬�������Ϊ�ַ�
	int n;
	char s[MAX_TREE_SIZE];
	printf("�밴����������ֵ(�ַ�)���ո��ʾ�ս�㣬�����<=%d:\n", MAX_TREE_SIZE);
	gets_s(s);
	n = strlen(s);
	for (; i < n; i++)
		T[i] = s[i];
#else
	printf("�밴����������ֵ(����)��0��ʾ�ս�㣬����999�����������<=%d:\n", MAX_TREE_SIZE);
	while (1)
	{
		scanf("%d", &T[i]);
		if (T[i] == 999)//�������
		{
			T[i] = Nil;
			break;
		}
		i++;
	}
#endif // CHAR
	for(i=1;i<MAX_TREE_SIZE;i++)
		if (T[i] !=Nil&&T[(i + 1) / 2 - 1] == Nil)//��㲻�յ���˫��(���������)
		{
			printf("������˫�׵ķǸ����%c\n",T[i]);
			printf("������˫�׵ķǸ����%d\n", T[i]);
			exit(EXIT_FAILURE);
		}
}

Status BiTreeEmpty(SqBiTree T)
{
	if (T[0] == Nil)//�����
		return true;
	else
		return false;
}

int BiTreeDepth(SqBiTree T)
{
	int i;
	if (T[0] == Nil)
		return 0;
	for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
		if (T[i] != Nil)//�ҵ����һ����㣬�����Ϊ��
			break;
	return (int)(log(i + 1) / log(2) + 1.1);
}
/*************************��e���ظ����*******************/
Status Root(SqBiTree T, TElemType &e)
{
	if (BiTreeEmpty(T))
		return ERROR;
	else
	{
		e = T[0];
		return OK;
	}
}
/**********************���ش���λ��e���㣬�������ţ��Ľ���ֵ****************/
TElemType Value(SqBiTree T, position e)
{
	return T[int(pow(2, e.level - 1) + e.order - 2)];
}

/************������λ��e���㣬�������ţ��Ľ�㸳��ֵvalue***********/
Status Assign(SqBiTree T, position e, TElemType value)
{
	int i = int(pow(2, e.level - 1) + e.order - 2);
	if (i != 0 && value != Nil&&T[(i + 1) / 2 - 1] == Nil)
		return ERROR;
	else if (value == Nil && (T[i * 2 + 1] != Nil || T[i * 2 + 2] != Nil))
		return ERROR;
	T[i] = value;
	return OK;
}
/*************ŵe��T�ķǸ���㣬�򷵻�����˫�ף����򷵻ؿ�*********/
TElemType Parent(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] ==Nil)
		return Nil;
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
		if (T[i] == e)
			return T[(i + 1) / 2 - 1];//����˫�׽���ֵ
	return Nil;
}
/********************����e�����ӣ�ŵe�����ӣ��򷵻ؿ�****************/
TElemType LeftChild(SqBiTree T, TElemType e)
{
	int i;
	for (i = 0; i <= (MAX_TREE_SIZE - 2) / 2; i++)
		if (T[i] == e)
			return T[i * 2 + 1];//����e�����ӵ�ֵ
	return Nil;
}


TElemType RightChild(SqBiTree T, TElemType e)
{
	int i;
	for (i = 0; i <= (MAX_TREE_SIZE - 3) / 2; i++)//��T�ĵ�һ����㵽���һ���������Һ��ӵĽ��
		if (T[i] == e)
			return T[i * 2 + 2];
	return Nil;
}

TElemType LeftSibling(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil)
		return Nil;
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
		if (T[i] == e&&i % 2 == 0)//�ҵ�e���������ż�����Һ��ӣ�
			return T[i - 1];//����e�����ֵܵ�ֵ
	return Nil;
}

TElemType RightSibling(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil)
		return Nil;
	for (i = 1; i <= MAX_TREE_SIZE - 2; i++)
		if (T[i] == e&&i % 2)//�ҵ�e�������Ϊ���������ӣ�
			return T[i + 1];//�������ֵܵ�ֵ
	return Nil;
}

/*************�Ѵ�q��j��㿪ʼ��������Ϊ��T��i��㿪ʼ������*****************/
void Move(SqBiTree q, int j, SqBiTree T, int i)
{
	if (i >= MAX_TREE_SIZE)
		exit(EXIT_FAILURE);
	if (q[2 * j + 1] != NULL)//q������������
		Move(q, (2 * j + 1), T, (2 * i + 1));//��q��j������������ΪT��i����������
	if (q[2 * j + 2] != NULL)//q������������
		Move(q, (2 * j + 2), T, (2 * i + 2));//��q��j������������ΪT��i����������
	T[i] = q[j];//���
	q[j] = Nil;
}

/*����LRΪ0��1������cΪT��p���������������P����ԭ������������������Ϊc��������*/
void InsertChild(SqBiTree T, TElemType p, int LR, SqBiTree c)
{
	int j, k;
	for (j = 0; j<int(pow(2, BiTreeDepth(T))) - 1; j++)//����p�����
		if (T[j] == p)//jΪp�����
			break;
	k = 2 * j + 1 + LR;//kΪp�����ӻ��Һ��ӵ����
	if (T[k] != Nil)//pԭ�������ӻ��Һ��Ӳ���
		Move(T, k, c, 2);//�Ѵ�T��k��㿪ʼ��������Ϊc��������
	Move(c, 0, T, k);//����c��Ϊ��T��k��㿪ʼ������
}



/*********************����**************************/


typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	QNode *next;
}*QueuePtr;

struct LinkQueue
{
	QueuePtr front, rear;
};

void InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));//ͷ���
	if (!Q.front)
		exit(EXIT_FAILURE);
	Q.front->next = NULL;
}

void DestroyQueue(LinkQueue &Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

void ClearQueue(LinkQueue &Q)
{
	DestroyQueue(Q);
	InitQueue(Q);
}

Status QueueEmpty(LinkQueue Q)
{
	if (Q.front->next == NULL)
		return true;
	else
		return false;
}

int QueueLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p = Q.front;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}
/******************���ض�ͷԪ��**********************/
Status GetHead(LinkQueue Q, QElemType &e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;//��ͷԪ��
	e = p->data;
	return OK;
}
/*******************�����βԪ��***************************/
void EnQueue(LinkQueue &Q, QElemType e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(EXIT_FAILURE);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;//p���β���
}
/********************ɾ����ͷԪ�أ���e����***************************/
Status DeQueue(LinkQueue &Q, QElemType &e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;//�൱�ڵڶ���
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}

void QueueTraverse(LinkQueue Q, void(*visit)(QElemType))
{
	QueuePtr p = Q.front->next;//��ͷ���
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}


/*****************�������Ĳ���*****************************************************************************/

/*********************����LRΪ0��1��ɾ��T��p��ָ�������������********************/
Status DeleteChild(SqBiTree T, position p, int LR)
{
	int i;//��ɾ�����Ľ�㣬��ɾ����
	Status k = OK;//���в�Ϊ��
	LinkQueue q;
	InitQueue(q);//��ʼ�������ڴ�Ŵ�ɾ���Ľ��

	i = (int)pow(2, p.level - 1) + p.order - 2;//���㣬��������ת��Ϊ��������
	if (T[i] == Nil)
		return ERROR;
	i = i * 2 + 1 + LR;//��ɾ�������ĸ�����������е����(�ӽ��)
	while (k!=-1)//
	{
		if (T[2 * i + 1] != Nil)//���㲻Ϊ��
			EnQueue(q, 2 * i + 1);//���
		if (T[2 * i + 2] != Nil)//�ҽ�㲻Ϊ�� 
			EnQueue(q, 2 * i + 2);
		T[i] = Nil;//ɾ���˽�� 
		k = DeQueue(q, i);//���ӽ�����ţ���ֵ����1���ɹ������в��գ�����ok,���򷵻�error
	}
	return OK;
}

void(*VisitFunc)(TElemType);//��������

/*****************�ݹ��������������T�����Ϊe��������preordertraverse()����*******************/
void PreTraverse(SqBiTree T, int e)
{
	VisitFunc(T[e]);//������T�����Ϊe�Ľ��
	if (T[2 * e + 1] != Nil)
		PreTraverse(T, 2 * e + 1);
	if (T[2 * e + 2] != Nil)
		PreTraverse(T, 2 * e + 2);
}

/******************�������T����ÿ�������ú���Visitһ���ҽ�һ��*******************/
void PreOrderTraverse(SqBiTree T, void(*Visit)(TElemType))
{
	VisitFunc = Visit;
	if (!BiTreeEmpty(T))//������
		PreTraverse(T, 0);//�ݹ����������T�����Ϊ0��������T����
	printf("\n");
}

/***********�ݹ��������������T�����Ϊe�Ľ�����������inordertraverse()����****************/
void InTraverse(SqBiTree T, int e)
{
	if (T[2 * e + 1] != Nil)
		InTraverse(T, 2 * e + 1);//������
	VisitFunc(T[e]);//������T�����Ϊe�Ľ��
	if (T[2 * e + 2] != Nil)
		InTraverse(T, 2 * e + 2);//������
}

/***********************�������T����ÿ�������ú���visitһ���ҽ�һ��************************/
void InOrderTraverse(SqBiTree T, void(*Visit)(TElemType))
{
	VisitFunc = Visit;
	if (!BiTreeEmpty(T))
		InTraverse(T, 0);
	printf("\n");
}

/*************************�ݺ������������T�����Ϊe��������postordertraverse()����************/
void PostTraverse(SqBiTree T, int e)
{
	if (T[2 * e + 1] != Nil)
		PostTraverse(T, 2 * e + 1);
	if (T[2 * e + 2] != Nil)
		PostTraverse(T, 2 * e + 2);
	VisitFunc(T[e]);
}

/******************�������T����ÿ�������ú���Visitһ���ҽ�һ��*****************/
void PostOrderTraverse(SqBiTree T, void(*Visit)(TElemType))
{
	VisitFunc = Visit;
	if (!BiTreeEmpty(T))
		PostTraverse(T, 0);
	printf("\n");
}

/***************��α���������T*************************/
void LevelOrderTraverse(SqBiTree T, void(*Visit)(TElemType))
{
	int i = MAX_TREE_SIZE - 1, j;
	while (T[i] == Nil)
		i--;//�ҵ����һ���ǿս������
	for (j = 0; j <= i; j++)
		if (T[j] != Nil)
			Visit(T[j]);
	printf("\n");
}

/**************************************��㣬������������������************************/
void print(SqBiTree T)
{
	int j, k;
	position p;
	TElemType e;
	for (j = 1; j <= BiTreeDepth(T); j++)//jΪ��ǰ��
	{
		printf("��%d��: ", j);
		p.level = j;
		for (k = 1; k <= pow(2, j - 1); k++)
		{
			p.order = k;//��ǰ������ڱ����˳��
			e = Value(T, p);//�ý���ֵ����e
			if (e != Nil)
				//printf("%d: %c", k, e);//����ڱ����˳��ֵ//�ַ��ͽ��
			printf("  %d  : %d  ", k, e);//����ڱ����˳��ֵ//�ַ��ͽ��
		}
		printf("\n");
	}
}
