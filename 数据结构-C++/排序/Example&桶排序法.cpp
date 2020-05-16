// Ͱ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

//��Ͱ��������鳤��
const int SIZE = 12;

void bucketSort(int[]);
void distributeElements(int[], int[][SIZE], int);
void collectElements(int[], int[][SIZE]);
int numberOfDigits(int[], int);
void zeroBucket(int[][SIZE]);

void main()
{
	int array[SIZE];
	cout << "ԭ����:\n";
	srand(/*(unsigned int)*/static_cast<unsigned int>(time(0)));
	for (int i = 0; i<SIZE; ++i)
	{
		array[i] = rand() % 100;
		cout << setw(3) << array[i];
	}
	cout << '\n';
	cout << "���������ʾ:\n";
	bucketSort(array);
	cout << "���������:\n";
	for (int j = 0; j<SIZE; ++j)
		cout << setw(3) << array[j];
	cout << endl; cin.get();
}

// Ͱ�����㷨
void bucketSort(int a[])
{
	int totalDigits, bucket[10][SIZE] = { 0 };
	totalDigits = numberOfDigits(a, SIZE);      //�����������λ��
	for (int i = 1; i <= totalDigits; ++i) //��Ҫ����Ĵ�����ÿ�θ���
	{
		distributeElements(a, bucket, i);
		collectElements(a, bucket);
		//��Ͱ�����ʼ��Ϊ0
		if (i != totalDigits) 
			zeroBucket(bucket);
		for (int j = 0; j<SIZE; ++j)
			cout << setw(3) << a[j];
		cout << endl;
	}
}

//ȷ�����±�������������λ��
int numberOfDigits(int b[], int arraySize)
{
	int largest = b[0], digits = 0;
	for (int i = 1; i<arraySize; ++i)
		if (b[i]>largest)
			largest = b[i];

	while (largest != 0) 
	{
		++digits;
		largest /= 10;
	}
	return digits;
}

// �����±������ÿ��ֵ�ŵ�Ͱ���������//���ߵ�λ�����迴digit����ֵ
void distributeElements(int a[], int buckets[][SIZE], int digit)//���δ�ú󣬰���λ�źã��ڰ���һλ���е���,��������
{																//���λΪ��λ�����ż��Σ����һ�����ź�
	int divisor = 10, bucketNumber, elementNumber;
	for (int i = 1; i<digit; ++i)
		divisor *= 10;
	for (int k = 0; k<SIZE; ++k)
	{
		bucketNumber = (a[k] % divisor - a[k] % (divisor / 10)) / (divisor / 10);//ȡ�����λ
		elementNumber = ++buckets[bucketNumber][0];//��λ��ͬ��Ԫ�صĸ���
		buckets[bucketNumber][elementNumber] = a[k];//���δ�����ӦͰ��������
	}
}

//��Ͱ�����ֵ���ƻ�ԭ����
void collectElements(int a[], int buckets[][SIZE])
{
	int subscript = 0;
	for (int i = 0; i<10; ++i)
		for (int j = 1; j <= buckets[i][0]; ++j)
			a[subscript++] = buckets[i][j];
}

//��Ͱ�����ʼ��Ϊ0
void zeroBucket(int buckets[][SIZE])
{
	for (int i = 0; i<10; ++i)
		for (int j = 0; j<SIZE; ++j)
			buckets[i][j] = 0;
}



