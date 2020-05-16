// �۰��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void insertsort(int *arr, int n)
{
	int *temp, temp_n;
	temp = (int *)malloc(sizeof(int)*(n + 1));
	for (size_t i = 0;i < n; i++)
		temp[i + 1] = arr[i];
	temp[0] = 0;
	int i, j, low, high, mid;
	for (i = 2; i <=n; i++)
	{
		temp[0] =temp[i];//arr[0]���ڴ�Ŵ��Ƚϵ�Ԫ��
		low = 1;
		high = i - 1;//�Ƚ�1��i-1��Ԫ��
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (temp[mid] > temp[0])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; --j)
			temp[j + 1] = temp[j];//���ƣ��ճ�����Ԫ�ص�λ��
		temp[high + 1] = temp[0];
	}
	for (size_t i = 1; i <=n; i++)
		arr[i - 1] = temp[i];
}


int main()
{
	int *arr;
	int n;
	printf("input n:\n");
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	puts("intput arr:");
	for (int i = 0; i < n; i++)//��һ��Ԫ��Ϊ0�����ڴ洢���Ƚϵ�Ԫ��
		scanf("%d", &arr[i]);

	insertsort(arr, n);
	puts("sort:");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}

