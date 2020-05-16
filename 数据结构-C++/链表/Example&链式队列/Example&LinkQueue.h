#pragma once
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<malloc.h>

#define QueueSize 10
typedef int datatype;

//�����е����Ͷ���Ϊһ���ṹ���ͣ�
typedef struct QueueNode
{
	datatype  data;
	struct QueueNode *next;
}queuenode;

class CLinkQueue
{
private:
	queuenode  *front;//����ͷָ��.
	queuenode  *rear; //����βָ��.
	int count;// ���н�����
public:
	//���캯��
	CLinkQueue()
	{
		front = rear = NULL; 
		count = 0;
	}

	//��������
	~CLinkQueue() 
	{ 
		front = rear = NULL; 
	}

	// �ж϶ӿ�
	int queueempty();

	// �ж϶���
	int queuefull();

	// ���(���еĲ���)
	void enqueue(datatype);

	// ����(���е�ɾ��)
	datatype dequeue();

	// ȡ���е�ͷԪ��
	datatype queuefront();

	//����еĳ���(�����е�Ԫ�ظ���)
	int QueueLength();
};

