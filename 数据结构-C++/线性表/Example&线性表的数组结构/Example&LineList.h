#pragma once

#include<malloc.h>
#include<string.h>
#include<iostream>
#include<iomanip>

#define MaxListSize 20
#define EQUAL 1

typedef struct STU
{
	char name[10];
	char stuno[10];
	int age;
	int score;
}ElemType;

class CLineList
{
public:
	CLineList();
	~CLineList();
private:
	//���Ա�������ʾ
	ElemType elem[MaxListSize];
	int length;
	int MaxSize;
public:
	//��ʼ��˳���
	void init(CLineList **L, int ms);
	//ɾ��˳���
	void DestroyList(CLineList &L) { free(&L); }
	//��˳�����Ϊ�ձ�
	void ClearList() { length = 0; }
	//�ж�˳����Ƿ�Ϊ�ձ�
	bool ListEmpty()
	{
		return length == 0;
	}
	//�ж�˳����Ƿ�Ϊ��
	bool ListFull()
	{
		return length == MaxSize;
	}
	//�������ر���Ԫ��pre_e��ǰ��
	ElemType PriorElem(ElemType cur_e, ElemType &pre_e);
	// �������ر���Ԫ��next_e�ĺ��
	ElemType NextElem(ElemType cur_e, ElemType &next_e);
	//�����Ա���ɾ����ͷ����β����ڸ���ֵ��Ԫ��
	bool ListDelete(int, ElemType &e);
	//����˳���
	void ListTraverse();
	//����˳���ĳ���
	int ListLength();
	// ��ȡ˳����е�i ��Ԫ��
	void GetElem(int, ElemType *);
	// �ж�˳�����Ԫ���Ƿ����
	bool EqualList(ElemType *, ElemType *);
	// �ж�˳�����Ԫ���Ƿ񲻵�
	bool Less_EqualList(ElemType *, ElemType *);
	//˳���Ĳ����㷨
	bool LocateElem(ElemType, int);
	//�������Ա��еĸ���Ԫ��
	bool UpdateList(ElemType& e, ElemType);
	//˳���ĺϲ��㷨
	void MergeList(CLineList *, CLineList *);
	//˳���Ĳ����㷨
	bool ListInsert(int, ElemType &);
	//˳���������㷨
	void UnionList(CLineList *, CLineList *);
	//�����Ա�����������
	void printlist(int);
};

