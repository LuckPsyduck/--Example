// ���ֲ���(�ݹ����).cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

double a[10] = { 1.1,1.3,1.5,1.7,1.9,2.1,2.3,2.5,2.7,2.9 };//����

void binsrch(int s, int r, double x)
{
	int m;
	m = (s + r) / 2;
	
	if (s > r)
	{
		cout << x << "��������δ�ҵ�!\n";
		exit(-1);
	}
	else if (a[m] == x)
		cout << x << "���������ҵ�!\n";
	else if (x > a[m])
		binsrch(m + 1, r, x);
	else
		binsrch(s, m - 1, x);
}

void main()
{
	double x;
	int s = 0, r = 9;
	cout << "����x:"; 
	cin >> x;
	cout << "���ҽ��:\n";
	binsrch(s, r, x);
}




