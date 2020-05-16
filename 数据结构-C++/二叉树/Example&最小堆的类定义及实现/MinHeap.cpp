#include"stdafx.h"
#include "MinHeap.h"
using namespace std;


CMinHeap::CMinHeap(int MaxSize)
{
	if (MaxSize <= 0)
	{
		cerr << "����MaxSize�Ƿ�!\n";
		exit(1);
	}
	heapArray = (ElemType *) new ElemType[MaxSize];
	if (!heapArray)
		exit(-1);
	maxheapSize = HeapSIZE;
	heapsize = 0;
}

void CMinHeap::Destroyheap()
{
	free(heapArray);
}

void CMinHeap::Clearheap()
{
	heapsize = 0;
}

bool CMinHeap::HeapEmpty()
{
	if (heapsize == 0)
		return true;
	else
		return false;
}

bool CMinHeap::HeapFull()
{
	return heapsize == maxheapSize;
}

int CMinHeap::HeapLength()
{
	return heapsize;
}

ElemType CMinHeap::GetTop() //�Ѵ����ҷǿ��򷵻ضѵĶѶ�Ԫ��
{
	if (heapsize == 0)
	{
		cerr << "���ѿ�!\n";
		exit(1);
	}
	return heapArray[0];
}

void CMinHeap::FilterUp()// �����Ķѵ���,ʹ֮������С�ѵĶ���
{
	int c, p;  //�嵽��������һ��λ���ϣ����ӶѴ�С�������ϸ���
	ElemType temp;
	c = heapsize - 1;
	p = (c - 1) / 2;//�Ҹ����//���������� 2n-1,2n  ���ҽ��   �൱����ȫ������
	temp = heapArray[c];
	while (c != 0)//��αȽϺ͸����Ĵ�С
	{
		if (heapArray[p] <= temp)
			break;
		heapArray[c] = heapArray[p];
		c = p;
		p = (c - 1) / 2;
	}
	heapArray[c] = temp;
}

void CMinHeap::FilterDown()	//ɾ����Ķѵ���,ʹ֮������С�ѵĶ���
{						//������ͷԪ��������βԪ�ؽ����滻����С�Ѵ�С�������³���
	int c, p;              
	ElemType temp; //�������£����Ը��ݵ�ǰ��㣬��������ӽ�㣬Ȼ�����ǰ�����бȽϣ�				
	p = 0;				   //	������ҽ��С��������Ҫע����ǣ�ȡ�����ӽ����С�Ľ��н�����
	c = 2 * p + 1;//�ӽ��
	temp = heapArray[p];//�����
	while (c < heapsize)
	{
		if (c + 1 < heapsize&&heapArray[c + 1] < heapArray[c])//���ҽ��
			c = c + 1;
		if (temp <= heapArray[c])//�ٽ���С��������Ƚ�,���н���
			break;
		heapArray[p] = heapArray[c];
		p = c;
		c = 2 * p + 1;
	}
	heapArray[p] = temp;
}

void CMinHeap::HeapInsert(ElemType item)
{
	if (heapsize == HeapSIZE)
	{
		cerr << "������!\n";
		exit(1);
	}
	heapArray[heapsize] = item;
	heapsize++;
	FilterUp();
}

ElemType CMinHeap::HeapDelete()
{
	ElemType temp;
	if (heapsize == 0)
	{
		cerr << "���ѿ�!\n";
		exit(1);
	}
	temp = heapArray[0];
	heapArray[0] = heapArray[heapsize - 1];//��һ��Ԫ����ȥ���൱��ɾ��һ���������µ���
	heapsize--;
	FilterDown();
	return(temp);
}

