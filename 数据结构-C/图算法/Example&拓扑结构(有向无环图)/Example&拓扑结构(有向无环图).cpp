// ���˽ṹ(�����޻�ͼ).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"��������.h"

int main()
{
	ALGraph f;
	printf("��ѡ������ͼ:\n");
	CreateGraph(f);
	Display(f);
	TopologicalSort(f);
    return 0;
}

