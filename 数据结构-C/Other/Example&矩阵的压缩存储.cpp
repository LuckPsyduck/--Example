// �����ѹ���洢.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Matrix.h"


int main()
{
	TSMtrix A, B, C;
	printf("��������A: ");
	CreateSMatrix(A);
	PrintSMatrix(A);
	CopySMatrix(A, B);
	printf("�ɾ���A���ƾ���B:\n");
	PrintSMatrix(B);

	DestroySMatrix(B);
	printf("���پ���B��: \n");
	PrintSMatrix(B);

	printf("��������B2:(�����A���У�������ͬ���У��зֱ�Ϊ%d,%d)\n", A.mu, A.nu);
	CreateSMatrix(B);
	PrintSMatrix(B);

	AddSMatrix(A, B, C);
	printf("����C1(A+B):\n");
	PrintSMatrix(C);
	SubSMatrix(A, B, C);
	printf("����C2(A-B):\n");
	PrintSMatrix(C);

	TransposeSMatrix(A, C);
	printf("����C3(A��ת��):\n");
	PrintSMatrix(C);

	printf("��������A2: ");
	CreateSMatrix(A);
	PrintSMatrix(A);

	printf("��������B3:(����Ӧ�����A2��������ͬ=%d)\n", A.nu);
	CreateSMatrix(B);
	PrintSMatrix(B);

#ifndef FLAG
	MultSMatrix(A, B, C);
#else
	MultSMatrix1(A, B, C);
#endif // !FLAG
	printf("����C5(A*B):\n");
	PrintSMatrix(C);
    return 0;
}

