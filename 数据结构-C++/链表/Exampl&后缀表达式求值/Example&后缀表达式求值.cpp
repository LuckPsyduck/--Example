// ��׺���ʽ��ֵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Evaluate.h"

void main()
{
	char p[40];
	float y;
	printf("Evaluatem.cpp���н��:\n");
	printf("�����׺���ʽ:");
	gets_s(p);
	y = Evaluate(p);
	printf("��׺���ʽ��ֵ:");
	printf("%5.0f\n", y); 
	cin.get();
}




