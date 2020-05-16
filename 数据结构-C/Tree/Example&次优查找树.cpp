// ���Ų�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

typedef struct TreeNode
{
	char data;
	int weight;
	struct TreeNode *lchild, *rchild;	
}TreeNode;

void init_tree(TreeNode *root)
{
	root = NULL;
	printf("init success!\n");
}

TreeNode *SecondOptimal(TreeNode *root, char R[], int sw[], int low, int high)
{
	int i = low;
	int min = fabs(sw[high] - sw[low]);//���㹫ʽ
	int dw = sw[high] + sw[low - 1];//��ֵ
	int j=0;
	for (j = low + 1; j <= high; ++j)
		if (fabs(dw - sw[j] - sw[j - 1]) < min)
		{
			i = j;//��С������ֵ
			min = fabs(dw - sw[j] - sw[j - 1]);
		}

	root = (TreeNode *)malloc(sizeof(TreeNode));
	root->data = R[i];
	if (i == low)
		root->lchild = NULL;
	else
		root->lchild = SecondOptimal(root->lchild, R, sw,low, i - 1);//����������,����߲���
	if (i == high)
		root->rchild = NULL;
	else
		root->rchild= SecondOptimal(root->lchild, R, sw, i+1, high);
	return root;
}

void pre_order(TreeNode *root)
{
	if (root)
	{
		putchar(root->data);
		pre_order(root->lchild);
		pre_order(root->rchild);
	}
}

void in_order(TreeNode *root)
{
	if (root)
	{
		in_order(root->lchild);
		putchar(root->data);
		in_order(root->rchild);
	}
}

void post_order(TreeNode *root)
{
	if (root)
	{
		post_order(root->lchild);
		post_order(root->rchild);
		putchar(root->data);
	}
}

int search_tree(TreeNode *root, char key)
{
	if (root == NULL)
		return 0;
	else
	{
		if (root->data == key)
			return 1;
		else
		{
			if (search_tree(root->lchild, key) || search_tree(root->rchild, key))
				return 1;
			else
				return 0;
		}
	}
}

int main()
{
	TreeNode *root=NULL;
	int low = 1; int high = 10;
	int *weight, *sw;
	char *R;
	int i, j;
	char ch;
	init_tree(root);
	R = (char *)malloc(high * sizeof(char));
	for (i = low; i < high; i++)
		R[i] = 'A' + i - 1;
	printf("������Ų������ĵ�R[]:\n");
	for (i = low; i < high; i++)
		printf("%-5c", R[i]);
	printf("\n");
	weight = (int*)malloc(high * sizeof(int));
	weight[0] = 0;//û��ʵ������
	weight[1] = 1;
	weight[2] = 1;
	weight[3] = 2;
	weight[4] = 5;
	weight[5] = 3;
	weight[6]=  4;
	weight[7] = 4;
	weight[8] = 3;
	weight[9] = 5;
	printf("������Ų�������Ȩֵweight[]:\n");
	for (i = low; i < high; i++)
		printf("%-5d", weight[i]);
	printf("\n");

	sw = (int *)malloc(sizeof(int)*high);
	sw[0] = 0;
	for (i = low; i < high; i++)
		sw[i] = sw[i - 1] + weight[i];
	printf("������Ų������ĵ���ۼ�Ȩֵsw[]:\n");
	for (i = low; i < high; i++)
		printf("%-5d", sw[i]);

	root = SecondOptimal(root, R, sw, low, high - 1);
	printf("\nǰ�����������:\n");
	pre_order(root);
	printf("\n");
	printf("�������������:\n");
	in_order(root);
	printf("\n");
	printf("�������������:\n");
	post_order(root);
	printf("\n");

	printf("����Ҫ���ҵ�Ԫ��!\n");

	scanf("%c",&ch);
	if (search_tree(root, ch) == 1)
		printf("yes!\n");
	else
		printf("no!\n");
    return 0;
}

