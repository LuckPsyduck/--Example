// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void sort(int *arr, int left, int right)
{
	int i, j, temp;
	if (left < right)
	{ 
		i = left;
		j = right;
		temp = arr[left];
		while (i<j)
		{
			while (arr[j] >= temp&&j > i)//�ȴ����ұ�������ҵ�һ��С��temp��ֵ�����߽���
				j--;
			if (j > i)
				arr[i++] = arr[j];
			while (arr[i] <= temp&&j > i)//������߿�ʼ���Ҳ��ҵ�һ������temp��ֵ�����߽���
				i++;
			if (j > i)
				arr[j--] = arr[i];
		}//���Ͻ�����С
		arr[i] = temp;
		sort(arr, left, i - 1);
		sort(arr, i + 1, right);
	}
}

int main()
{
	int n, *arr;
	printf("input n:\n");
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	printf("input arr:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr,0,n-1);
	puts("sort:");
	for (int i = 0; i <n; i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}

