// ��·ƽ��鲢(�����ļ�).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Sort.h"

void main()
{
	int n, i;
	char *fa = ".\\fa1.dat";
	srand(time(0));
	fstream fna(fa, ios::in | ios::out | ios::binary);
	cout << "�����n:"; 
	cin >> n;
	cout << "�ļ�δ����ǰ�Ľ��:\n";
	LoadFile myfile(fa, n);
	myfile.Print(fna);
	if (n % 2 == 0)
	{
		myfile.FMergeSort(fna, 2);
		for (i = 2; i <= n / 2; i++)
		{
			myfile.FMergeSort(fna, 2 * i - 1);
			myfile.FMergeSort(fna, 2 * i);
		}
		myfile.FMergeSort(fna, n / 2);
	}
	else
	{
		myfile.FMergeSort(fna, 2);
		for (i = 2; i <= n / 2; i++)
		{
			myfile.FMergeSort(fna, 2 * i - 1);
			myfile.FMergeSort(fna, 2 * i);
		}
		myfile.FMergeSort(fna, n / 2 + 1);
	}
	cout << "�ļ������Ľ��:\n";
	myfile.Print(fna); 
	fna.close();
}

