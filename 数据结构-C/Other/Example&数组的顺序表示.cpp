// �����˳���ʾ.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include<stdarg.h>
#include<math.h>

#define ERROR 0;
#define TRUE 1;
#define OK 1;

typedef int ElemType;
typedef int  Status;

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#define MAX_ARRAY_DIM 8//�����ά�����ֵ
struct Array
{
	ElemType *base;//����Ԫ�صĻ���
	int dim;//�����ά��
	int *bounds;//����ά���Ļ�ַ
	int *constants;//����ӳ������ַ
};

Status InitArray(Array &A, int dim, ...)//dim��ʾ��������
{
	int elemtotal = 1, i;
	va_list ap;                  //����һ�������洢����
	if (dim<1 || dim>MAX_ARRAY_DIM)
		return ERROR;
	A.dim = dim;//����б��в����ĸ���
	A.bounds = (int *)malloc(dim * sizeof(int));
	if (!A.bounds)
		exit(EXIT_FAILURE);
	va_start(ap, dim);//��ap��ʼ��Ϊһ�������б�
	for (i = 0; i<dim; i++)
	{
		A.bounds[i] = va_arg(ap, int);//���������е�ֵ,��һ��Ϊ��һ�������������ƶ�,���ϵĸ�ֵ����ߵĶ���
		if (A.bounds[i] < 0)
			return UNDERFLOW;
		elemtotal *= A.bounds[i];
	}
	va_end(ap);//�ͷŶ�̬�������ڴ洢�������ڴ�,

	A.base = (ElemType *)malloc(elemtotal*(sizeof(ElemType)));
	if (!A.base)
		exit(EXIT_FAILURE);
	A.constants = (int *)malloc(dim*(sizeof(int)));//��ά�Ļ�ַ
	if (!A.constants)
		exit(EXIT_FAILURE);
	A.constants[dim - 1] = 1;//���һά��ƫ����Ϊ1

	for (i = dim - 2; i >= 0; --i)
		A.constants[i] = A.bounds[i + 1] * A.constants[i + 1];
	return OK;
}

void DestroyArray(Array &A)
{
	if (A.base)
		free(A.base);
	if (A.bounds)
		free(A.bounds);
	if (A.constants)
		free(A.constants);
	A.base = A.bounds = A.constants = nullptr;
	A.dim = 0;
}

Status Locate(Array A, va_list ap, int &off)
{
	int i, ind;
	off = 0;
	for (i = 0; i < A.dim; i++)
	{
		ind = va_arg(ap, int);//��һ��ȡ��ά�ȵ��±�ֵ
		if (ind < 0 || ind >= A.bounds[i])//��ά�ȵ��±�ֵ���Ϸ�
			exit(EXIT_FAILURE);
		off += A.constants[i] * ind;//��Ե�ַ=��ά�ȵ��±�ֵ*��ά��ƫ����֮��
	}
	return OK;
}

Status Value(ElemType &e, Array A, ...)
{
	va_list ap;
	int off;
	va_start(ap, A);
	if (Locate(A, ap, off) == OVERFLOW)
		return ERROR;
	e = *(A.base + off);
	return OK;
}

Status Assign(Array A, ElemType e, ...)
{
	va_list ap;
	int off;
	va_start(ap, e);
	if (Locate(A, ap, off) == OVERFLOW)
		return ERROR;
	*(A.base + off) = e;
	return OK;
}





int main()
{
	Array A;
	int i, j, k, dim = 3, bound1 = 3, bound2 = 4, bound3 = 2;
	ElemType e;
	InitArray(A, dim, bound1, bound2, bound3);
	printf("A.bounds= ");
	for (i = 0; i < dim; i++)
		printf("%3d", *(A.bounds + i));
	printf("\nA.constants= ");
	for (i = 0; i < dim; i++)
		printf("%2d", *(A.constants + i));
	printf("\n");
	printf("[%d] [%d] [%d]\n", bound1, bound2, bound3);
	for (i = 0; i < bound1; i++)
	{ 
		for (j = 0; j < bound2; j++)
		{
			for (k = 0; k < bound3; k++)
			{
				Assign(A, i * 100 + j * 10 + k, i, j, k);
				Value(e, A, i, j, k);
				printf("A[%d][%d][%d]=%2d  ", i, j, k, e);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("A.base=\n");
	for ( i = 0; i < bound1*bound2*bound3; i++)
	{
		printf("%4d", *(A.base + i));
		if (i % (bound2*bound3) == bound2*bound3 - 1)//4*2
			printf("\n");
	}
	printf("A.dim=%d\n", A.dim);
	DestroyArray(A);
    return 0;
}

