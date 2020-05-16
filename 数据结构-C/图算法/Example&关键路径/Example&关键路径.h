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


Status TopologicalOrder(ALGraph &G, SqStack &T)//TWΪ�������ж���ջ��SΪ����ȶ���ջ
{
	int i, k, count = 0;//����ջ����������ֵΪ0
	int indegree[MAX_VERTEXT_NUM];//��Ÿ����㵱ǰ�����
	SqStack S;
	ArcNode *p;
	FindInDegree(G, indegree);
	InitStack(S);
	printf("��������: ");
	for (i = 0; i < G.vexnum; i++)
		if (!indegree[i])
			Push(S, i);//��i������ȶ���ջ
	InitStack(T);
	for (i = 0; i < G.vexnum; i++)//��ʼ��ve=0
		G.vertices[i].data.ve = 0;
	while (!StackEmpty(S))//������ȶ���ջS����
	{
		Pop(S, i);
		Visit(G.vertices[i].data);
		Push(T, i);//j�Ŷ���������������ջT(ջ��Ԫ��Ϊ��������ĵ�1��Ԫ��)
		++count;
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{
			k = p->data.adjvex;//���Ϊk
			if (--indegree[k] == 0)
				Push(S, k);
			//����i�¼������緢��ʱ��+<i,k>��Ȩֵ>����k�¼������緢��ʱ��
			if (G.vertices[i].data.ve + p->data.info->weight > G.vertices[k].data.ve)
				G.vertices[k].data.ve = G.vertices[i].data.ve + p->data.info->weight;
			//k�¼������緢����ʱ��=i�¼������緢����ʱ��+<i,k>��Ȩֵ
		}
	}
	if (count < G.vexnum)
	{
		printf("��ʱ�������л�·!\n");
		return ERROR;
	}
	else
		return OK;
}

Status CriticalPath(ALGraph &G)//�������ؼ��
{
	SqStack T;
	int i, k, j;
	ArcNode *p;
	if (!TopologicalOrder(G, T))//��������
		return ERROR;
	j = G.vertices[0].data.ve;

	for (i = 1; i < G.vexnum; i++)//��ve����ֵ��Ȼ��������������õ�vl
		if (G.vertices[i].data.ve > j)
			j = G.vertices[i].data.ve;

	for (i = 0; i < G.vexnum; i++)
		G.vertices[i].data.vl = j;
	while (!StackEmpty(T))//������������������v1��ֵ
		for (Pop(T, j), p = G.vertices[j].firstarc; p; p = p->nextarc)
		{//����ջT��Ԫ�أ�����j,pָ�򶥵�j�ĺ���¼�(����)����k
			k = p->data.adjvex;//����¼���������
			if (G.vertices[k].data.vl - p->data.info->weight < G.vertices[j].data.vl)
				//�¼�j����ٷ���ʱ��>��ֱ�Ӻ���¼�k����ٷ���ʱ��-<j,k>��Ȩֵ
				G.vertices[j].data.vl = G.vertices[k].data.vl - p->data.info->weight;//�������
			//�¼�j����ٷ���ʱ��=�¼�k����ٷ���ʱ��-<j,k>��Ȩֵ
			//����k�����������򣬹�G.vertices[k].data.v1���ڸı�
		}
	printf("\ni  ve  vl\n");
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%d", i);
		Visitel(G.vertices[i].data);//���ve,vl
		if (G.vertices[i].data.ve == G.vertices[i].data.vl)//���緢����ʱ��=��ٷ�����ʱ��
			printf("�ؼ�·�������Ķ���:");
		printf("\n");
	}

	printf("j  k  Ȩֵ  ee  el\n");//��ee,el�͹ؼ��
	for(j=0;j<G.vexnum;++j)
		for (p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->data.adjvex;
			p->data.info->ee = G.vertices[j].data.ve;//ee=��β��ve//���翪ʼʱ��

			p->data.info->el = G.vertices[k].data.vl - p->data.info->weight;//el=��ͷ����ٿ�ʼʱ��-���ߵ�Ȩֵ

			printf("%s--%s", G.vertices[j].data.name, G.vertices[k].data.name);
			OutputArcel(p->data.info);
			if (p->data.info->ee == p->data.info->el)
				printf("�ؼ��!");
			puts("\n");
		}
	return OK;
}