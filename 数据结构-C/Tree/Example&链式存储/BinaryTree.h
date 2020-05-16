/*******************************��������ṹ*******************************/
#include<stdio.h>                  
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ERROR -1
#define OK 1

typedef int Status;
typedef char TElemType;//���Ԫ������

#define Nil ' '                       //char
/*#define Nil 0 */                       //int

typedef struct BiNode
{
	TElemType data;
	BiNode *lchild, *rchild;
}BiTNode,*BiTree;

/*******************��������Ļ�������*************************************/
#define ClearBiTree DestroyBiTree
void InitBiTree(BiTree &T)
{
	T = NULL;
}

void DestroyBiTree(BiTree &T)
{
	if (T)
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
		T = NULL;
	}
}

void PreOrderTraverse(BiTree T, void(Visit)(TElemType))
{
	if (T)
	{
		Visit(T->data);
		PreOrderTraverse(T->lchild,Visit);
		PreOrderTraverse(T->rchild,Visit);
	}
}

void InOrderTraverse(BiTree T, void(Visit)(TElemType))
{
	if (T)
	{
		InOrderTraverse(T->lchild, Visit);
		Visit(T->data);
		InOrderTraverse(T->rchild, Visit);
	}
}

/**************************��������Ļ�������******************************/
Status BiTreeEmpty(BiTree T)
{
	if (T)
		return false;
	else
		return true;
}

int BiTreeDepth(BiTree T)
{
	int i, j;
	if (!T)
		return 0;
	i = BiTreeDepth(T->lchild);
	j = BiTreeDepth(T->rchild);
	return i > j ? i + 1 : j + 1;//���ϸ���һ��
}

TElemType Root(BiTree T)
{
	if (BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

TElemType Value(BiTree p)
{
	return p->data;
}

void Assign(BiTree p, TElemType value)
{
	p->data = value;
}
/**************************������*************************/
typedef BiTree QElemType;

typedef struct QNode
{
	QElemType data;
	QNode *next;
}*QueuePtr;

struct LinkQueue
{
	QueuePtr front, rear;
};


/**************************�����л�������*************************/
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


/******************����������******************/
//���ض�����T��ָ��Ԫ��Ϊs�Ľ���ָ��
BiTree Point(BiTree T, TElemType s)
{
	LinkQueue q;
	QElemType a;
	if (T)
	{
		InitQueue(q);
		EnQueue(q, T);//�����
		while (!QueueEmpty(q))
		{
			DeQueue(q, a);//���ӣ�����Ԫ�ظ���a
			if (a->data == s)
				return a;
			if (a->lchild)
				EnQueue(q, a->lchild);
			if (a->rchild)
				EnQueue(q, a->rchild);
		}
	}
	return NULL;
}
//
TElemType LeftChild(BiTree T, TElemType e)
{
	BiTree a;
	if (T)
	{
		a = Point(T, e);
		if (a&&a->lchild)
			return a->lchild->data;
	}
	return Nil;
}

TElemType RightChild(BiTree T, TElemType e)
{
	BiTree a;
	if (T)
	{
		a = Point(T, e);
		if (a&&a->rchild)
			return a->rchild->data;
	}
	return Nil;
}
//����LRΪ0��1��ɾ��T��p��ָ������������������
Status DeleteChild(BiTree p, int LR)
{
	if (p)
	{
		if (LR == 0)
			ClearBiTree(p->lchild);
		else
			ClearBiTree(p->rchild);
		return OK;
	}
	return ERROR;
}

void PostOrderTraverse(BiTree T, void(Visit)(TElemType))
{
	if (T)
	{
		PostOrderTraverse(T->lchild, Visit);
		PostOrderTraverse(T->rchild, Visit);
		Visit(T->data);
	}
}
//�������
void LevelOrderTraverse(BiTree T, void(*Visit)(TElemType))
{
	LinkQueue q;
	QElemType a;
	if (T)
	{
		InitQueue(q);
		EnQueue(q, T);
		while (!QueueEmpty(q))
		{
			DeQueue(q, a);
			Visit(a->data);
			if (a->lchild != NULL)
				EnQueue(q, a->lchild);
			if (a->rchild != NULL)
				EnQueue(q, a->rchild);
		}
		printf("\n");
	}
}

void CreateBiTree(BiTree &T)
{
	TElemType ch;
	scanf("%c", &ch);//�������ֵ
	if (ch == Nil)
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));//���ɸ����
		if (!T)
			exit(EXIT_FAILURE);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
//��eΪ�Ǹ����ʱ������˫�ף����򷵻ؿ�
TElemType Parent(BiTree T, TElemType e)
{
	LinkQueue q;
	QElemType a;
	if (T)
	{
		InitQueue(q);
		EnQueue(q, T);
		while (!QueueEmpty(q))
		{
			DeQueue(q, a);
			if (a->lchild&&a->lchild->data == e || a->rchild&&a->rchild->data == e)
				return a->data;
			else
			{
				if (a->lchild)
					EnQueue(q, a->lchild);
				if (a->rchild)
					EnQueue(q, a->rchild);
			}
		}
	}
	return Nil;
}

TElemType LeftSibling(BiTree T, TElemType e)
{
	TElemType a;
	BiTree p;
	if (T)
	{
		a = Parent(T, e);
		if (a != Nil)
		{
			p = Point(T, e);
			if (p->lchild&&p->rchild&&p->rchild->data == e)
				return p->lchild->data;
		}
	}
	return Nil;
}
TElemType RightSibling(BiTree T, TElemType e)
{
	TElemType a;
	BiTree p;
	if (T)
	{
		a = Parent(T, e);
		if (a != Nil)
		{
			p = Point(T, e);
			if (p->lchild&&p->rchild&&p->lchild->data == e)
				return p->rchild->data;
		}
	}
	return Nil;
}

Status InsertChild(BiTree p, int LR, BiTree c)
{
	if (p)
	{
		if (LR == 0)//�Ѷ�����c��Ϊp��ָ����������
		{
			c->rchild = p->lchild;//p��ָ����ԭ����������Ϊc��������
			p->lchild = c;//��������Ϊp��������
		}
		else
		{
			c->rchild = p->rchild;//p��ָ����ԭ��������Ϊc��������
			p->rchild = c;//������Ϊp��������
		}
		return OK;
	}
	return ERROR;
}

/*******************˳��ջ*********************/
typedef BiTree SElemType;

#define STACK_INIT_SIZE 10//��ʼ������
#define STACK_INCREMENT 2//��������

struct SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;//�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
};

