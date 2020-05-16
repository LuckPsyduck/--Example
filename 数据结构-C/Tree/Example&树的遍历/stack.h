#include"headfile.h"

//��ʼ��ջ
Status InitStack(Stack *s)
{
	s->base = (BiTree*)malloc(sizeof(BiTree)*STACK_INIT_SIZE);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}

//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(Stack *s)
{
	if (s->base == s->top)
		return OK;
	return ERROR;
}

//���ջ��Ԫ��
Status GetTop(Stack *s, BiTree *c)
{
	if (StackEmpty(s))
		return ERROR;
	*c = *(s->top - 1);
	return OK;
}

//��ջ
Status Push(Stack *s, BiTree c)
{
	//����ռ䲻�������ӿռ�ķ���
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (BiTree*)realloc(s->base, sizeof(BiTree)*(s->stacksize + STACKINCREMENT));
		s->stacksize = s->stacksize + STACKINCREMENT;
	}
	*(s->top++) = c;
	return OK;
}

//��ջ
Status Pop(Stack *s, BiTree *c)
{
	if (StackEmpty(s))
		return ERROR;
	*c = *(--s->top);
	return OK;
}
