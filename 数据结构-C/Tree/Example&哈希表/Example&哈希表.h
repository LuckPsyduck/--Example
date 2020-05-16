#pragma once

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int m;
typedef int KeyType;
typedef int Status;

#define EQ(a,b)((a)==(b))
#define LT(a,b)((a)<(b))
#define LQ(a,b)((a)<=(b))

struct ElemType
{
	KeyType key;
	int order;
};

int hashsize[] = { 11,19,29,37 };
struct HashTable
{
	ElemType *elem;//��̬��������
	int count;//��ǰԪ�ظ���
	int sizeindex;//hashsize[]������
};
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
#define NULL_KEY 0
#define OK 1
#define ERROR 0
void InitHashTable(HashTable &H)
{
	int i;
	H.count = 0;
	H.sizeindex = 0;
	m = hashsize[0];//��ϣ��ı�
	H.elem = (ElemType *)malloc(m * sizeof(ElemType));
	if (!H.elem)
		exit(EXIT_FAILURE);
	for (i = 0; i < m; i++)
		H.elem[i].key = NULL_KEY;//δ���¼�ı�־
}

void DestroyHashTable(HashTable &H)
{
	free(H.elem);
	H.elem = NULL;
	H.count = 0;
	H.sizeindex = 0;
}

unsigned Hash(KeyType K)//��ϣ����
{
	return K % m;
}

int d(int i)//�������к���
{
	return i;//����̽����ɢ��
	/*return ((i + 1) / 2)*((i + 1) / 2)*(int)pow(-1, i - 1);
	return rand();*/
}

void collision(KeyType K, int &p, int i)//���Ŷ�ַ��������
{
	p = (Hash(K) + d(i)) % m;
}

Status SearchHash(HashTable H, int K, int &p, int &c)
{
	p = Hash(K);//pָʾ����λ��
	while (H.elem[p].key!=NULL&&!EQ(K,H.elem[p].key))
	{
		c++;//��¼��ͻ����
		if (c < m)//��H���п����ҵ������ַ���޸�
			collision(K, p, c);//�����һ̽���ַp
		else
			break;
	}
	if EQ(K, H.elem[p].key)
		return SUCCESS;
	else
		return UNSUCCESS;
}

void RecreateHashTable(HashTable &);
//���Ҳ��ɹ�ʱ��������Ԫ��e�����Ŷ�ַ��ϣ��H�У�
//ŵ��ͻ�����������ؽ���ϣ ��
Status InsertHash(HashTable &H, ElemType e)
{
	int p, c = 0;
	if (SearchHash(H, e.key, p, c))
		return DUPLICATE;
	else if (c < hashsize[H.sizeindex] / 2)//δ�ҵ�����ͻ����Ҳcδ�ﵽ����
	{
		H.elem[p] = e;
		++H.count;
		return OK;
	}
	else//δ�ҵ�������ͻ����c�Ѵﵽ����
	{
		RecreateHashTable(H);
		return UNSUCCESS;
	}
}

void RecreateHashTable(HashTable &H)
{
	int i, count = H.count;
	ElemType *p, *elem = (ElemType *)malloc(count * sizeof(ElemType));
	p = elem;
	for (int i = 0; i < m; i++)
		if ((H.elem + i)->key != NULL_KEY)
			*p++ = *(H.elem + i);
	H.count = 0;
	H.sizeindex++;//����洢����Ϊ��һ��������
	m = hashsize[H.sizeindex];
	H.elem = (ElemType *)realloc(H.elem, m * sizeof(ElemType));
	for (i = 0; i < m; i++)
		H.elem[i].key = NULL_KEY;
	for (p = elem; p < elem + count; p++)//��ԭ�е����ݰ����µı����뵽�ؽ��Ĺ�ϣ����
		InsertHash(H, *p);
	free(elem);
}

void TraverseHash(HashTable H, void(*Visit)(int, ElemType))
{
	int i;
	printf("��ϣ��ַ0-%d\n", m - 1);
	for (i = 0; i < m; i++)
		if (H.elem[i].key != NULL_KEY)
			Visit(i, H.elem[i]);
}