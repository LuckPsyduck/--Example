#include"String.h"
void main()
{
	int i, j;
	Status k;
	char s, c[MAX_STR_LEN + 1];
	SString t, s1, s2;
	printf("�����봮s1: ");
	gets_s(c);
	k = StrAssign(s1, c);
	if (!k)
	{
		printf("��������MAX_STR_LEN(=%d)\n", MAX_STR_LEN);
		exit(EXIT_FAILURE);
	}
	printf("����Ϊ%d,���շ�?%d(1 �� 0 ��)\n", Strlength(s1), StrEmpty(s1));
	StrCopy(s2, s1);
	printf("��ֵs1���ɵĴ�Ϊ");
	StrPrint(s2);
	printf("�����봮s2: ");
	gets_s(c);
	StrAssign(s2, c);
	i = StrCompare(s1, s2);
	if (i < 0)
		s = '<';
	else
		s = '>';
	printf("��s1 %c��s2\n", s);
	k = Concat(t, s1, s2);
	printf("��s1���Ӵ�s2�õ��Ĵ�tΪ");
	StrPrint(t);
	if (k == false)
		printf("��t�нض�\n");
	ClearString(s1);
	printf("��Ϊ�մ��󣬴�s1Ϊ");
	StrPrint(s1);
	printf("����Ϊ%d,�մ���(1 �� 0 ��)]\n", Strlength(s1), StrEmpty(s1));
}