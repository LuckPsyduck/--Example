/*******************************˫������**********************/
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

struct DuLNode
{
	ElemType data;
	DuLNode *next,*prior;
};
typedef DuLNode *DuLinkList;

/**/
void InitList(DuLinkList &L)
{
	L = (DuLinkList)malloc(sizeof(DuLNode));/*����ͷ��㣬��ʹLָ��ͷ���*/
	if (L)
		L->next = L->prior = L;
	else
		exit(EXIT_FAILURE);
}

//��L����Ϊ��
void ClearList(DuLinkList L)
{
	DuLinkList p=L->next;//pָ���һ�����

	while (p != L)//pδָ��ͷ���
	{
		p = p->next;
		free(p->prior);//�ͷ�p��ǰ�����
	}
	L->next = L->prior=L;//ͷ����ָ�����ָ������
}


//�������Ա�L
void DestroyList(DuLinkList &L)
{
	ClearList(L);
	free(L);//�ͷ�ͷ���
	L = NULL;
}

Status ListEmpty(DuLinkList L)
{
	if (L->next==L&&L->prior==L)
		return true;
	else
		return false;
}

int ListLength(DuLinkList L)
{
	int i = 0;
	DuLinkList p = L->next;//pָ���һ�����
	while (p != L)//pδָ��ͷ���
	{
		i++;
		p = p->next;
	}
	return i;
}
//����i��Ԫ�ش���ʱ����ֵ����e������
Status GetElem(DuLinkList L, int i, ElemType &e)
{
	int j = 1;
	DuLinkList p = L->next;//pָ���һ�����

	while (p != L&&j < i)//ֱ��pָ���һ��Ԫ�ػ�Pָ��ͷ���
	{
		j++;
		p = p->next;
	}
	if (p == L || j > i)
		return ERROR;
	e = p->data;
	return OK;
}
//����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��ŵ�����ڣ��򷵻�0
int LocateElem(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	int i = 0;
	DuLinkList p = L->next;//pָ���һ��Ԫ��
	while (p != L)//pδָ��ͷ���
	{
		i++;
		if (compare(p->data, e))
			return i;
		p = p->next;
	}
	return 0;
}

Status PriorElem(DuLinkList L, ElemType cur_e, ElemType &pre_e)
{
	DuLinkList  p = L->next->next;//pָ��ڶ���Ԫ��

	while (p != L)//pδָ��ͷ���
	{
		if (p->data == cur_e)//p��ָ��ֵΪcur_e�Ľ��
		{
			pre_e = p->prior->data;//��p��ǰ������ֵ����pre_e
			return OK;
		}
		p = p->next;
	}
	return ERROR;//����ʧ��
}
//ŵcur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ��
Status NextElem(DuLinkList L, ElemType cur_e, ElemType &next_e)
{
	DuLinkList p = L->next->next;//pָ��ڶ���Ԫ��
	while (p != L)//pδָ��ͷ���
	{
		if (p->prior->data == cur_e)//p��ָ�Ľ���ǰ����ֵΪcur_e
		{
			next_e = p->data;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

//���ص�i��Ԫ�صĵ�ַ��iΪ0������ͷ���ĵ�ַ
DuLinkList GetElemP(DuLinkList L, int i)
{
	int j;
	DuLinkList p = L;//ָ��ͷ���
	if (i<0 || i>ListLength(L))
		return NULL;
	for (j = 1; j <= i; j++)
		p = p->next;
	return p;
}
//��i��Ԫ��֮ǰ���루1<=i<=length(L)+1��
Status ListInsert(DuLinkList &L, int i, ElemType e)
{
	DuLinkList p , s;

	if (i <1 || i > ListLength(L) + 1)
		return ERROR;
	
	p = GetElemP(L, i - 1);//��L��ȷ����i�����ǰ����λ��ָ��p
	if (!p)
		return ERROR;

	s = (DuLinkList)malloc(sizeof(DuLNode));//�����½��
	s->data = e;
	s->prior = p;//�½���ǰ��Ϊ��i-1�����
	s->next = p->next;//�½��ĺ��Ϊ��i�����
	p->next->prior = s;//��i������ǰ��ָ���½��
	p->next = s;//��i-1�����ĺ��ָ���½��
	return OK;
}
//ɾ����i��Ԫ�أ�����e������ֵ
Status ListDelete(DuLinkList L, int i, ElemType &e)
{
	DuLinkList p ;
	if (i <1)
		return ERROR;
	p = GetElemP(L, i);//ȷ����i��Ԫ�ص�λ��ָ��p
	if (!p)
		return ERROR;
	e = p->data;
	p->prior->next = p->next;//��i-1�����ĺ��ָ��ԭ��i+1�����
	p->next->prior = p->prior;//ԭ��i+1������ǰ��ָ���i-1�����
	free(p);//�ͷŵ�i�����
	return OK;
}

void ListTraverse(DuLinkList L, void(*visit)(ElemType))
{
	DuLinkList p = L->next;//pָ����Ԫ���
	while (p != L)//p��ָ��ͷ���
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}


void ListTraverseBack(DuLinkList L, void(*visit)(ElemType))
{
	DuLinkList p = L->prior;//pָ��β���
	while (p != L)//p��ָ��ͷ���
	{
		visit(p->data);
		p = p->prior;
	}
	printf("\n");
}
