#include"String3.h"
void main()
{
	int i, *p;
	SString s1, s2;
	StrAssign(s1, "aaabaaaab");
	printf("����Ϊ: ");
	
	StrPrint(s1);
	StrAssign(s2, "aaaab");

	printf("�Ӵ�Ϊ: ");
	StrPrint(s2);
	p = (int *)malloc((Strlength(s2) + 1) * sizeof(int));
	get_next(s2, p);
	printf("�Ӵ���next����Ϊ");
	for (i = 1; i <= Strlength(s2); i++)
		printf("%2d", *(p + i));
	printf("\n");
	i = Index_KMP(s1, s2, 1, p);
	if (i)
		printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n", i);
	else
		printf("�������Ӵ�ƥ�䲻�ɹ�!");

	get_nextval(s2, p);
	printf("������nextval����Ϊ");
	for (i = 1; i <= Strlength(s2); i++)
		printf("%2d", *(p + i));
	printf("\n");
	printf("�������Ӵ���%d���ַ����״�ƥ��\n", Index_KMP(s1, s2, 1, p));
}