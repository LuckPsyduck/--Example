// ����ƥ����.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "Stack.h"

void main()
{
	CStack *p;
	int n, m , q = 0;
	char ch, ca, cd;
	cout << "���н��:\n";
	cout << "�������ŵĸ���m: ";
	cin >> m;
	cout << "���������ַ�����:";
	p->InitStack(&p);
	for (n = 1; n<m; n++)
	{
		cin >> ch;
		if (ch == '[') 
			p->Push(ch);

		if (ch == '(')
			p->Push(ch);

		if (ch == '{')
			p->Push(ch);

		if (ch == ']')
		{
			ca = p->Pop(&cd);
			if (ca == '[') 
				cout << ca << "��" << ch << "��ƥ���!\n";
			else
			{
				cout << ca << "��" << ch << "����ƥ���!\n"; 
				q++;
			}
		}
		if (ch == ')')
		{
			ca = p->Pop(&cd);
			if (ca == '(') 
				cout << ca << "��" << ch << "��ƥ���!\n";
			else
			{
				cout << ca << "��" << ch << "����ƥ���!\n";
				q++;
			}
		}
		if (ch == '}')
		{
			ca = p->Pop(&cd);
			if (ca == '{') 
				cout << ca << "��" << ch << "��ƥ���!\n";
			else
			{
				cout << ca << "��" << ch << "����ƥ���!\n";
				q++;
			}
		}
		if (p->StackEmpty()) 
			break;
	}
	if (q >= 1) 
		cout << "�κ����в�ƥ��!\n";
	else 
		cout << "�κ�����ƥ��!\n";
	cin.get(); 
	cin.get();
}










