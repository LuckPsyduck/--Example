#pragma once
#include"ͼ������.h"

typedef Status PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//·������
typedef VRType ShortPathTable[MAX_VERTEX_NUM];//���·����

void ShortestPath_DIJ(MGraph G, int v0,PathMatrix P, ShortPathTable D)
{			//��Dijkstra�㷨��������G�е�v0�����ඥ��v�����·��P[v]����Ȩ����D[v]
			//��P[v][w]ΪTRUE����w�Ǵ�v0��v��ǰ������·���ϵĶ���
			//final[v]ΪTRUE,���ҽ���v����S������ô�v0��v�����·��	
	int v, w, i,j;
	VRType min;
	Status final[MAX_VERTEX_NUM];//��������Ϊ���ʾ�ö��㵽v0����̾����Ѿ��������ֵΪ��

	for (v = 0; v < G.vexnum; ++v)
	{
		final[v] = FALSE;
		D[v] = G.arcs[v0][v].adj;//D[]���v0��v����̾��룬��ֵΪv0��v��ֱ�Ӿ���
		for (w = 0; w < G.vexnum; ++w)
			P[v][w] = FALSE;//p[][]��ֵΪFALSE��û��·��

		if (D[v] < INFINITY)//v0��v��ֱ��·��
			P[v][v0] = P[v][v] = TRUE;
		//һά����p[v][]��ʾԴ��v0��v���·��ͨ���Ķ��㣬Ŀǰͨ��v0��v��������
	}
	D[v0] = 0;//v0��v0�ľ���Ϊ0
	final[v0] = TRUE;//v0����S���൱���޸ı�־
	for (i = 1; i < G.vexnum; ++i)//ÿ�����v0��ĳ������v�����·��������v����S
	{
		min = INFINITY;
		for (w = 0; w < G.vexnum; ++w)
			if (!final[w] && D[w] < min)//��S��֮��Ķ���(��final[]=FALSE)��
			{					//�ҳ���v0����Ķ���w,������ֵ����v�����븳��min
				v = w;
				min = D[w];
			}
		final[v] = TRUE;//v�뼯��S

		for(w=0;w<G.vexnum;++w)//�����²���Ķ��㣬���²���S���еĶ��㵽v0�ľ����·������
			if (!final[w] && min < INFINITY&&G.arcs[v][w].adj < INFINITY && (min + G.arcs[v][w].adj < D[w]))
			{										//w������S����v0-v-w�ľ���<v0-w�ľ���
				D[w] = min + G.arcs[v][w].adj;		//����D[w]
				for (j = 0; j < G.vexnum; j++)
					P[w][j] = P[v][j];		//�޸�P[w],v0��w�����Ķ������v0��v�����Ķ����ټ��϶���w
				P[w][w] = TRUE;				//����·��
			}
	}
}