// ð�ݷ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void sort(int *arr, int n)
{
	for (int i = 0; i<n - 1; i++)
	{
		int temp = 0;
		for (int j = i + 1; j < n; j++)//ÿ�ν���С���ŵ���ǰ
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	}
}

int main()
{
	int n,*arr;
	printf("input n:\n");
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	printf("input arr:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, n);
	puts("sort:");
	for (int i = 0; i <n; i++)
		printf("%d ", arr[i]);
	printf("\n");
    return 0;
}

