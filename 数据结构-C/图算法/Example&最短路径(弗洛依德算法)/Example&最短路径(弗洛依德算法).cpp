// ���·��(���������㷨).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"��������.h"

int main()
{
	MGraph g;
	int i, j, k;
	PathMatrix p;
	DistancMatrix d;
	CreateDN(g);
	for (i = 0; i < g.vexnum; i++)
		g.arcs[i][i].adj = 0;
	Display(g);
	ShortestPath_FLOYD(g, p, d);
	printf("d����:\n");
	for (i = 0; i < g.vexnum; i++)
	{
		for (j = 0; j < g.vexnum; j++)
			printf("%6d", d[i][j]);
		printf("\n");
	}
	printf("p����:\n");
	for(i=0;i<g.vexnum;i++)
		for(j=0;j<g.vexnum;j++)
			if (i != j)
			{
				printf("��%s �� %s ����: ", g.vexs[i].name, g.vexs[j].name);
				for (k = 0; k < g.vexnum; k++)
					if (p[i][j][k] == 1)
						printf("%s ", g.vexs[k].name);
				printf("\n");
			}
    return 0;
}

