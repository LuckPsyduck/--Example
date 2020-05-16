/*******************************���Ա��˳���ʾ**********************/
#include<stdio.h>                  
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#define ERROR -1
#define OK 1

typedef  int ElemType;
typedef int Status;

/***********************���Ա�Ķ�̬����˳��洢�ṹ*********************************/
#define LIST_INIT_SIZE 10 //��ʼ������
#define LIST_INCREMENT 2 //��������
struct SqList
{
	ElemType *elem;//�洢�ռ�Ļ�ַ
	int length;//��ǰ����
	int listsize;//��ǰ����Ĵ洢����(sizeof(ElemType)Ϊ��λ)
};
/*************************************************************************************/

/****************˳��洢�����Ա�Ļ�������********************************/
void InitList(SqList &L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(EXIT_FAILURE);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}
void DestroyList(SqList &L)
{
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
}
//����Ϊ��
void ClearList(SqList &L)
{
	L.length = 0;
}

Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return true;
	else
		return false;
}

int ListLength(SqList L)
{
	return L.length;
}
//��e���ص�i��Ԫ�ص�ֵ��1<=i<=Listlength(L)��
Status GetElem(SqList L, int i, ElemType &e)
{
	if (i<1 || i>L.length)
		return ERROR;
	e = *(L.elem + i - 1);
	return OK;
}
//����L�е�һ����e�����ϵcompare����������Ԫ��λ��
int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	int i = 1;
	ElemType *p = L.elem;
	while (i < L.length && !compare(*p++, e))
		++i;
	if (i <= L.length)
		return i;
	else
		return 0;
}
//��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
	int i = 2;
	ElemType *p = L.elem + 1;
	while (i <= L.length&&*p != cur_e)
	{
		p++;
		i++;
	}
	if (i > L.length)
		return ERROR;
	else
	{
		pre_e = *--p;
		return OK;
	}
}

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
	int i = 1;
	ElemType *p = L.elem;
	while (i < L.length && *p != cur_e)
	{
		p++;
		i++;
	}
	if (i == L.length)
		return ERROR;
	else
	{
		next_e = *++p;
		return OK;
	}
}
//��L�е�i��λ��֮ǰ�����µ�Ԫ��e,L�ĳ��ȼ�1��1<=i<=ListLength(L)+1)
Status ListInsert(SqList &L, int i, ElemType e)
{
	ElemType *newbase, *q, *p;
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length == L.listsize)
	{
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(EXIT_FAILURE);
		L.elem = newbase;
		L.listsize += LIST_INCREMENT;
	}
	q = L.elem + i - 1;
	for (p = L.elem + L.length - 1; p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}
//ɾ����i��Ԫ��
Status ListDelete(SqList &L, int i, ElemType &e)
{
	ElemType *p, *q;
	if (i<1 || i>L.length)
		return ERROR;
	p = L.elem + i - 1;
	e = *p;
	q = L.elem + L.length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	L.length--;
	return OK;
}
//��ÿ��Ԫ�ص���visit()
void ListTraverse(SqList L, void(*visit)(ElemType))
{
	ElemType *p = L.elem;
	int i;
	for (i = 1; i <= L.length; i++)
		visit(*p++);
	printf("\n");
}
/*************************************************************************************/