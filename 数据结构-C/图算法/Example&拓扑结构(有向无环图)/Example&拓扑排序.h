#pragma once
#include"ͼ�洢�ṹ.h"

void FindInDegree(ALGraph G, int indegree[])//�󶥵׵����
{
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; i++)
		indegree[i] = 0;
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;//Pָ�򶥵���ڽӱ��ͷָ��
		while (p)//p��Ϊ��
		{
			indegree[p->data.adjvex]++;//��p��ָ���ڽӶ�������+1,��ͷ+1
			p = p->nextarc;
		}
	}
}//�����ж������ȶ�������ˣ���ָ��+1

Status TopologicalSort(ALGraph G)
{
	int i, k, count = 0;//�����������
	int indegree[MAX_VERTEXT_NUM];//��ȵ����飬��Ÿ�����ĵ�ǰ���
	SqStack S;
	ArcNode *p;
	FindInDegree(G, indegree);

	InitStack(S);//��ʼ������ȶ����ջS
	for (i = 0; i < G.vexnum; i++)
		if (!indegree[i])//�������Ϊ0
			Push(S, i);
	while (!StackEmpty(S))//���䲻Ϊ��
	{
		Pop(S, i);//��������i
		printf("%s ", G.vertices[i].data.name);
		++count;//������Ķ�����
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)//��i��ÿ���ڽӶ���
		{
			k = p->data.adjvex;//��� 
			if (!(--indegree[k]))//���-1,Ϊ0����ջ
				Push(S, k);
		}
	}
	if (count < G.vexnum)//û����ȫ���
	{
		printf("������ͼ�л�·!\n");
		return ERROR;
	}
	else
	{
		printf("Ϊһ����������!\n");
		return OK;
	}
}