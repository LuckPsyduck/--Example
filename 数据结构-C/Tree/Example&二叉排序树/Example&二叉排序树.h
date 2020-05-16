/****************************��̬�����*****(����������)***********************/
/*ͨ���������������ͺ��򣩱����������������Ϳ���ȷ����������������̬*/
#include<stdio.h>
#include<stdlib.h>

#define ERROR -1
#define OK 1

typedef int Status;


/****************************��ֵ�Ƚϵ�Լ��*******************************/
#define EQ(a,b)((a)==(b))
#define LT(a,b)((a)<(b))
#define LQ(a,b)((a)<=(b))
/*************************************************************************/

/*******************���Ļ�������**************************/
typedef int KeyType;

struct ElemType
{
	KeyType key;
	int others;
};

typedef struct BiTNode
{
	ElemType data;
	BiTNode *lchild, *rchild;
}BiTNode,* BiTree;

/***********�����������������������ͬ�Ĳ�������***********/
#define InitDSTable InitBiTree
#define DestroyDSTable DestroyBiTree
#define TraverseDSTable InOrderTraverse//����һ��

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
//���ؼ���˳�����������������ƽ�����������������������Ĳ�����ͬ
void InOrderTraverse(BiTree T, void(*Visit)(ElemType))
{
	if (T)
	{
		InOrderTraverse(T->lchild, Visit);
		Visit(T->data);
		InOrderTraverse(T->rchild, Visit);
	}
}
//�ݹ���ҹؼ���Ϊkey������Ԫ��
BiTree SearchBST(BiTree T, KeyType key)
{
	if (!T || EQ(key, T->data.key))
		return T;
	else if LT(key, T->data.key)
		return SearchBST(T->lchild, key);
	else
		return SearchBST(T->rchild, key);
}

//ȷ��������̬
void PostOrderTraverse(BiTree T, void (*Visit)(ElemType e))
{
	if (T)
	{
		Visit(T->data);
		PostOrderTraverse(T->lchild, Visit);
		PostOrderTraverse(T->rchild, Visit);
	}
}


/********************�����������Ļ�������*************************/
/*
�ڸ�ָ��T��ָ�����������еݹ�����Ĳ�����ؼ��ֵ���key������Ԫ�أ�ŵ���ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE������ָ��\
pָ�����·���Ϸ��ʵ����һ�����,������FALSE ��ָ��fָ��T��˫�ף����ʼֵΪnull��
*/
Status SearchBST(BiTree &T, KeyType key,BiTree f,BiTree &p)
{
	if (!T)
	{
		p = f;//pָ�����·�������һ�����
		return false;
	}
	else if EQ(key, T->data.key)
	{
		p = T;//pָ������Ԫ�صĽ��
		return true;
	}
	else if LT(key, T->data.key)
		return SearchBST(T->lchild, key, T, p);
	else
		return SearchBST(T->rchild, key, T, p);
}
//ŵ��������û�йؼ��ֵ���Key�ģ�����벢����TRUE�����򷵻�FALSE
Status InsertBST(BiTree &T, ElemType e)
{
	BiTree p, s;
	if (!SearchBST(T, e.key, NULL, p))//pָ�����·���Ϸ��ʵ����һ��Ҷ�ӽ��(pΪҶ�ӽ�㣬����Ҫ)
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!p)
			T = s;//������Ľ��Ϊ���ڵ�
		else if LT(e.key, p->data.key)
			p->lchild = s;//������Ľ��Ϊp��ָ��������
		else
			p->rchild = s;
		return true;
	}
	else
		return false;
}
//�Ӷ�����������ɾ��P��ָ�Ľ�㣬���ؽ��������������
void Delete(BiTree &p)
{
	BiTree s, q = p;//qָ���ɾ�����
	if (!p->rchild)
	{
		p = p->lchild;//ֱ�Ӽ̳�
		free(p);
	}
	else if (!p->lchild)
	{
		p = p->rchild;//ֱ�Ӽ̳�
		free(p);
	}
	else//��������������
	{
		s = p->lchild;//sָ���ɾ����������
		while (s->rchild)//�ҵ�����,����ɾ������ǰ��(������������ʣ����ڶ���������������С����)
		{
			q = s;//qָ�����ɾ�����ǰ����˫��
			s = s->rchild;
		}
		p->data = s->data;//�滻Ԫ�ص�ֵ��ֱ������ӽ���ֵ�滻��ֱ��ǰ����ֱ�Ӻ�̣���
		if (q != p)//��ɾ������������������Ϊ�գ���������������
			q->rchild = s->lchild;
		else//��ɾ����������������Ϊ�գ�������û��������(q p�غ�)
			q->lchild = s->lchild;
		free(s);
	}
}
//ŵ����������T�д��ڹؼ��ֵ���Key������Ԫ��ʱ����ɾ��������Ԫ�صĽ�㣬������TRUE�����򷵻�FALSE
Status DeleteBST(BiTree &T, KeyType key)
{
	if (!T)
		return false;
	else
	{
		if EQ(key, T->data.key)
			Delete(T);//ɾ���ý��(�ص�)
		else if LT(key, T->data.key)
			DeleteBST(T->lchild, key);
		else
			DeleteBST(T->rchild, key);
		return true;
	}
}

/************************����Ԫ�����ͻ�������*************************/
void Visit(ElemType c)
{
	printf("(%d,%d)", c.key, c.others);
}

void InputFromFile(FILE *f, ElemType &c)
{
	fscanf(f, "%d%d", &c.key, &c.others);
}

void InputKey(KeyType &k)
{
	scanf("%d", &k);
}