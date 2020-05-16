#pragma once
#include"ͼ������.h"

typedef char PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef VRType DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

void ShortestPath_FLOYD(MGraph G, PathMatrix P, DistancMatrix D)
{//��Floyd�㷨��������G�и��Զ���v��w֮������·��P[v][w][]�����Ȩ����D[v][w]
	//P[v][w][u]ΪTRUE����u�Ǵ�v��w��ǰ������·���ϵĶ���
	int u, v, w, i;
	for(v=0;v<G.vexnum;v++)
		for (w = 0; w < G.vexnum; w++)
		{
			D[v][w] = G.arcs[v][w].adj;//����v��w��ֱ�Ӿ���
			for (u = 0; u < G.vexnum; u++)
				P[v][w][u] = FALSE;//·����ʼ����
			if (D[v][w] < INFINITY)//��v��w��ֱ�Ӿ���
				P[v][w][v] = P[v][w][w] = TRUE;//��v��w��·������v��w����
		}//�������·���Ѿ�������v,w����

	for(u=0;u<G.vexnum;u++)
		for(v=0;v<G.vexnum;v++)
			for(w=0;w<G.vexnum;w++)
				if (D[v][u] < INFINITY&&D[u][w] < INFINITY && (D[v][u] + D[u][w]) < D[v][w])
				{						//��v����u��w��һ��·������
					D[v][w] = D[v][u] + D[u][w];
					for (i = 0; i < G.vexnum; i++)
						P[v][w][i] = P[v][u][i] || P[u][w][i];
				}//���ֶε����·���Ķ���ϲ�
}				//��v��w��·��������v��u�ʹ�u��w������·��
				//����̰���㷨��ÿ������