// ��С������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"��С������.h"

int main()
{
	MGraph g;
	char filename[13];
	printf("�������ļ���:\n");
	scanf("%s", filename);
	CreateFormFile(g, filename, 0);
	Display(g);
	MinSpanTree_PRIM(g, g.vexs[0]);
    return 0;
}

