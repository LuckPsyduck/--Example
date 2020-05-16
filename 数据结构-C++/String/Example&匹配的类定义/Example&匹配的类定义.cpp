// �ַ���ƥ����ඨ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iomanip>
#include<string>
#include<stdlib.h>

class String 
{
private:
	char *str;
	int len;
public:
	friend class string;

	String(char S[]);

	~String() { delete[] str; }

	int IndexBF(char T[], int pos);

	void GetNext(int next[]);

	int IndexKMP(char T[], int next[], int pos);
};

String::String(char S[])
{
	len = strlen(S);
	str = new char[len + 1];
	if (str == NULL)
		exit(1);
	for (int i = 0; i<len; i++) 
		str[i] = S[i];
	str[len] = '\0';
}

int String::IndexBF(char T[], int pos)//��pos��λ�ÿ�ʼƥ��
{
	int i, j, r, n;
	i = pos; j = 0;
	n = strlen(T);
	while ((i<len - 1 || j<n - 1) && str[j] != '\0'&&T[j] != '\0')
	{
		if (str[i] == T[j])
		{
			++i; 
			++j;
		}
		else 
		{ 
			i = i - j + 1; //��S����һ��λ�ÿ�ʼƥ��,ÿ�δ���һ����ʼ�ĵط�����һλ
			j = 0; //���´�T�ĵ�һ��Ԫ�ؿ�ʼƥ��
		}
	}
	if (j >= n - 1)//ƥ��ɹ�
		r = i - n + 1;
	else 
		r = -1;
	return r;
}

void String::GetNext(int next[])//�õ�Next���飬װ������һ����Ҫƥ���Ԫ��λ�ã��൱���±�
{
	int j = 0, k = -1; next[0] = -1;
	while (j<len - 1)
	{
		if (k == -1 || str[j] == str[k])
		{
			j++; //jΪ��׺
			k++; //kΪǰ׺
			next[j] = k;//ƥ��ɹ���+1�����ƣ�
		}
		else 
			k = next[k];//���ݻ�ǰ׺
	}
	for (j = 0; j<len; j++)
	{
		printf("%s%d%s%d ", "next[", j, "]=", next[j]);
		if ((j + 1) % 5 == 0) 
			printf("\n");
	}
	printf("\n");
}
//ע���������ʼ�±�
int String::IndexKMP(char T[], int next[], int pos)//��pos����ʼƥ��
{
	int i, j, r, n;
	i = pos; j = 0;
	n = strlen(T); T[n] = '\0';
	while ((i<len - 1 || j<n - 1) && str[j] != '\0'&&T[j] != '\0')
	{
		if (j == 0 || str[i] == T[j])
		{
			++i;
			++j;
		}
		else 
			j = next[j];
	}
	if (j >= n - 1)
		r = i - n + 1;//����ƥ��ɹ���S��Ӧ���±�ֵ
	else 
		r = -1;
	return r;
}

//��ģʽƥ��Ĳ���
void main()
{
	printf("%s\n", "FindSub.cpp���н��:");
	int Index, next[30] = { 0 };
	char s1[30], t1[28];
	printf("%s\n", "GetNext-IndexKMP�Ľ��:");
	printf("%s", "��������s1:");
	scanf("%s", s1);
	printf("%s", "����ģʽ��t1:");
	scanf("%s", t1);
	String s(s1), t(t1);
	printf("%s%d\n", "����s1��=", strlen(s1));
	printf("%s%d\n", "ģʽ��t1��=", strlen(t1));
	t.GetNext(next);
	Index = s.IndexKMP(t1, next, 0);
	if (Index != -1)
		printf("%s%d%s\n", "ģʽ����������λ�ôӵ�", Index, "���ַ���ʼ");
	else 
		printf("%s\n", "����s�в���ģʽ��t");
	printf("%s\n", "IndexBF�Ľ��:");
	Index = s.IndexBF(t1, 0);
	if (Index)
		printf("%s%d%s\n", "ģʽ��t������s�е�λ�ôӵ�", Index, "���ַ���ʼ");
	else 
		printf("%s\n", "����s�в���ģʽ��t");
}



