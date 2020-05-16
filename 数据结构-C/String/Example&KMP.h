/********************������˳��洢**************************/

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


#define MAX_STR_LEN 40
typedef unsigned char SString[MAX_STR_LEN + 1];//0�ŵ�Ԫ��Ŵ��ĳ���


											   /*****************����һ����ֵ����chars�Ĵ�T*****************/
Status StrAssign(SString T, char *chars)
{
	int i;
	if (strlen(chars) > MAX_STR_LEN)
		return ERROR;
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);//�Լ�����ʱ���Ǵ�0�±꿪ʼ��
		return OK;
	}
}
/******************��S���Ƶô�T**************************/
void StrCopy(SString T, SString S)
{
	int i;
	for (i = 0; i <= S[0]; i++)
		T[i] = S[i];
}

Status StrEmpty(SString S)
{
	if (S[0] == 0)
		return true;
	else
		return false;
}

int StrCompare(SString S, SString T)
{
	int i;
	for (i = 1; i <= S[0] && i <= T[0]; i++)
		if (S[i] != T[i])
			return S[i] - T[i];
	return S[0] - T[0];
}

int Strlength(SString S)
{
	return S[0];
}

void ClearString(SString S)
{
	S[0] = 0;
}

/*****************��T����S1��S2���Ӷ��ɵ��´���ŵδ���ضϣ��򷵻�TRUE�������򷵻�FALSE**************/
Status Concat(SString T, SString S1, SString S2)
{
	int i;
	if (S1[0] + S2[0] <= MAX_STR_LEN)//δ�ض�
	{
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= S2[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = S1[0] + S2[0];
		return true;
	}
	else//�ض�
	{
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i < MAX_STR_LEN - S1[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = MAX_STR_LEN;
		return false;
	}
}

/******************��Sub���ش�S���Ե�pos���ַ���ĳ���Ϊlen���Ӵ�****************/
Status SubString(SString Sub, SString S, int pos, int len)
{
	int i;
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1)
		return ERROR;
	for (i = 1; i <= len; i++)
		Sub[i] = S[pos + i - 1];
	Sub[0] = len;
	return OK;
}

/******�����Ӵ�T������S�еĵ�pos���ַ�֮���λ�ã�ŵ�����ڣ�����ֵΪ0(1<=pos<=strlength(s))********/
int Index1(SString S, SString T, int pos)
{
	int i, j;
	if (1 <= pos&&pos <= S[0])
	{
		i = pos;
		j = 1;
		while (i <= S[0] && j <= T[0])
			if (S[i] == T[i])
			{
				++i;
				++j;
			}
			else
			{
				i = i - j + 2;
				j = 1;
			}
		if (j > T[0])
			return i - T[0];
		else
			return 0;
	}
	else
		return 0;
}


/*��1<=pos<=strlength(s)+1��*/
/*�ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE�����ֲ��뷵��FALSE*/
Status StrInsert(SString S, int pos, SString T)
{
	int i;
	if (pos<1 || pos>S[0] + 1)
		return ERROR;
	if (S[0] + T[0] <= MAX_STR_LEN)//��ȫ����
	{
		for (i = S[0]; i >= pos; i--)
			S[T[0] + i] = S[i];
		for (i = pos; i < pos + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] += T[0];
		return true;
	}
	else//���ֲ���
	{
		for (i = MAX_STR_LEN; i >= pos + T[0]; i--)
			S[i] = S[i - T[0]];
		for (i = pos; i < pos + T[0] && i <= MAX_STR_LEN; i++)
			S[i] = T[i - pos + 1];
		S[0] = MAX_STR_LEN;
		return false;
	}
}

/*****************(1<=pos<=strlength(pos)-len+1)***************/
/*�Ӵ�S��ɾ���Ե�pos���ַ��𳤶�Ϊlen���Ӵ�*/
Status StrDelete(SString S, int pos, int len)
{
	int i;
	if (pos<1 || pos>S[0] - len + 1 || len < 0)
		return ERROR;
	for (i = pos + len; i <= S[0]; i++)
		S[i - len] = S[i];//��ǰ�ƶ�ɾ���Ӵ��ĳ���
	S[0] -= len;
	return OK;//ɾ���ɹ��ı��
}


void StrPrint(SString S)
{
	int i;
	for (i = 1; i <= S[0]; i++)
		printf("%c", S[i]);
	printf("\n");
}
/********************************KMP�㷨�ĺ���****************/
void get_next(SString T, int next[])//��ģʽ��T��next����ֵ����������next
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T[0])
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
}

void get_nextval(SString T, int nextval[])//��ģʽ��T��next��������ֵ����������nextval
{
	int i = 1,j = 0;
	nextval[1] = 0;
	while (i < T[0])
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			if (T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
}

/*����ģʽ����next������T������S�еĵ�pos���ַ�֮���λ��*/
int Index_KMP(SString S, SString T, int pos, int next[])
{
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0])
		if (j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}


