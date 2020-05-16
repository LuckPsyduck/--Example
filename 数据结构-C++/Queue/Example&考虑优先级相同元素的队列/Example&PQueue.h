#pragma once
//�������ȼ���ͬԪ�ص��Ƚ��ȳ�
//�����˳�����ȼ������ඨ��
#include<fstream>
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define MaxSize 6
typedef struct Datatype
{
	int taskNo;
	int priority;
}datatype;

class PQueue
{
public:
	PQueue() { count = 0; }
	~PQueue() {}
private:
	datatype data[MaxSize];
	int count;
public:

	//���ع�ϵ�����С��<
	friend int operator <(datatype &, datatype &);

	//��ն���
	void ClearPq() { count = 0; }

	// �ж϶ӿ�
	int PQueueEmpty();

	// �ж϶���
	int PQueuefull();

	// ���еĲ���
	void InsertPQ(datatype);

	// ���е�ɾ��
	datatype DeQueue();

	// ȡ���е�ͷԪ��
	datatype PQueuefront();

	//����е�Ԫ�ظ���
	int PQueueSize();
};

