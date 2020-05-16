// ���������ඨ�弰ʵ��1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "BTree.h"

using namespace std;

void main()
{
	cout << "btreeM.cpp���н��:\n";
	int n;
	char b[80] = "(a)(b),c(d),e(f),g(h),i(j),k(l),m(n),o@";
	BTree<char> B;
	cout << "�����Ķ�����Ϊ:\n";
	B.CreateBTree(b); 
	cout << endl;
	if (!B.BTreeEmpty())
		cout << "�������ǿ�!\n";
	else
		cout << "������Ϊ��!\n";
	cout << "�������������:\n";
	B.TraverseBTree(1); 
	cout << endl;
	cout << "�������������:\n";
	B.TraverseBTree(2);
	cout << endl;
	cout << "�������������:\n";
	B.TraverseBTree(3); 
	cout << endl;
	cout << "�������������:\n";
	B.TraverseBTree(4); 
	cout << endl;
	n = B.BTreeDepth();
	cout << "�����������=" << n << endl;
	n = B.BTreeCount();
	cout << "�����������н����=" << n << endl;
	n = B.BTreeLeafCount();
	cout << "������������Ҷ�ӽ����=" << n << endl;
	cout << "���������Ĺ�������:\n(";
	B.PrintBTree(); 
	cout << ')' << endl;
	cin.get();
}