void InitStack(SqStack &S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(EXIT_FAILURE);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{
	free(S.base);
	S.top = S.base = NULL;
	S.stacksize = 0;
}

Status ClearStack(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}

Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}

int StackLength(SqStack S)
{
	return S.top - S.base;
}
/****************************����ջ��Ԫ��***********************/
Status GetTop(SqStack S, SElemType &e)
{
	if (S.top > S.base)
	{
		e = *(S.top - 1);
		return OK;
	}
	else
		return ERROR;
}

void Push(SqStack &S, SElemType e)
{
	if (S.top - S.base == S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof(SElemType));
		if (!S.base)
			exit(EXIT_FAILURE);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*(S.top)++ = e;
}

Status Pop(SqStack &S, SElemType &e)
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}

void StackTraverse(SqStack S, void(*visit)(SElemType))
{
	while (S.top>S.base)
	{
		visit(*S.base++);
	}
	printf("\n");
}


void InOrderTraverse1(BiTree T, void(*Visit)(TElemType))
{
	SqStack S;
	InitStack(S);
	while (T||!StackEmpty(S))
	{
		if(T)
		{ 
			Push(S, T);
			T = T->lchild;
		}
		else
		{
			Pop(S, T);
			Visit(T->data);
			T = T->rchild;
		}
	}
	printf("\n");
}

void InOrderTraverse2(BiTree T, void(*Visit)(TElemType))
{
	SqStack S;
	BiTree p;
	InitStack(S);
	Push(S, T);

	while (!StackEmpty(S))
	{
		while (GetTop(S,p)&&p)
			Push(S, p->lchild);
		Pop(S, p);
		if (!StackEmpty(S))
		{
			Pop(S, p);
			Visit(p->data);
			Push(S, p->rchild);
		}
	}
	printf("\n");
}