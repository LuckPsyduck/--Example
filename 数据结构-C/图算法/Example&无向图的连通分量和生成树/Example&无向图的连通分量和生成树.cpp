// ����ͼ����ͨ������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"����ͼ������.h"

int main()
{
	Graph g;
	CSTree t;
	printf("��ѡ������ͼ:\n");
	CreateGraph(g);
	Display(g);
	DFSForest(g, t);
	printf("���������������:\n");
	PreOrderTraverse(t, Visit);
	printf("\n");
    return 0;
}

