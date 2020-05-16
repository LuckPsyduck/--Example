// ϣ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;

void shell(int *arr, int n)
{
	int i, j, x, d;
	d = n / 2;                      //ÿ�ε����ıȽϼ��
	while (d>=1)                    //����ѭ��
	{
		for (i = d + 1; i <= n; i++)
		{
			x = arr[i];
			j = i - d;
			while ((j>0)&&(x< arr[j]))
			{
				arr[j + d] = arr[j];//��ֵ���Ԫ��
				j -= d;
			}
			arr[j + d] = x;//��ֵС��Ԫ��
		}
		d /= 2;//��һ���Ƚϼ��
	}
}
/*
static void shell_sort(int unsorted[] , int len)
{
	int group, i, j, temp;
	for (group = len / 2; group > 0; group /= 2)
	{
		for (i = group; i < len; i++)
		{
			for (j = i - group; j >= 0; j -= group)
			{
				if (unsorted[j] > unsorted[j + group])
				{
					temp = unsorted[j];
					unsorted[j] = unsorted[j + group];
					unsorted[j + group] = temp;
				}
			}
		}
	}
}
*/
int main()
{
	int n, *arr;
	cout << "input n:" << endl;
	cin >> n;
	arr = (int *)malloc(sizeof(int)*n);
	cout << "input arr:\n";
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	shell(arr, n);
	cout << "sort :" << endl;
	for (size_t i = 1; i <= n; i++)
		cout << arr[i] << " ";
	cout << endl;
    return 0;
}

