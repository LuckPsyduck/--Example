// ��С������-��³˹.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"��³˹�㷨.h"

int main()
{
	MGraph g;
	char filename[13];
	printf("���������ݵ��ļ���:\n");
	scanf("%s", filename);
	CreateFormFile(g, filename, 0);
	Display(g);
	Kruskal(g);
    return 0;
}

