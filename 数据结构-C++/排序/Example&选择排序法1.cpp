// ѡ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define N 10

void gensort(int b[], int n)//���ֱȽϷ�
{
	int i, j, k;
	for (i = 0; i<n - 1; i++)
	{
		k = i;
		for (j = i + 1; j<n; j++)
			if (b[k]>b[j])
				k = j;
		if (k != i)
		{
			int temp = b[k];
			b[k] = b[i]; 
			b[i] = temp;
		}
	}
}

//ѡ�����򷨲���
void main()
{
	int ai[N], i;
	srand(time(0));// rand �������ɵ�α�������
	for (i = 0; i<N; i++)
		ai[i] = rand() % 100;
	cout << "����ǰ����:\n";
	for (i = 0; i<N; i++)
		cout << setw(4) << ai[i];
	cout << endl;
	gensort(ai, sizeof(ai) / sizeof(int));
	cout << "���������:\n";
	for (i = 0; i<N; i++)
		cout << setw(4) << ai[i];
	cout << endl; cin.get();
}



