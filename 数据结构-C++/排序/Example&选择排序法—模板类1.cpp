// ѡ�����򷨡�ģ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"// ���򲻸ı�ԭ�����Ԫ�ص�ֵ
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

#define M 10

template<class T>
void sortp(T d[], T *pd[], int b[], int size)
{
	int i, j, k;
	for (i = 0; i < size - 1; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
			if (d[b[k]]>d[b[j]])//b[kl]��������Ԫ�ص��±�
				k = j;
		if (i != k)
		{
			T g; 
			g = b[i]; 
			b[i] = b[k]; 
			b[k] = g;
		}
	}
	for (i = 0; i<size; i++) 
		pd[i] = &d[b[i]];
}

void main()
{
	int q[M], *p[M], a[M], n = M, i;
	srand(time(0));
	for (i = 0; i<n; i++)
		q[i] = rand() % 100;
	for (i = 0; i<n; i++)
	{ 
		a[i] = i;//ֻ�����±�
		p[i] = &q[i];
	}
	cout << "����ǰ����:\n";
	for (i = 0; i<n; i++)
		cout << setw(4) << q[i];
	cout << endl << "�����ԭ����:\n";
	sortp(q, p, a, n);
	for (i = 0; i<n; i++)
		cout << setw(4) << q[i];
	cout << endl << "���������:\n";
	for (i = 0; i<n; i++)
		cout << setw(4) << *p[i];
	cout << endl;
	float w[M], *t[M];
	cout << setiosflags(ios::fixed);
	for (i = 0; i<n; i++) 
		w[i] = rand() / 100.0;
	for (i = 0; i<n; i++)
	{
		a[i] = i;
		t[i] = &w[i];
	}

	cout << "����ǰ����:\n";
	for (i = 0; i<n; i++)
		cout << setprecision(2) << setw(7) << w[i];
	cout << endl << "�����ԭ����:\n";
	sortp(w, t, a, n);
	for (i = 0; i<n; i++)
		cout << setprecision(2) << setw(7) << w[i];
	cout << endl << "���������:\n";
	for (i = 0; i<n; i++)
		cout << setprecision(2) << setw(7) << *t[i];
	cout << endl;
	cin.get();
}

