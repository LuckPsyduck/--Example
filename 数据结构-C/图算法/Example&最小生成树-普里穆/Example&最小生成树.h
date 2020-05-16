#pragma once
#include"ͼ������.h"

typedef struct
{
	int adjvex;
	VRType lowcost;
}minside[MAX_VERTEX_NUM];

int Minimum(minside SZ, MGraph G)//��SZ.lowcost ����С��ֵ������������SZ���
{
	int i = 0, j, k, min;
	while (!SZ[i].lowcost)//�ҵ���һ����Ϊ0��SZ[i].lowcost
		i++;
	min = SZ[i].lowcost;
	k = i;
	for(j=i+1;j<G.vexnum;j++)//������
		if (SZ[j].lowcost > 0 && SZ[j].lowcost < min)//�ҵ��µĸ�С��ֵ
		{
			min = SZ[j].lowcost;
			k = j;
		}
	return k;
}

void MinSpanTree_PRIM(MGraph G, VertexType u)//��u��������G����С������T
{
	int i, j, k;
	minside closedge;
	k = LocateVex(G, u);//���׵����
	for (j = 0; j < G.vexnum; j++)//���������ʼ��
	{
		closedge[j].adjvex = k;
		closedge[j].lowcost = G.arcs[k][j].adj;
	}
	closedge[k].lowcost = 0;//��ʼ���൱���Լ����Լ����Լ��ľ���

	printf("��С�����������ĸ�����Ϊ:\n");
	for (i = 1; i < G.vexnum; i++)//ѡ��ʣ���G.vexnum-1������
	{
		k = Minimum(closedge, G);//�ҳ���С������T����һ�����
		printf("(%s-%s)\n", G.vexs[closedge[k].adjvex].name, G.vexs[k].name);
		closedge[k].lowcost = 0;//����ֵ�޸ģ��൱���޸ı��
		for(j=0;j<G.vexnum;j++)
			if (G.arcs[k][j].adj < closedge[j].lowcost)//�¶��㲢�������ѡ����С��
			{                                           //���ǽ���һ��������С�������е�Ȩֵ��Ȩֵ�����½������滻��
				closedge[j].adjvex = k;					//�����нϴ��Ȩֵ,���Ǹ�������
				closedge[j].lowcost = G.arcs[k][j].adj;
			}
	}
}