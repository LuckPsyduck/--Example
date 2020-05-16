/********************�ѷ���洢��ʾ**************************/

#include<stdio.h>                  
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ERROR -1
#define OK 1

#define STACK_INIT_SIZE 10//��ʼ������
#define STACK_INCREMENT 2//��������

typedef int Status;

typedef int QElemType;

struct HString
{
	char *ch;
	int length;
};

//�����մ�
void InitString(HString &S)
{
	S.length = 0;
	S.ch = NULL;
}

void ClearString(HString &S)
{
	free(S.ch);
	InitString(S);
}
//����һ����ֵ���ڴ�����chars�Ĵ�T
void StrAssign(HString &T, char *chars)
{
	int i, j;
	if (T.ch)
		free(T.ch);
	i = strlen(chars);
	if (!i)
		InitString(T);//���ɿմ�
	else
	{
		T.ch = (char *)malloc(i * sizeof(char));
		if (!T.ch)
			exit(EXIT_FAILURE);
		for (j = 0; j < i; j++)
			T.ch[j] = chars[j];
		T.length = i;
	}
}
//��S��ֵ�õ���T
void StrCopy(HString &T, HString S)
{
	int i;
	if (T.ch)
		free(T.ch);
	T.ch = (char*)malloc(S.length * sizeof(char));
	if (!T.ch)
		exit(EXIT_FAILURE);
	for (i = 0; i < S.length; i++)
		T.ch[i] = S.ch[i];
	T.length = S.length;
}

Status StrEmpty(HString S)
{
	if (S.length == 0 && S.ch == NULL)
		return true;
	else
		return false;
}

int StrCompare(HString S, HString T)
{
	int i;
	for (i = 0; i < S.length&&i < T.length; ++i)
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	return S.length - T.length;
}

int StrLength(HString S)
{
	return S.length;
}
//��T����S1��S2���Ӷ��ɵĳ���
void Concat(HString &T, HString S1, HString S2)
{
	int i;
	if (T.ch)
		free(T.ch);
	T.length = S1.length + S2.length;
	T.ch = (char*)malloc(T.length * sizeof(char));
	if (!T.ch)
		exit(EXIT_FAILURE);
	for (i = 0; i < S1.length; i++)
		T.ch[i] = S1.ch[i];
	for (i = 0; i < S2.length; i++)
		T.ch[i+S1.length] = S1.ch[i];
}
//��sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
Status SubString(HString &Sub, HString S, int pos, int len)
{
	int i;
	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
		return ERROR;
	if (Sub.ch)
		free(Sub.ch);
	if (!len)//���Ӵ�
		InitString(Sub);//��ʼ�����Ӵ�
	else
	{
		Sub.ch = (char*)malloc(len * sizeof(char));
		if (!Sub.ch)
			exit(EXIT_FAILURE);
		for (i = 0; i <= len - 1; i++)
			Sub.ch[i] = S.ch[pos - 1 + i];
		Sub.length = len;
	}
	return OK;
}
//�ڴ�S�ĵ�pos���ַ�֮ǰ���봮T
Status StrInsert(HString &S, int pos, HString T)
{
	int i;
	if (pos<1 || pos>S.length + 1)
		return ERROR;
	if (T.length)
	{
		S.ch = (char*)realloc(S.ch, (S.length + T.length) * sizeof(char));
		if (!S.length)
			exit(EXIT_FAILURE);
		for (i = S.length - 1; i >= pos - 1; --i)
			S.ch[i + T.length] = S.ch[i];
		for (i = 0; i < T.length; i++)
			S.ch[pos - 1 + i] = T.ch[i];
		S.length += T.length;
	}
	return OK;
}
//�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen ���Ӵ�
Status StrDelete(HString &S, int pos, int len)
{
	int i;
	if (S.length < pos + len - 1)
		return ERROR;
	for (i = pos - 1; i <= S.length - len; i++)
		S.ch[i] = S.ch[i + len];
	S.length -= len;
	S.ch = (char*)realloc(S.ch, S.length * sizeof(char));//���·��䴮S�Ĵ洢�ռ䣨���٣�
	return OK;
}

void StrPrint(HString S)
{
	int i;
	for (i = 0; i < S.length; i++)
		printf("%c", S.ch[i]);
	printf("\n");
}