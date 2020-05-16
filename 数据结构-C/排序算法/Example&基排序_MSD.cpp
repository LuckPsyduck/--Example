// ������_MSD.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int getdigit(int x, int d)
{
	int a[] = { 1,1,10 };
	return ((x / a[d]) % 10);
}

void PrintArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void MSDdix_sort(int arr[], int begin, int end, int d)
{
	const int radix = 10;
	int count[radix], i, j;
	int *bucket = (int *)malloc((end - begin + 1) * sizeof(int));

	for (i = 0; i < radix; i++)
		count[i] = 0;

	for (i = begin; i <= end; i++)
		count[getdigit(arr[i], d)]++;

	for (i = 1; i < radix; i++)
		count[i] = count[i] + count[i - 1];

	for (i = end; i >= begin; --i)
	{
		j = getdigit(arr[i], d);
		bucket[count[j] - 1] = arr[i];
		--count[j];
	}
	for (i = begin, j = 0; i <= end; ++i, ++j)
		arr[i] = bucket[j];//�����һ���������˳��
	free(bucket);
	for (i = 0; i < radix; i++)
	{
		int p1 = begin + count[i];//��߽�
		int p2 = begin + count[i + 1] - 1;//�ұ߽�
		if (p1 < p2&&d>1)
			MSDdix_sort(arr, p1, p2, d - 1);//����ʣ�µ����
	}
}

int main()
{
	int arr[10] = { 12,14,54,5,6,3,9,8,47,89 };
	cout << "����ǰ:\n";
	PrintArr(arr, 10);
	MSDdix_sort(arr, 0, 9, 2);
	cout << "�����:\n";
	PrintArr(arr, 10);
    return 0;
}

