// ͨ��ѡ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define N 10

typedef bool(*isgreat)(void *this_num, void *next_num);

void gensort(void *base, int n, int elemsize, isgreat great)
{
	int i, j, k;
	for (i = 0; i<n - 1; i++)//���ֱȽϷ���0��Ԫ����������е�Ԫ�رȽϣ�ѡ����С�ģ�
	{													//Ȼ����һ��Ԫ����֮���Ԫ�رȽϣ�ѡ����С�ģ�ֱ�����һ��
		k = i; //���Ƚ�Ԫ��
		char *this_num = (char *)base + k*elemsize;
		char *that = this_num;

		for (j = i + 1; j<n; j++)
		{
			char *next_num = (char *)base + j*elemsize;
			if (great(that, next_num)) 
				that = next_num;//that Ϊ��ʱ�Ƚϵ���СԪ��
		}
		if (this_num != that)//����СԪ�ز��ǵ�ǰ���Ƚϵ�Ԫ�أ��򽻻�����
		{
			for (int k = 0; k<elemsize; k++)
			{
				char temp = this_num[k];
				this_num[k] = that[k];
				that[k] = temp;
			}
		}
	}
}

bool greatint(void *first, void *second)
{
	return (*(int *)first>*(int *)second);//ǿ������ת�������Ͻ����������
}

bool greatdouble(void *first, void *second)
{
	return (*(double *)first>*(double *)second);
}

//ͨ��ѡ�����򷨲���
void main()
{
	int ai[N], i;
	srand(time(0));
	for (i = 0; i<N; i++)
		ai[i] = rand() % 100;
	cout << "����ǰ����:\n";
	for (i = 0; i<N; i++)
		cout << setw(4) << ai[i]; cout << endl;
	gensort(ai, sizeof(ai) / sizeof(int), sizeof(int), greatint);
	cout << "���������:\n";
	for (i = 0; i<N; i++)
		cout << setw(4) << ai[i]; cout << endl;
	double bf[N];
	for (i = 0; i<N; i++)
		bf[i] = rand() / 200.0;
	cout << setiosflags(ios::fixed);//��λ��ָ���������ڹ̶�ʮ������ʽ��ʾ
	cout << "����ǰ����:\n";
	for (i = 0; i<N; i++)
		cout << setprecision(2) << setw(7) << bf[i]; 
	cout << endl;

	gensort(bf, sizeof(bf) / sizeof(double), sizeof(double), greatdouble);
	cout << "���������:\n";
	for (i = 0; i<N; i++)
		cout << setprecision(2) << setw(7) << bf[i];//����
	cout << endl; cin.get();
}






