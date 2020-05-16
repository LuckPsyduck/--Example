// ����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define n 5                 // 5������ 
#define m (2*n)-1           // ѭ��������㣬�ܼ�Ϊ(2*n)-1 
#define maxval 10000.0
#define maxisize 100

typedef struct
{
	char ch;
	float weight;
	int lchild, rchild, parent;
}hufmtree;

typedef struct
{
	char bits[n];
	int start;//������λ������ʼλ��
	char ch;
}codetype;
//������������
void huffman(hufmtree tree[])
{
	int i, j, p1, p2;
	float small1, small2, f;
	char c;
	for (i = 0; i < m; i++)//��ֵ
	{
		tree[i].parent = 0;
		tree[i].lchild = -1;
		tree[i].rchild = -1;
		tree[i].weight = 0.0;
	}

	printf("����������ǰ%d�������ַ���Ȩֵ!\n", n);
	for (i = 0; i < n; i++)
	{
		printf("�����%d���ַ���Ȩֵ: ", i + 1);
		scanf("%c %f", &c, &f);
		getchar();//ȥ'\n'
		tree[i].ch = c;
		tree[i].weight = f;
	}

	for (i = n; i < m; i++)//����n-1�κϲ�������n-1���½��
	{
		p1 = 0;
		p2 = 0;
		small1 = maxval;
		small2 = maxval;
		for (j = 0; j < i; j++)//ѡ��Ȩֵ��С���������
			if(tree[j].parent==0)
				if (tree[j].weight < small1)  //�ı���СȨ����СȨ����Ӧ��λ��
				{                      
					small2 = small1;
					small1 = tree[j].weight;
					p2 = p1;
					p1 = j;//��Сֵ���±�ֵ
				}
				else
				{
					if (tree[j].weight<small2)
					{
						small2 = tree[j].weight;
						p2 = j;//��Сֵ���±�ֵ
					}
				}
		tree[p1].parent = i;//n��2n-2
		tree[p2].parent = i;
		tree[i].lchild = p1;
		tree[i].rchild = p2;
		tree[i].weight = tree[p1].weight + tree[p2].weight;
	}
}

void huffmancode(codetype code[], hufmtree tree[])
{
	int i, c, p;
	codetype cd;
	for (i = 0; i < n; i++)
	{
		cd.start = n;
		cd.ch = tree[i].ch;
		c = i;
		p = tree[i].parent;//n��2n-2
		while (p!=0)
		{
			cd.start--;
			if (tree[p].lchild == c)
				cd.bits[cd.start] = '0';//��Ͳ�Ĵ���±�ֵ�����Ϊ���ң����ϵ�������
			else
				cd.bits[cd.start] = '1';
			c = p;
			p = tree[p].parent;
		}
		code[i] = cd;
	}
}

void decode(hufmtree tree[])
{
	int i, j = 0;
	char b[maxisize];
	char endflag = 'z';
	
	i = m - 1;
	puts("�����뷢�͵ı���:");
	gets_s(b);
	printf("�������ַ�Ϊ:");
	while (b[j]!='z')
	{
		if (b[j] == '0')
			i = tree[i].lchild;
		else
			i = tree[i].rchild;
		if (tree[i].lchild == -1)//tree[i]��Ҷ���
		{
			printf("%c", tree[i].ch);
			i = m - 1;//�ص������
		}
		j++;
	}
	printf("\n");
	if (tree[i].lchild != -1 && b[j] != 'z') //���Ķ��꣬����δ��Ҷ�ӽ��
		printf("\nerror!\n");
}

int main()
{
	printf("�ܹ���%d���ַ�\n", n);
	hufmtree tree[m];
	codetype code[m];

	int i, j;
	huffman(tree);
	huffmancode(code, tree);
	printf("���ÿ���ַ��Ĺ���������:\n");
	for (i = 0; i <n; i++)
	{
		printf("%c:", code[i].ch);
		for (j = code[i].start; j < n; j++)
			printf("%c", code[i].bits[j]);
		printf("\n");
	}
	printf("������ģ�����������:\n");
	decode(tree);
    return 0;
}

