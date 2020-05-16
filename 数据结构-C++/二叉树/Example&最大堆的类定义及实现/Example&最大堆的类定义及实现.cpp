// ���ѵ��ඨ�弰ʵ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"MaxHeap.h"

using namespace std;

void PrintArray(int a[], int n)
{
	for (int i = 0; i<n; i++)
		cout << setw(3) << a[i];
	cout << endl;
}

void main()
{
	cout << "maxheapm.cpp���н��:\n";
	ElemType b[HeapSIZE];
	srand(350);
	for (int i = 0; i<HeapSIZE; i++)
		b[i] = rand() % 100;
	cout << "�������b:\n";
	PrintArray(b, HeapSIZE);

	CMaxHeap H(HeapSIZE), H1(HeapSIZE);
	for (int i = 0; i<HeapSIZE; i++)
		H.HeapInsert(b[i]);

	cout << "�����ǰ��H�ĶѶ�Ԫ��:\n";
	cout << setw(3) << H.GetTop() << endl;

	cout << "������������b:\n";
	PrintArray(b, HeapSIZE);

	cout << "������ɾ����H����Ԫ��:\n";
	while (!H.HeapEmpty())
		cout << setw(3) << H.HeapDelete();
	cout << endl;

	for (int i = 0; i<HeapSIZE; i++)
		H1.HeapInsert(rand() % 100);

	cout << "�����ǰ��H1�ĶѶ�Ԫ��:\n";
	cout << setw(3) << H1.GetTop() << endl;

	cout << "������ɾ����H1����Ԫ��:\n";
	while (!H1.HeapEmpty())
		cout << setw(3) << H1.HeapDelete();
	cout << endl;

	H.Destroyheap(); 
	H1.Destroyheap();
}


