
#include"stdio.h"
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1

typedef int Status;

struct PosType//�Թ�����λ������
{
	int x;//��ֵ
	int y;//��ֵ
};

struct SElemType	//ջ��Ԫ������
{
	int ord;			//ͨ������·���ϵġ���š�
	PosType seat;			//ͨ�������Թ��еġ�����λ�á�
	int di;					//�Ӵ�ͨ����������һͨ����ġ�����
};

/************************************ջ�ṹ������**********************************************/

#define STACK_INIT_SIZE 10//�洢�ռ��ʼ������
#define STACK_INCREMENT 2//�洢�ռ��������

struct SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;//��ǰ�ѷ���洢�ռ�
};

void InitStack(SqStack &S)
{
	if (!(S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType))))
		exit(EXIT_FAILURE);
	S.top = S.base;//ջ��
	S.stacksize = STACK_INIT_SIZE;//�洢�ռ�Ϊ��ʼ������
}

Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

void Push(SqStack &S, SElemType e)
{
	//����Ԫ��eΪջS�µ�ջ��Ԫ��
	if (S.top - S.base == S.stacksize)//մ��
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof(SElemType));
		if (!S.base)
			exit(EXIT_FAILURE);
		S.top = S.base + S.stacksize;//�޸�ջ��ָ�룬ָ���µ�ջ��
		S.stacksize += STACK_INCREMENT;//���µ�ǰ�ѷ���Ĵ洢�ռ�
	}
	*(S.top)++ = e;//��e��ջ����Ϊ�µ�ջ��Ԫ�أ�ջ��ָ������1���洢��Ԫ
}

Status Pop(SqStack &S, SElemType &e)//
{
	//��S��Ϊ�գ�ɾ��S��ջ��Ԫ�أ���E������ֵ
	if (S.top == S.base)
		return ERROR;//ջ��
	else
		e = *--S.top;
	return OK;
}

/******************************************************************************************/

#define MAXLENGTH 25						//�Թ����������Ϊ25

typedef int MazeType[MAXLENGTH][MAXLENGTH];//�Թ���������[��][��]
MazeType m;	//�Թ�����

int x, y;							//�Թ�����������

PosType begin, end;
PosType direct[4] = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };//{��������������}���ƶ���������Ϊ��������

void Print()//����Թ��Ľ�
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
			printf("%3d", m[i][j]);
		printf("\n");
	}
}

void Init()							//�趨�Թ����֣�ǽΪ0��ͨ��Ϊ1
{
	int i, j, x1, y1;				//x1,y1��ǽ��Ԫ��������
	printf("�����Թ����У�������");
	scanf("%d,%d", &x, &y);

	for (i = 0; i<y; i++)
	{
		m[0][i] = 0;//�ϱ�Ϊ0
		m[x - 1][i] = 0;
	}
	for (i = 1; i<x - 1; i++)
	{
		m[i][0] = 0;
		m[i][y - 1] = 0;
	}

	for (i = 1; i < x - 1; i++)
		for (j = 1; j < y - 1; j++)
			m[i][j] = 1;//�����ǽ�⣬����ȫ��ͨ������ֵΪ1

	printf("�������Թ���ǽ��Ԫ����");
	scanf("%d", &j);
	printf("�����������Թ���ǽÿ����Ԫ��������������\n");
	for (i = 1; i <= j; i++)
	{
		scanf("%d,%d", &x1, &y1);
		m[x1][y1] = 0;					//�޸���ǽ��ֵΪ0
	}
	printf("�Թ��Ľṹ���£�\n");
	Print();						//ֱ�ӵ��ú���
	printf("��������ڵ�����������");
	scanf("%d,%d", &begin.x, &begin.y);
	printf("��������ڵ�����������");
	scanf("%d,%d", &end.x, &end.y);
}

int curstep = 1;//��ǰ�㼣����ֵΪ1������ڴ�

Status Pass(PosType b)
{
	//���Թ���b��ֵΪ1���ȿ���ͨ����������OK
	if (m[b.x][b.y] == 1)
		return OK;
	else
		return ERROR;
}

void FootPrint(PosType b)
{
	//ʹm��b���ֵ��Ϊ�㼣��curstep��
	m[b.x][b.y] = curstep;
}

void NextPos(PosType &b, int di)
{                                  //���ݵ�ǰλ��b���ƶ�����di,�޸�bΪ��һλ��
	b.x += direct[di].x;
	b.y += direct[di].y;
}

void MarkPrint(PosType b)
{
	m[b.x][b.y] = -1;
}

Status MazePath(PosType start, PosType end)
{
	PosType curpos = start;//��ǰλ�������
	SqStack S;
	SElemType e;//ջԪ��
	InitStack(S);
	do
	{
		if (Pass(curpos))//��ǰλ�ÿ�ͨ����Ҳ��δ���߹���ͨ����
		{
			FootPrint(curpos); //�����㼣��ʹ�Թ���ǰλ�õ�ֵΪcurstep
			e.ord = curstep;//ջԪ�ص����Ϊ��ǰ�㼣
			e.seat = curpos;//ջԪ�ص�λ��Ϊ��ǰλ��
			e.di = 0;//�ӵ�ǰλ�ó�������һλ����
			Push(S, e);
			curstep++;//�㼣��1
			if (curpos.x == end.x&&curpos.y == end.y)//�������
				return TRUE;
			NextPos(curpos, e.di);//�ɵ�ǰλ�ü��ƶ�����ȷ����һ����ǰλ�ã�����curpos		
		}
		else//��ǰλ�ò���ͨ��
		{
			if (!StackEmpty(S))
			{
				Pop(S, e);//��ջ��ǰһλ��
				curstep--;
				while (e.di == 3 && !StackEmpty(S))//��ǰλ�ô������һ�������Ҳ���
				{
					MarkPrint(e.seat);				//��ǰһλ���������䲻�ܵ����յ�ı��			
					Pop(S, e);						//���˻�һ��
					curstep--;
				}
				if (e.di < 3)//δ�����һ������
				{
					e.di++;       //����һ������̽��
					Push(S, e);    //��ջ��λ����һ������
					curstep++;
					curpos = e.seat;    //ȷ����ǰλ��
					NextPos(curpos, e.di);     //�ɵ�ǰλ�ü��ƶ�����ȷ����һ����ǰλ�ã�����curpos		
				}
			}
		}
	} while (!StackEmpty(S));
	return FALSE;
}

void main(int argc, char* argv[])
{
	Init();
	if (MazePath(begin, end))
	{
		printf("���Թ�����ڵ����ڵ�һ��·��Ϊ��\n");
		Print();//�����ͨ·m����
	}
	else
		printf("û�д���ڵ����ڵ�·����\n");
}

