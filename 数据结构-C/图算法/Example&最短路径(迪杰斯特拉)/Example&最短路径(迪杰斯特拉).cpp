// ���·��(�Ͻ�˹����).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"�Ͻ�˹����.h"

int main()
{
	int i, j;
	MGraph g;
	PathMatrix p;
	ShortPathTable d;
	CreateDN(g);
	Display(g);
	ShortestPath_DIJ(g, 0, p, d);

	printf("���·������p[i][j]����:\n");
	for (i = 0; i < g.vexnum; ++i)
	{
		for (j = 0; j < g.vexnum; ++j)
			printf("%2d", p[i][j]);
		printf("\n");
	}
	printf("%s������������·������Ϊ:\n", g.vexs[0].name);
	for (i = 0; i < g.vexnum; ++i)
		if (i != 0)
			printf("%s--%s: %d\n", g.vexs[0].name, g.vexs[i].name, d[i]);
    return 0;
}

