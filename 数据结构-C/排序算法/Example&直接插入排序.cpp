// ֱ�Ӳ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


void insertsort(int *arr, int n)
{
	int j = 0;
	for (int i = 1; i < n; i++)
		if (arr[i] < arr[i - 1])
		{
			int temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
				arr[j + 1] = arr[j];//Ԫ������ƣ�
			arr[j + 1] = temp;//����αȽϵ�Ԫ�����ȷ��λ��
		}
}

int main()
{
	int *arr;
	int n;
	printf("input n:\n");
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int)*n);
	puts("intput arr:");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	insertsort(arr, n);
	puts("sort:");
	for (int i = 0; i < n; i++)
		printf("%d ",arr[i]);

	printf("\n");
    return 0;
}

