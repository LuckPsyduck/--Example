// ��Ⱥ͹����������(ͼ�ı���(�ڽӱ�洢)).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"��Ⱥ͹����������.h"

int main()
{
	Graph g;
	char filename[13];
	printf("�������ļ���:\n");
	scanf("%s", filename);
	CreateFromFile(g, filename);
	printf("����������������Ľ��:\n");
	DFSTraverse(g, Visit);
	printf("����������������Ľ��:\n");
	BFSTraverse(g, Visit);
	return 0;

}


