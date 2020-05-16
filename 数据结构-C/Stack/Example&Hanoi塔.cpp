// ջ_Hanoi��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int c = 0;
void move(char x, int n, char z)
{
	printf("��%i������%i���̴�%c�Ƶ�%c\n", ++c, n, x, z);
}
//������x�ϰ�ֱ����С���������϶��±��Ϊ1��n��n����
void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
		move(x, 1, z);//�����Ϊ1��Բ�̴�x�Ƶ�z
	else
	{
		hanoi(n - 1, x, z, y);//��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��Ϊ������
		move(x, n, z);//�����Ϊn��Բ�̴�x�Ƶ�z
		hanoi(n - 1, y, x, z);//��y�ϱ��Ϊ1��n-1��Բ���Ƶ�z,x��Ϊ������
	}
}
int main()
{
	int n;
	printf("3������Ϊa,b,c,Բ�������a��������b���Ƶ�c����������Բ����: ");
	scanf("%d", &n);
	hanoi(n, 'a', 'b', 'c');
    return 0;
}

