// ��С�ѵ��ඨ�弰ʵ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"MinHeap.h"
using namespace std;


void PrintArray(int a[], int n)
{
	for (int i = 0; i<n; i++)
		cout << setw(3) << a[i];
	cout << endl;
}
void main()
{
	cout << "minheapm.cpp���н��:\n";
	ElemType b[10];
	srand(350);
	for (int i = 0; i<10; i++)
		b[i] = rand() % 100;
	cout << "�������b:\n";
	PrintArray(b, 10);
	CMinHeap H(10), H1(10);
	for (int i = 0; i<10; i++)
		H.HeapInsert(b[i]);
	cout << "�����ǰ��H�ĶѶ�Ԫ��:\n";
	cout << setw(3) << H.GetTop() << endl;
	cout << "������������b:\n";
	PrintArray(b, 10);
	cout << "������ɾ����H����Ԫ��:\n";
	while (!H.HeapEmpty())
		cout << setw(3) << H.HeapDelete();
	cout << endl;
	for (int i = 0; i<10; i++)
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



