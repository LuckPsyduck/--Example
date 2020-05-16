#include "stdafx.h"
#include "PQueue.h"

// �ж϶ӿ�
int PQueue::PQueueEmpty()
{
  return count==0;
}

// �ж϶���
int PQueue::PQueuefull()
{
  return count==MaxSize;
}

//���ع�ϵ�����С��<
int operator <(datatype &b,datatype &c)//��������ĳ�Ա����//�Զ���
 {
	return b.priority<c.priority;
}

//���еĲ���
void PQueue::InsertPQ(datatype x)
{
	if(PQueuefull())
    {
		cerr<<"������.\n";
		exit(1);
	}
  data[count]=x;
   count++;
 }

//���е�ɾ��
datatype PQueue::DeQueue()
{
	if(PQueueEmpty())
    {
		cerr<<"���п�.\n";
		exit(1);
	}
  datatype min=data[0];
  int minindex=0;
  for(int i=0;i<count;i++)
	 if(data[i]<min)//���ȼ�,ɾ�����ȼ��͵�//�������ص�С�ں�
	  {
		  min=data[i];
		  minindex=i;
	  }
  data[minindex]=data[count-1];//���ǣ�ɾ��
  count--;
  return min;
 }

// ȡ���е�ͷԪ��
datatype PQueue::PQueuefront()
{
	if(PQueueEmpty())
   {
		cerr<<"���п�.\n";
		exit(1);
   }
  datatype min=data[0];
  for(int i=1;i<count;i++)
   if(data[i]<min)//���ȼ��͵�
    min=data[i];
  return min;
 }

//����е�Ԫ�ظ���
int PQueue::PQueueSize()
{
	return count;
}



