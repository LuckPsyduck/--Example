#include "stdafx.h"
#include"Queue.h"

//���캯��
CQueue::CQueue()
{
	front = rear = count = 0;
}

// �ж϶ӿ�
int CQueue::queueempty()
{
	return count == 0;
}

// �ж϶���
int CQueue::queuefull()
{
	return count == QueueSize;
}

// ���(���еĲ���)
void CQueue::enqueue(datatype x)//�ڶ����в���һԪ��eΪQ���¶�βԪ��
{
	if (queuefull())
		printf("������.\n");
	count++;
	data[rear] = x;
	rear = (rear + 1) % QueueSize;
	//rearָ�����
}

// ����(���е�ɾ��)
datatype CQueue::dequeue()//�����в�����ɾ������ͷ��Ԫ�ز���e������ֵ
{
	datatype temp;
	if (queueempty())
		printf("���п�.\n");
	temp = data[front];
	count--;
	//frontָ�����
	front = (front + 1) % QueueSize;
	return temp;
}

// ȡ���е�ͷԪ��
datatype CQueue::queuefront()
{
	if (queueempty())
		printf("���п�.\n");
	return data[front];
}

//����еĳ���(�����е�Ԫ�ظ���)
int CQueue::QueueLength()
{
	return count;
}



