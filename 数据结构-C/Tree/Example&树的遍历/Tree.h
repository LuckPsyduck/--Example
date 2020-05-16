#include"stack.h"
// �������������������н���ֵ(һ���ַ�)���ո��ַ���ʾ������������������ʾ�Ķ�����T��
Status CreatBiTree(BiTree *T)//˫ָ��
{
	char ch;
	scanf("%c", &ch);
	//�����ǰ������ַ�Ϊ�ո���(*T)ָ�������
	if (ch == ' ')
	{
		(*T) = NULL;
	}
	else
	{
		if (!((*T) = (BiTree)malloc(sizeof(BiNode))))
			exit(OVERFLOW);
		(*T)->data = ch;             //���ɸ����
		CreatBiTree(&((*T)->lchild));    //����������
		CreatBiTree(&((*T)->rchild));    //����������
	}
	return OK;
}

/*
* ���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú�����
* �������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
*/
Status PreOrderTraverse_Recursive(BiTree T, Status(*Visit)(TElemType e))
{
	if (T)
	{
		if (Visit(T->data))
			if (PreOrderTraverse_Recursive(T->lchild, Visit))
				if (PreOrderTraverse_Recursive(T->rchild, Visit))
					return OK;
		return ERROR;   //��������ִ�е���һ�������᷵��Error������дֻ��Ϊ��û�б��뾯�档
	}
	else
		return OK;  //��TΪ����ʱ��ֹͣ�ݹ顣
}


Status InOrderTraverse_Recursive(BiTree T, Status(*Visit)(TElemType e))
{
	if (T)
	{
		if (InOrderTraverse_Recursive(T->lchild, Visit))
			if (Visit(T->data))
				if (InOrderTraverse_Recursive(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}


Status PostOrderTraverse_Recursive(BiTree T, Status(*Visit)(TElemType e))
{
	if (T)
	{
		if (PostOrderTraverse_Recursive(T->lchild, Visit))
			if (PostOrderTraverse_Recursive(T->rchild, Visit))
				if (Visit(T->data))
					return OK;
		return ERROR;
	}
	else
		return OK;
}

/*
* ����������������ǵݹ��㷨��
*/

Status PreOrderTraverse_NonRecursive(BiTree T, Status(*Visit)(TElemType e))
{
	Stack *S;   //ջS�д洢ָ��������ָ�롣
	BiTree p;
	S = (Stack*)malloc(sizeof(Stack));
	InitStack(S);
	Push(S, T); //��ָ���ջ��
	while (!StackEmpty(S))
	{
		//��ȡջ��ָ�룬���ջ��ָ�벻Ϊ�գ����ʸý�㡣�����ý�����������ջ��
		if (GetTop(S, &p) && p)
		{
			if (!Visit(p->data))
				return ERROR;
			Push(S, p->lchild);
		}
		//ջ��ָ��Ϊ�գ�����֮ǰѹ�������������������Ϊ�ա�
		else
		{
			Pop(S, &p); //��ָ����ջ
			if (!StackEmpty(S))
			{
				Pop(S, &p); //�ѱ����ʹ��ĸ������ջ����ʱ������ջ�����������ѱ�ȫ�����ʹ���
				Push(S, p->rchild);  //��������ջ��
			}
		}
	}
	return OK;
}

/*
* ���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ؽ��в�����Ӧ�ú�����
* ��������������ķǵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
*/

Status InOrderTraverse_NonRecursive(BiTree T, Status(*Visit)(TElemType e))
{
	Stack *S;
	BiTree p;
	S = (Stack *)malloc(sizeof(Stack));
	InitStack(S);
	Push(S, T); //��ָ���ջ
	while (!StackEmpty(S))
	{
		//�����ߵ���ͷ
		while (GetTop(S, &p) && p)
		{
			Push(S, p->lchild);
		}
		//��ָ����ջ
		Pop(S, &p);
		//���ʽڵ㣬������һ��
		if (!StackEmpty(S))
		{
			Pop(S, &p);
			if (!Visit(p->data))
				return ERROR;
			Push(S, p->rchild);
		}
	}
	return OK;
}

/*
* ���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ؽ��в�����Ӧ�ú�����
* ��������������ķǵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
*/

Status InOrderTraverse_NonRecursive_2(BiTree T, Status(*Visit)(TElemType e))
{
	Stack *S;
	BiTree p = T;
	S = (Stack *)malloc(sizeof(Stack));
	InitStack(S);
	while (p || !StackEmpty(S))
	{
		//��ָ���ջ������������
		if (p)
		{
			Push(S, p);
			p = p->lchild;
		}
		//��ָ����ջ�����ʸ���㣬����������
		else
		{
			Pop(S, &p);
			if (!Visit(p->data))
				return ERROR;
			p = p->rchild;
		}
	}
	return OK;
}

/*
* ����������������ǵݹ��㷨
*/

Status PostOrderTraverse_NonRecursive(BiTree T, Status(*Visit)(TElemType e))
{
	Stack *S;
	BiTree p, pre = NULL;//preָ���ѷ��ʹ������һ����㡣
	S = (Stack*)malloc(sizeof(Stack));
	InitStack(S);
	Push(S, T);//��ָ���ջ
	while (!StackEmpty(S))
	{
		//��ȡջ��ָ�룬�����ǰ�������������������������㲻�Ǹձ����ʵĽڵ㡣�����ǰ�������������������������㲻�Ǹձ����ʵĽ�㡣
		//����ջ��ָ��ָ��������δ�����ʣ�������������������δ�����ʡ���ʱ����������������ջ��
		if (GetTop(S, &p) && p->lchild && pre != p->lchild && !(p->rchild && pre == p->rchild))
			Push(S, p->lchild);
		//���ջ��ָ������������ڣ���δ�����ʡ�����������ջ
		else if (p->rchild && pre != p->rchild)
			Push(S, p->rchild);
		//������������������������ʹ���������ջ�������з��ʡ�����pre��
		else
		{
			Pop(S, &p);
			if (!Visit(p->data))
				return ERROR;
			pre = p;
		}
	}
	return OK;
}

