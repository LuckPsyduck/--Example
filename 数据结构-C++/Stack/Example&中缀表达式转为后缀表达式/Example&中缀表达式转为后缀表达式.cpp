// ��׺���ʽתΪ��׺���ʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<ctype.h>//����int isdigit(int c)������ԭ��
#include "Translate.h"

void main()
{
	printf("���н��:\n");
	printf("������׺���ʽ:");
	char p1[40], p2[40];
	gets_s(p1);
	zhuanhuan(p1, p2);
	printf("\n�����׺���ʽ:");
	printf("%s", p2); 
	cin.get();
}




