//���������ַ�Ϊ��ABC##DE#G##F###��ʵ������ʱ��#�ÿո���档
#include"Tree.h"
//��������Ԫ��ʱ�����ú���
Status PrintElement(TElemType e)
{
	putchar(e);
	return OK;
}

int main()
{
	BiTree T;
	puts("�밴�������������:");
	CreatBiTree(&T);
	//����
	puts("����ݹ�:");
	PreOrderTraverse_Recursive(T, PrintElement); putchar('\n');
	puts("����ǵݹ�:");
	PreOrderTraverse_NonRecursive(T, PrintElement); putchar('\n');
	//����
	puts("����ݹ�:");
	InOrderTraverse_Recursive(T, PrintElement); putchar('\n');
	puts("����ǵݹ�:");
	InOrderTraverse_NonRecursive(T, PrintElement); putchar('\n');
	InOrderTraverse_NonRecursive_2(T, PrintElement); putchar('\n');
	//����
	puts("����ݹ�:");
	PostOrderTraverse_Recursive(T, PrintElement); putchar('\n');
	puts("����ǵݹ�:");
	PostOrderTraverse_NonRecursive(T, PrintElement); putchar('\n');
	return 0;
}
