// ϣ������.cpp : �������̨Ӧ�ó������ڵ㡣
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

class xier
{
public:
	xier(sqlist a, int m) :n(m)
	{
		for (int i = 1; i<n; i++) 
			b[i] = a[i];//��ʼ��
	}

	void shellsort()
	{
		int i, j, gap, k; 
		rec x; 
		gap = n / 2;//����
		while (gap>0)
		{
			for (i = gap + 1; i<n; i++)//����
			{
				j = i - gap;                //���е�����һ��Ԫ��
				while (j>0)
					if (b[j].key>b[j + gap].key)//���е�Ԫ��֮��Ĳ�������
					{
						x = b[j]; 
						b[j] = b[j + gap];
						b[j + gap] = x;
						j = j - gap;
					}
					else 
						j = 0;

					for (k = 1; k<n; k++)
						cout << setw(4) << b[k].key;
					cout << endl;
			}
			gap = gap / 2;//������ //����10��Ԫ�صĻ�����Ϊ 5 2 1
		}// 5���飬ÿ������Ԫ�أ� 2���� ÿ����5��Ԫ�� 1���� 10��Ԫ��
	}

	void output()
	{
		for (int i = 1; i<n; i++)
			cout << setw(4) << b[i].key;
		cout << endl;
	}

private:sqlist b; int n;
};

void main()
{
	sqlist a1; int i, n = MAXI;
	srand((unsigned int)time(0));
	for (i = 1; i<n; i++)
	{
		a1[i].key = rand() % 100;
		a1[i].data = rand() % 80;
	}
	xier px(a1, n);
	cout << "����ǰ����:\n";
	px.output();
	cout << "�������������ʾ:\n";
	px.shellsort();
	cout << "���������:\n";
	px.output(); 
	cin.get();
}



