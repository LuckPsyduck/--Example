#include "stdafx.h"
#include "MaxHeap.h"

using namespace std;

CMaxHeap::CMaxHeap(int MaxSize)
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

void CMaxHeap::Destroyheap()
{
	free(heapArray);
}

void CMaxHeap::Clearheap()
{
	heapsize = 0;
}

bool CMaxHeap::HeapEmpty()
{
	if (heapsize == 0) 
		return true;
	else 
		return false;
}

bool CMaxHeap::HeapFull()
{
	return heapsize == maxheapSize;
}

int CMaxHeap::HeapLength()
{
	return heapsize;
}

ElemType CMaxHeap::GetTop()
{
	if (heapsize == 0)
	{
		cerr << "���ѿ�!\n"; 
		exit(1);
	}
	return heapArray[0];
}

void CMaxHeap::FilterUp()//�������ϣ����Ը��ݵ�ǰ��㣬������׽�㣬Ȼ������׽����бȽϣ�									
{								//����ӽ��С�Ļ�������Ҫ�����໥��������֮���ã�ֱ��ѭ�����±굽���β��
	int c, p;
	ElemType temp;
	c = heapsize - 1;
	p = (c - 1) / 2;
	temp = heapArray[c];
	while (c != 0)
	{
		if (heapArray[p]>temp)//���򽻻�
			break;
		heapArray[c] = heapArray[p];
		c = p;
		p = (c - 1) / 2;
	}
	heapArray[c] = temp;
}

void CMaxHeap::FilterDown()//���ݵ�ǰ��㣬��������ӽ�㣬Ȼ�����ǰ�����бȽϣ�������ҽ��С��
{	 //������Ҫע����ǣ�ȡ�����ӽ����С�Ľ��н�������Ϊ���б�Ȼ��������֮�е���Сֵ����֮���ã�ֱ��ѭ�����±굽��0
	int c, p;
	ElemType temp;
	p = 0;
	c = 2 * p + 1;
	temp = heapArray[p];
	while (c<heapsize)
	{
		if (c + 1<heapsize&&heapArray[c + 1]>heapArray[c])//�ҳ�������ıȽ�
			c = c + 1;
		if (temp>heapArray[c])//���븸�׽��Ƚ�
			break;
		heapArray[p] = heapArray[c];
		p = c;
		c = 2 * p + 1;
	}
	heapArray[p] = temp;
}

void CMaxHeap::HeapInsert(ElemType item)
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

ElemType CMaxHeap::HeapDelete()
{
	ElemType temp;
	if (heapsize == 0)
	{
		cerr << "���ѿ�!\n";
		exit(1);
	}
	temp = heapArray[0];
	heapArray[0] = heapArray[heapsize - 1];
	heapsize--;
	FilterDown();
	return(temp);
}

