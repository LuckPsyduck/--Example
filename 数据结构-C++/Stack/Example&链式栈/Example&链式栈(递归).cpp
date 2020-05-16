// ��ʽջ(�ݹ�).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;

class list;
class CListNode {
	friend class CList;
	int data;
	CListNode *link;
	CListNode(int value, CListNode *zz) :data(value), link(zz) {}
};

class CList {
	CListNode *first;

	//�ۼӺ�
	long sum(CListNode *p);

	//������
	long count(CListNode *p);

public:
	CList() :first(NULL) {}

	//����ջ
	void add(int value);

	//��ʾջ������
	void display();

	//��ȡ�ۼӺ�
	long get_sum() { return sum(first); }

	//��ȡ���ݸ���
	long get_count() { return count(first); }

	//��ƽ��
	float get_avg()
	{
		return (float)sum(first) / count(first);
	}
};

void CList::add(int value) 
{
	CListNode *p = new CListNode(value, first);
	if (p != NULL) 
		first = p;
	else 
		cerr << "Memory Error!" << endl;
}

void CList::display() 
{
	cout << "������ĸ���ֵ:";
	for (CListNode *p = first; p != NULL; p = p->link)
		cout << setw(2) << p->data;
	cout << endl;
}

long CList::sum(CListNode *p) {
	if (p->link == NULL)
		return p->data;
	else 
		return
		p->data + sum(p->link);//����
}

long CList::count(CListNode *p) 
{
	long n = 1;
	if (p->link == NULL)
	{ 
		return 1;
	}
	else
	{ 
		return count(p->link) + n; 
	}
}

void main()
{
	cout << "Recurve.cpp���н��:\n";
	CList a;
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	a.display();
	cout << "�ۼӺ�sum=" << a.get_sum() << endl;
	cout << "���ݸ���count=" << a.get_count() << endl;
	cout << "ƽ��ֵavg=" << a.get_avg() << endl;
	cin.get();
}


