#pragma once

#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

#define LEN 30
//����ElemTypeΪint
typedef int ElemType;

//�������н�������
typedef struct LNode {
	ElemType data;//ֵ��
	LNode *next;  //ָ����
}LNode;

class CLinkList
{
	LNode *head;
public:
	//�����βι��캯��
	CLinkList();

	//��һ���βι��캯��
	CLinkList(int);

	//�������βι��캯��,n�ǳ�ʼ��Ԫ�ظ���,m�ǻ�
	//����,mark=0������,mark>0����,mark<0����
	CLinkList(int n, int m, int mark = 0);

	//���ƹ��캯��
	CLinkList(CLinkList& HL);

	//��������
	~CLinkList();

	//��յ�����
	void ClearList();

	//��������
	int ListSize();

	//��鵥�����Ƿ�Ϊ��
	bool ListEmpty();

	//���ص�������ָ����ŵĽ��ֵ
	ElemType GetElem(int pos);

	//����������
	void TraverseList(void f(ElemType &));

	//�ӵ������в���Ԫ��
	bool FindList(ElemType& item);

	//���µ������еĸ���Ԫ��
	bool UpdateList(const ElemType& item, ElemType e);

	//���������Ԫ��,mark=0���ڱ���,������ڱ�β
	void InsertList(ElemType item, int mark);

	//�ӵ�������ɾ��Ԫ�� , markΪҪɾ���ĵڼ���Ԫ��
	bool DeleteList(ElemType& item, int mark);

	//�Ե���������������� mark>0����,������
	void pailie(int mark = 1);//Sort

	//������la ��lb ��Ԫ�ذ�ֵ�ǵݼ�����,����������
	//�ϲ��������Ҳ��һ�������
	void MergeList_L(CLinkList &la, CLinkList &lb);

	//�Ե���������������,mark=0������,mark>0����,mark<0����
	void OrderOutputList(int mark = 0);
};

