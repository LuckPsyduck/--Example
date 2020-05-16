// �б༭.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Stack.h"

#define EOFILE '^'

void LineEdit()
{
	CStack *S, *T;
	char str[100];
	int strlen = 0;
	char e;
	char ch;
	S->InitStack(&S);
	T->InitStack(&T);
	ch = getchar();
	while (ch != EOFILE)//������־
	{
		while (ch != EOFILE&&ch != '\n')
		{
			switch (ch) 
			{
			case '#':
				S->Pop(&ch);
				break;
			case '@':
				S->ClearStack();
				break;
			default:
				S->Push(ch);
				break;
			}
			ch = getchar();
		}
		if (ch == '\n')
			S->Push(ch);
		while (!S->StackEmpty())
		{
			S->Pop(&e);
			T->Push(e);
		}
		while (!T->StackEmpty())//��ԭ˳��
		{
			T->Pop(&e);
			str[strlen++] = e;
		}
		if (ch != EOFILE) 
			ch = getchar();
	}
	printf("����༭���ַ���:\n");
	str[strlen] = '\0';
	printf("%s\n", str);
	S->DestroyStack();
	T->DestroyStack();
}

void main()
{
	printf("LINEEDIT.CPP���н��:\n");
	printf("�����ַ���,�������ַ�`��Ϊ����:\n");
	LineEdit();
	cin.get();
	cin.get();
}

