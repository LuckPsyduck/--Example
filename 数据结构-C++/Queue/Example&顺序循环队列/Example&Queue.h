#pragma once
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define QueueSize 10
typedef int datatype;

class CQueue
{
public:
	CQueue() ;
	~CQueue() {}

private:
	int front;
	int rear;
	int count;
	datatype data[QueueSize];
public:
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

