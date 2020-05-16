// ��������1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int N = 10;
class jishu
{
public:
	jishu(int d[], int s) :n(s)
	{
		for (int i = 0; i<n; i++)
			A[i] = d[i];
	}
	void output()
	{
		for (int i = 0; i<n; i++)
			cout << setw(4) << A[i];
		cout << endl;
	}
	void radix(int B[], int k, int r, int cnt[])//�ɵ�λ����λ
	{
		int j;
		for (int i = 0, rtok = 1; i<k; i++, rtok *= r)
		{
			for (j = 0; j<r; j++) //��ʼ��
				cnt[j] = 0;

			for (j = 0; j<n; j++) 
				cnt[(A[j] / rtok) % r]++;//ͬλ��ͬ��Ԫ�ظ���

			for (j = 1; j<r; j++) 
				cnt[j] = cnt[j - 1] + cnt[j];//��ӦλԪ�ش洢�������е�λ��

			for (j = n - 1; j >= 0; j--)
				B[--cnt[(A[j] / rtok) % r]] = A[j];//��������,���뵽B

			for (j = 0; j<n; j++)
				A[j] = B[j];//����A ������һ�ֵ�����
			output();
		}
	}
private:int A[N], n;
};
void main()
{
	int a[N], b[N], c[N], i, k = 3;
	srand(time(0));
	for (i = 0; i<N; i++)
	{
		a[i] = rand() % 1000;//��λ���Ļ�������
		b[i] = 0;
	}
	jishu jx(a, N);
	cout << "����ǰ����a:\n";
	jx.output();
	cout << "��������Ĺ�����ʾ:\n";
	jx.radix(b, k, 10, c);
	cout << "���������a:\n";
	jx.output(); 
	cin.get();
}









