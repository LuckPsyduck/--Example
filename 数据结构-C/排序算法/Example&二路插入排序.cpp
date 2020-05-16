#include<stdio.h>
#include<stdlib.h>
/*
С����С��ŵ���ǰ�档���������ŵ�����棬����֮�䣬���۰����
*/

void insert_sort(int *arr, int *temp, int n)
{
	int i, first, final, k;
	first = final = 0;
	temp[0] = arr[0];
	for (i = 1; i < n; i++)
	{
		if (arr[i] < temp[first])
		{
			first = (first - 1 + n) % n;//first ǰ��
			temp[first] = arr[i];//�ŵ���ǰ��
		}
		else if(arr[i]>temp[final])
		{
			final = (final + 1 + n) % n;//final����
			temp[final] = arr[i];//�ŵ������
		}
		else//��first��final֮��
		{
			k = (final + 1 + n) % n;//���һ������һλ
			while (temp[(k - 1 + n) % n] > arr[i])//�ɺ���ǰ�Һ��ʵ�λ��
			{
				temp[(k + n) % n] = temp[(k - 1 + n) % n];//���ƣ�Ϊ������׼��
				k = (k - 1 + n) % n;
			}
			temp[(k + n) % n] = arr[i];//����
			final = (final + 1 + n) % n;//�������һλλ��
		}
	}
	for (k = 0; k < n; k++)//���ص�arr������
		arr[k] = temp[(first + k) % n];
}

void main()
{
	int i, n, *arr,*temp;
	printf("input n:\n");
	while (scanf("%d", &n) == 1)
	{
		arr = (int*)malloc(sizeof(int)*n);
		temp = (int *)malloc(sizeof(int)*n);
		printf("arr:\n");
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		insert_sort(arr, temp, n);
		puts("after sort:");
		for (i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
		free(arr);
		free(temp);
	}
}