// ѡ������2.cpp : �������̨Ӧ�ó������ڵ㡣
//�Ӻ���ǰ��ѡ����󣬴δ�......

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define N 10

void gensort(int b[], int n)
{
	int i, j, k;
	for (i = 1; i<n; i++)//�Ƚ�n-1��
	{
		k = n - i;
		for (j = n - i - 1; j >= 0; j--)//�Ӻ���ǰ
			if (b[k]<b[j])
				k = j;//ѡ������
		if (k != n - i)
		{
			int temp = b[k];
			b[k] = b[n - i]; 
			b[n - i] = temp;
		}
		for (int m = 0; m<N; m++)
			cout << setw(4) << b[m]; cout << endl;
	}
}

//ѡ�����򷨲���
void main()
{
	int ai[N], i;
	srand(time(0));
	for (i = 0; i<N; i++)
		ai[i] = rand() % 100;
	cout << "����ǰ����:\n";
	for (i = 0; i<N; i++)
		cout << setw(4) << ai[i];
	cout << endl << "���������ʾ:\n";
	gensort(ai, sizeof(ai) / sizeof(int));
	cout << "���������:\n";
	for (i = 0; i<N; i++)
		cout << setw(4) << ai[i];
	cout << endl; 
	cin.get();
}


