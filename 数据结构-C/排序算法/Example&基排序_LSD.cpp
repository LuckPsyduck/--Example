// ������_LSD.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int getdigit(int x, int d)//ȡ������λ
{
	int a[] = { 1,1,10,100 };//��0λ��Ԫ��û��
	return (x / a[d]) % 10;
}

void PrintArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void LSDdix_sort(int arr[], int begin, int end, int d)
{
	const int radix = 10;
	int count[radix], i, j;
	int *bucket = (int *)malloc((end - begin + 1) * sizeof(int));

	for (int k = 1; k <= d; k++)
	{
		for (i = 0; i < radix; i++)
			count[i] = 0;

		for (i = begin; i <= end; i++)
			count[getdigit(arr[i], k)]++;//����Ͱ�е����ĸ���

//count[1]��count[9],count[1]�����ΪͰ0��Ͱ1��Ԫ�ظ���,��������
		for (i = 1; i < radix; i++)
			count[i] = count[i] + count[i - 1];

		for (i = end; i >= begin; --i)
		{
			j = getdigit(arr[i], k);//����ؼ���ĵ�kλ�����֣�
			bucket[count[j] - 1] = arr[i];//count[j]Ϊj�洢�����һ��Ԫ�ش�С��count[j]-1,��Ϊ���Դ洢j���ֵ����һ��λ�ã�
			--count[j];////��ӦͰ��װ������������һ �����ν�Ԫ����ǰ�洢
		}
		for (i = begin, j = 0; i <= end; ++i, ++j)
			arr[i] = bucket[j];////�Ӹ���Ͱ���ռ�����
	}
	free(bucket);
}

int main()
{
	int br[10] = { 20,80,90,589,998,965,852,123,456,789 };
	cout << "ԭ��������:" << endl;
	PrintArr(br, 10);
	LSDdix_sort(br, 0, 9, 3);
	cout << "�������������:" << endl;
	PrintArr(br, 10);
    return 0;
}

