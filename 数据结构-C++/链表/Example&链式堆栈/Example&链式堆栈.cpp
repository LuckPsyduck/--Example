// ��ʽ��ջ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"LinkStack.h"
using namespace std;

void main()
{
	cout << "linearStack2m.cpp���н��:\n";
	int m, n;
	CLinkStack q, p, w;
	cout << "��������������������n:"; 
	cin >> n;
	cout << "����������ջq�ĳ���m:"; 
	cin >> m;
	cout << "����ջq(����):\n";
	q.CreateStack(n, m, 1);

	cout << "qջ�Ľ�����=" << q.StackSize() << endl;
	cout << "���qջԪ��:\n";
	q.StackPrint(m); 
	cout << endl;
	cout << "qջ:";
	if (q.StackFull(m) == 1)
		cout << "����!\n";
	else
		cout << "δ��!\n";
	cout << "����ջp(����):\n";
	p.CreateStack(n + 10, m, -1);
	cout << "pջ:";

	if (p.StackFull(m) == 1)
		cout << "����!\n";
	else 
		cout << "δ��!\n";
	cout << "ɾ��Ԫ��Ϊ:" << p.Pop() << endl;
	cout << "pջ:";

	if (p.StackEmpty() == 1)
		cout << "Ϊ��!\n";
	else 
		cout << "Ϊ�ǿ�!\n";
	cout << "���pջԪ��:\n";
	p.StackPrint(m - 1);
	cout << endl;
	cout << "����ջw(����):\n";
	w.CreateStack(2 * n, m);
	cout << "���wջԪ��:\n";
	w.StackPrint(m); 
	cout << endl;
	p.ClearStack();
	p.DeleteStack();
	cin.get(); 
	cin.get();
}
