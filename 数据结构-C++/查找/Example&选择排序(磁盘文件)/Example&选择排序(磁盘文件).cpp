// ѡ������(�����ļ�).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Sort.h"

void main()
{
	int m = 10;
	ElemType d[10];
	char *fa = ".\\fa1.dat";
	srand(time(0));
	fstream fna(fa, ios::out | ios::in | ios::binary | ios::trunc);
	cout << "�ļ�δ����ǰ�Ľ��:\n";
	LoadFile myfile(fa, m);
	myfile.Print(fna);
	cout << "�ļ������Ľ��:\n";
	myfile.FMergeSort(fna, d, m);
	myfile.Print(fna);
	fna.close(); 
	cin.get();
}
