// ��ѡ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void sort(int *arr, int n)
{
	int i, j, k,temp;
	for (i = 0; i < n; i++)
	{
		temp = arr[i];//���Ƚ�Ԫ��
		k = i;
		for(j=i+1;j<n;j++)
			if (arr[j]<temp)
			{
				temp = arr[j];//��Сֵ
				k = j;//��Сֵ������
			}
		if (i != k)//�����Сֵ����Ƚϵ�ֵ�����
		{
			temp = arr[i];
			arr[i] = arr[k];//���ΰ�˳���ŷ���Сֵ
			arr[k] = temp;
		}
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

	sort(arr,n);
	puts("sort:");
	for (int i = 0; i <n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

