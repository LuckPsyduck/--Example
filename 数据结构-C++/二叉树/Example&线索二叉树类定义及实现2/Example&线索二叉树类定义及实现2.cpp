// �����������ඨ�弰ʵ��2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include"TBSTree.h"

using namespace std;
void main()
{
	THNode<char> *q, *p;
	TBSTree<char> t;

	q = t.MakeCharT(q, 2);
	cout << "���������������������������Ϊ:\n";
	t.InThread(q);
	t.ThInorder(q);
	TBSTree<char> d;
	p = d.MakeCharT(p, 1);
	cout << "\n���������������������������Ϊ:\n";
	d.InThread(p);
	d.ThInorder(p);
	cout << endl;
}











