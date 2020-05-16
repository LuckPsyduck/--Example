// �������������ඨ�弰ʵ��2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"BSTree.h"
using namespace std;

TNode<char> *q;

void main()
{
	int i;
	char test[50] = "abxycdMNefgzkl";
	BSTree<char> t(q);

	for (i = 0; test[i] != '\0'; i++)
		t.BSTInsert(q, test[i]);

	cout << "�����������������:\n";
	t.Inorder(q);

	cout << "\n�����������Ľ����=" << t.BSTSize() << endl;
	cout << "�����������Ľ����=" << t.BSTreeCount(q) << endl;
	cout << "���������������=" << t.BSTreeDepth(q) << endl;
	cout << "������������Ҷ�ӽ����=" << t.BSTreeLeafCount(q) << endl;
	cout << "Press any key and delete 'd'\n";
	cin.get();
	t.BSTDelete(q, 'd');

	cout << "�����������������:\n";
	t.Inorder(q);
	cout << "\n�����������Ľ����=" << t.BSTSize() << endl;
	cout << "�����������Ľ����=" << t.BSTreeCount(q) << endl;
	cout << "���������������=" << t.BSTreeDepth(q) << endl;
	cout << "������������Ҷ�ӽ����=" << t.BSTreeLeafCount(q) << endl;
	cin.get();
	t.FreeBST(q);
}


