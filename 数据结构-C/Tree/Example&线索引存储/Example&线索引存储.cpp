#include"Tree3.h"
//#define CHAR 0
#define FLAG 1//�Ƿ���к�������
void main()
{
	BiThrTree H, T;

	for (int i = 1; i < 3; i++)
	{
#if CHAR //CHAR ��ֵΪ��0���������Ϊ�ַ�
		printf("�밴���������������\n");
#else 
		printf("�밴���������������\n");
#endif
		CreateBiThrTree(T);
		scanf("%*c");
		/*	getchar();*/
		switch (i)
		{
		case 1:PreOrderThreading(H, T); printf("�����������������:\n"); PreOrderTraverse_Thr(H, visit); break;
		case 2:InOrderThreading(H, T); printf("�����������������:\n"); InOrderTraverse_Thr(H, visit); break;
		case 3:PostOrderThreading(H, T);
#if FLAG
			printf("�����������������:\n");
			PostOrderTraverse_Thr(H, visit); break;
#endif
		default:break;
		}
		printf("\n");
		DestroyBiThrThree(H);
	}
}