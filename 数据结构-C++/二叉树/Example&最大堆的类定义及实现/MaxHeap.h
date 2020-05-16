#pragma once

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>

typedef int ElemType;

#define HeapSIZE 10
#define MaxHeapSize 100

class CMaxHeap
{
private:
	ElemType *heapArray;
	int maxheapSize;
	int heapsize;
public:

	//����һ���ն�S
	CMaxHeap(int);

	//�Ѵ�����ѱ�����
	void Destroyheap();

	//�Ѵ�������Ϊ�ն�
	void Clearheap();

	//�ѿ��򷵻�true,����false
	bool HeapEmpty();

	//�����򷵻�true,����false
	bool HeapFull();

	// �Ѵ����򷵻ضѵ�Ԫ�ظ���,���ѵĳ���
	int HeapLength();

	//�Ѵ����ҷǿ��򷵻ضѵĶѶ�Ԫ��
	ElemType GetTop();

	// �����Ķѵ���,ʹ֮�������ѵĶ���
	void FilterUp();

	//ɾ����Ķѵ���,ʹ֮�������ѵĶ���
	void FilterDown();

	//�Ѳ���
	void HeapInsert(ElemType item);

	//��ɾ��
	ElemType HeapDelete();
};

