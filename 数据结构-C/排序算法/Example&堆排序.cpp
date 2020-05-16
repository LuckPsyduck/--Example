// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
using namespace std;
//�󶥶�(���Ϊ����)�����Һ��ӵ�ֵС�ڸ��׽�㣩
//��ȫ�������Ľṹ
void HeapAdjust(int *arr, int i, int size)//������
{
	int lchild = 2 * i;
	int rchild = 2 * i + 1;
	int max = i;
	if (i <= size / 2)//��Ҷ�ӵĽ��
	{
		if (lchild <= size&&arr[lchild] > arr[max])
			max = lchild;
		if (rchild <= size&&arr[rchild] > arr[max])
			max = rchild;
		if (max != i)
		{
			swap(arr[i], arr[max]);
			HeapAdjust(arr, max, size);//ʹ��maxΪ˫�׽�������Ϊ��
		}
	}
}

void BulidHeap(int *arr, int size)
{
	int i;
	for (i = size / 2; i >= 1; i--)//�ǽ���������Ϊsize/2
		HeapAdjust(arr, i, size);//������Ϊ��λ���е���,��������
}

void HeapSort(int *arr, int size)
{
	int i;
	BulidHeap(arr, size);
	for (i = size; i >= 1; i--)
	{
		swap(arr[1], arr[i]);//�����Ѷ������һ��Ԫ�أ�����ɾ�������Ԫ�طŵ����
		HeapAdjust(arr, 1, i - 1);//���µ�Ԫ�����½���Ϊ�󶥶�
	}
}

int main()
{
	int n, *arr;
	printf("input n:\n");
	cin >> n;
	arr = (int *)malloc(sizeof(int)*n);
	printf("input arr:\n");
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	HeapSort(arr, n);
	puts("sort:");
	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";
	printf("\n");
	return 0;
}

