// �ؼ�·��(�����޻�ͼ).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"�ؼ�·��.h"

int main()
{
	ALGraph h;
	printf("��ѡ������ͼ\n");
	CreateGraph(h);
	Display(h);
	CriticalPath(h);
    return 0;
}

