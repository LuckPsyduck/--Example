// ��������2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>

using namespace std;

#define MAXI 11
typedef int KeyType;
typedef int ElemType;

struct rec 
{
	KeyType key;
	ElemType data;
};

typedef rec sqlist[MAXI];

class charu
{
public:
	charu(sqlist a, int m) :n(m)
	{
		for (int i = 1; i<n; i++)//��ʼ��
			b[i] = a[i];
	}

	void insertsort()
	{
		int i, j, k;
		for (i = 2; i<n; i++)//���ֱȽϷ�
		{
			b[0] = b[i];                          //��� ���Ƚϵ�ֵ����b[0]
			j = i - 1;             //�±��i=1��ʼ
			while (b[0].key<b[j].key)//�ӵ�2������ʼ�ڵ�һ�����Ƚϣ�����һ����������ȷ��λ�ã�
			{                   //�ڴӵ�������ʼ��ǰ�����Ƚϣ���������������ȷ��λ��,��������
				b[j + 1] = b[j]; 
				j--;
			}

			b[j + 1] = b[0];
			for (k = 1; k<n; k++)
				cout << setw(4) << b[k].key;
			cout << endl;
		}
	}
	void output()
	{
		for (int i = 1; i<n; i++)
			cout << setw(4) << b[i].key;
		cout << endl;
	}
private:
	sqlist b;
	int n;
};

void main()
{
	sqlist a1; int i, n = MAXI;
	srand((unsigned int)time(0));
	for (i = 1; i<n; i++)
	{
		a1[i].key = rand() % 80;
		a1[i].data = rand() % 100;
	}
	charu px(a1, n);
	cout << "����ǰ����:\n";
	px.output();
	cout << "�������������ʾ:\n";
	px.insertsort();
	cout << "���������:\n";
	px.output();
	cin.get();
}


