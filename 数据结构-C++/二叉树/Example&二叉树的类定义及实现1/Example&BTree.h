#pragma once
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<strstream>

template<class T>
class CBTree
{
public:
	CBTree() { left = right = NULL; }
	~CBTree();
private:
	CBTree<T> *left;//������ָ��
	CBTree<T> *right;//������ָ��
public:
	T data;//������

	CBTree(T item, CBTree<T> *left1 = NULL, CBTree<T> *right1 = NULL)
		:data(item), left(left1), right(right1) { }

	CBTree<T> *&Left() { return left; }
	CBTree<T> *&Right() { return right; }

	//�����ַ�����a�Ķ��������������Ӧ�Ķ������洢�ṹ
	void CreateBTree(char* a);

	//�ж϶������Ƿ�Ϊ��
	bool BTreeEmpty() { return left == NULL; }

	//����һ�ֱ�����������������е����н��
	void TraverseBTree(int mark);

	//���ڱ����ĵݹ麯��
	void Traverse(CBTree<T> *&BT, int mark);

	//������������
	int BTreeDepth();

	//�������������ȵĵݹ麯��
	int Depth(CBTree<T> *&BT);

	//������������н����
	int BTreeCount();

	//����������������н�����ĵݹ麯��
	int Count(CBTree<T> *&BT);

	//�������������Ҷ�ӽ����
	int BTreeLeafCount();

	//�����������������Ҷ�ӽ�����ĵݹ麯��
	int LeafCount(CBTree<T> *&BT);

	//���ն�������һ�ֱ�ʾ�����������������
	void PrintBTree();

	//������������������ĵݹ麯��
	void Print(CBTree<T> *&BT);

	//��������������ĵݹ麯��
	void Clear(CBTree<T> *&BT);
};

