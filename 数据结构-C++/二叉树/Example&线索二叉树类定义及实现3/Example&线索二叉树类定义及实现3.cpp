// �����������ඨ�弰ʵ��3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//��������������ز����Ĳ���TBSTree2M.cpp
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include"TBSTree.h"
#include"ITBSTree.h"
using namespace std;

void main()
{
	THNode<char> *q, *p;
	q = MakeCharT(q, 2);
	ITBSTree<char> t(q);
	t.CreatInThread();
	cout << "�����������������������Ϊ:\n";
	t.First();
	cout << "\n���������������������Ϊ:\n";
	t.Last();
	p = MakeCharT(p, 1);

	ITBSTree<char> d(p);
	d.CreatInThread();
	cout << "\n�����������������������Ϊ:\n";
	d.First();
	cout << "\n���������������������Ϊ:\n";
	d.Last();
	cout << endl;
}












