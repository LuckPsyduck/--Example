// �鲢����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;

void merge(int *arr, int start, int mid, int last)
{
	int i, j, k;
	int *arr1 = (int *)malloc(sizeof(int)*(mid - start + 1));
	int *arr2= (int *)malloc(sizeof(int)*(last-mid));

	for (i = 0; i < mid - start + 1; i++)
		arr1[i] = arr[start + i];
	for (i = 0; i < last - mid; i++)
		arr2[i] = arr[i + mid + 1];

	i = j = 0;
	k = start;
	while (i<(mid-start+1)&&j<(last-mid))
	{
		if (arr1[i] < arr2[j])
			arr[k++] = arr1[i++];
		else
			arr[k++] = arr2[j++];
	}
	//ʣ���Ԫ�غϲ�
	while (i < mid - start + 1)
		arr[k++] = arr1[i++];
	while (j < last - mid)
		arr[k++] = arr2[j++];
	free(arr1);
	free(arr2);
}

void mergesort(int *arr, int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start + end) / 2;//�ֽ�����

		mergesort(arr, start,mid);//ǰһ��ݹ�����,�ӷֽ�Ϊ��С��Ԫ��ʼ�Ƚ�
		mergesort(arr, mid + 1, end);//��һ��ݹ�����

		merge(arr, start, mid, end);//�����ֺϲ�
	}
}

int main()
{
	int n, *arr;
	printf("input n:\n");
	cin >> n;
	arr = (int *)malloc(sizeof(int)*n);
	printf("input arr:\n");
	for (int i = 0; i <n; i++)
		cin >> arr[i];


	mergesort(arr, 0, n-1);
	puts("sort:");
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	printf("\n");
	return 0;
}



