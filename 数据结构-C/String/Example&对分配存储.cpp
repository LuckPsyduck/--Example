#include"String.h"
void main()
{
	int i;
	char c, *p = "God bye!", *q = "God luck!";
	HString t, s, r;

	InitString(t);
	InitString(s);
	InitString(r);

	StrAssign(t, p);
	printf("��tΪ��");
	StrPrint(t);

	printf("����Ϊ%d,���շ�?%d(1 �� 0 ��)\n", StrLength(t), StrEmpty(t));
	StrAssign(s, q);
	printf("��sΪ��");
	StrPrint(s);
	i = StrCompare(s, t);
	if (i < 0)
		c = '<';
	else if (i == 0)
		c = '=';
	else
		c = '>';
	printf("��s %c ��t\n", c);
	Concat(r, t,s);
	printf("��t���Ӵ�s�����Ĵ�rΪ��\n");
	StrPrint(r);
}