// �����˳���ʾ����ֵ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include<stdarg.h>
#include<math.h>

typedef int ElemType;


ElemType Max(int num, ...)
{
	va_list ap;
	ElemType m, n;
	if (num < 1)
		exit(EXIT_FAILURE);
	va_start(ap, num);
	m = va_arg(ap, ElemType);
	for (int i = 0; i < num; i++)
	{
		n = va_arg(ap, ElemType);
		if(m<n)
			m = n;//m�д�����ֵ
	}
	va_end(ap);
	return m;
}

int main()
{
	printf("1.���ֵΪ%d\n", Max(4, 7, 9, 5, 8));//�ʼ����Ϊ�βεĸ���
	printf("2.���ֵΪ%d\n", Max(3, 17, 36, 25));
    return 0;
}

