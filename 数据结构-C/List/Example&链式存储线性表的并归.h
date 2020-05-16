/*******************************���Ա����ʽ��ʾ**********************/
#include<stdio.h>                  
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#define ERROR -1
#define OK 1

#define LIST_INIT_SIZE 10 //��ʼ������
#define LIST_INCREMENT 2 //��������

typedef  int ElemType;
typedef int Status;

struct LNode
{
	ElemType data;
	LNode *next;
};
typedef LNode *LinkList;

/**/
void InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));/*����ͷ��㣬��ʹLָ��ͷ���*/
	if (!L)
		exit(EXIT_FAILURE);
	L->next = NULL;
}
/***************************�������Ա�L*****************************/
void DestroyList(LinkList &L)
{
	LinkList q;
	while (L)
	{
		q = L->next;
		free(L);
		L = q;
	}
}
/*******************************��L����Ϊ��*****************************/
void ClearList(LinkList L)
{
	LinkList p = L->next;//pָ���һ�����
	L->next = NULL;
	DestroyList(p);
}

Status ListEmpty(LinkList L)
{
	if (L->next)
		return false;
	else
		return true;
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}
/**********************����i��Ԫ�ش���ʱ����ֵ����e������*******************/
Status GetElem(LinkList L, int i, ElemType &e)
{
	int j = 1;
	LinkList p = L->next;
	while (p&&j<i)
	{
		j++;
		p = p->next;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	return OK;
}
/*************����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��ŵ�����ڣ��򷵻�0***************/
int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (compare(p->data, e))
			return i;
		p = p->next;
	}
	return 0;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
	LinkList q, p = L->next;
	while (p->next)
	{
		q = p->next;
		if (q->data == cur_e)
		{
			pre_e = p->data;
			return OK;
		}
		p = q;
	}
	return ERROR;//����ʧ��
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
	LinkList p = L->next;
	while (p->next)
	{
		if (p->data == cur_e)
		{
			next_e = p->next->data;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}
/**********************��i��Ԫ��֮ǰ����****************************/
Status ListInsert(LinkList L, int i, ElemType e)
{
	int j = 0;
	LinkList s, p = L;
	while (p&&j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
/******************************ɾ����i��Ԫ�أ�����e������ֵ************/
Status ListDelete(LinkList L, int i, ElemType &e)
{
	int j = 0;
	LinkList q, p = L;
	while (p->next&&j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (!p->next || j > i - 1)
		return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}

void ListTraverse(LinkList L, void(*visit)(ElemType))
{
	LinkList p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}


/*��λ�򣨽����ڱ�ͷ������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L*/

void CreateList(LinkList &L, int n)
{
	int i;
	LinkList p/*, q*/;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	printf("'������%3d������\n", n);
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//�����½��
		scanf("%d", &p->data);
		p->next = L->next;//���½����ڱ�ͷ
		L->next = p;//ͷ���ָ���½��
	}
}

/*��λ�򣨽����ڱ�β������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�*/
void CreateList1(LinkList &L, int n)
{
	int i;
	LinkList p=NULL,q;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	q = L;//qָ��ձ�ͷ��ͷ���
	printf("'������%3d������\n", n);
	for (i = 1; i <= n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		q->next = p;//���½����ڱ�β
		q = q->next;//qָ��β���
	}
	p->next = NULL;//������ָ����Ϊ��
}

/*************�ǵݼ�����****************/

void MergeList(LinkList La, LinkList &Lb, LinkList &Lc)
{
	LinkList pa = La->next, pb = Lb->next, pc;
	Lc = pc = La;//��La��ͷ�����ΪLc��ͷ���
	while (pa&&pb)
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;//pcָ���LC�����һ����㣬�൱��ָ������Lc�����һ��
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;//pcָ���Lc�����һ�����
			pb = pb->next;
		}
	pc->next = pa ? pa : pb;//����ʣ���
	free(Lb);
	Lb = NULL;
}