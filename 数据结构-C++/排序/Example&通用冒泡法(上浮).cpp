// ͨ��ð�ݷ�(�ϸ�).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define N 10

void gensort(int b[], int n)
{
	int i, j;
	for (i = 0; i<n - 1; i++)//ÿ��ѡ��С�ķ���ǰ��
	{
		for (j = i + 1; j<n; j++)
			if (b[i]>b[j])
			{
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		for (int k = 0; k<n; k++)
			cout << setw(4) << b[k];
		cout << endl;
	}
}

void main()
{
	int ai[N], i;
	srand(time(0));
	for (i = 0; i<N; i++)
		ai[i] = rand() % 100;
	cout << "����ǰ����:\n";
	for (i = 0; i<N; i++)
		cout << setw(4) << ai[i];
	cout << endl;
	cout << "���������ʾ:\n";
	gensort(ai, sizeof(ai) / sizeof(int));
	cout << "���������:\n";
	for (i = 0; i<N; i++)
		cout << setw(4) << ai[i];
	cout << endl;
	cin.get();
}








