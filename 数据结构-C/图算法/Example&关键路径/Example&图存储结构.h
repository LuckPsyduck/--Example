#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#define FLASE 0
#define OK 1
#define ERROR 0
#define TRUE 1

#define MAX_NAME 9
#define MAX_VERTEXT_NUM 20		//��󶥵���
enum GraphKind { DG, DN, UDG, UDN };//����ͼ �� ����ͼ ��

struct VertexType
{
	char name[MAX_NAME];
	int ve, vl;
};

void Visit(VertexType ver)
{
	printf("%s ", ver.name);
}

void Input(VertexType &ver)
{
	scanf("%s", ver.name);
}

void Visitel(VertexType ver)
{
	printf("%3d%3d", ver.ve, ver.vl);
}

void InputFromFile(FILE *f, VertexType &ver)
{
	fscanf(f, "%s", ver.name);
}

typedef int VRType;
struct InfoType
{
	VRType weight;
	int ee, el;
};

void InputArc(InfoType *&arc)
{
	arc = (InfoType *)malloc(sizeof(InfoType));
	scanf("%d", &arc->weight);
}
void OutputArc(InfoType *arc)
{
	printf(":%d  ", arc->weight);
}

void OutputArcel(InfoType *arc)
{
	printf("%3d %3d %3d", arc->weight, arc->ee, arc->el);
}

void InputArcFromFile(FILE *f, InfoType *&arc)
{
	arc = (InfoType *)malloc(sizeof(InfoType));
	fscanf(f, "%d", &arc->weight);
}
struct ElemType
{
	int adjvex;//�û���ָ��Ķ����λ��
	InfoType *info;//�û������Ϣ(��������Ȩֵ)��ָ��
};
struct ArcNode//����,�满����Ϣ
{
	ElemType data;
	ArcNode *nextarc;//ָ����һ������ָ��
};
typedef struct//ͷ��㣬�涥�����Ϣ
{
	VertexType data;//������Ϣ
	ArcNode *firstarc;//��һ������ĵ�ַ,ָ���1�������ö���Ļ���ָ��
}VNode, AdjList[MAX_VERTEXT_NUM];

struct ALGraph
{
	AdjList vertices;
	int vexnum, arcnum;
	GraphKind kind;//ͼ������
};
#define LNode ArcNode
#define next nextarc
typedef ArcNode *LinkList;


/***********************************************************/
typedef int Status;
#define DestroyList ClearList

void InitList(LinkList &L)
{
	L = NULL;
}

void ClearList(LinkList &L)
{
	LinkList p;
	while (L)
	{
		p = L;
		L = L->next;
		free(p);
	}
}

Status ListEmpty(LinkList L)
{
	if (L)
		return false;
	else
		return true;
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
	int j = 1;
	LinkList p = L;
	if (i < 1)
		return ERROR;
	while (j<i&&p)
	{
		j++;
		p = p->next;
	}
	if (j == i&&p)
	{
		e = p->data;
		return OK;
	}
	return ERROR;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	int i = 0;
	LinkList p = L;
	while (p)
	{
		i++;
		if (compare(p->data, e))
			return i;
		p = p->next;
	}
	return 0;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{
	int j = 1;
	LinkList s, p = L;
	if (i < 1)
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	if (i == 1)
	{
		s->next = L;
		L = s;
	}
	else
	{
		while (p&&j<i - 1)
		{
			j++;
			p = p->next;
		}
		if (!p)
			return ERROR;
		s->next = p->next;
		p->next = s;
	}
	return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e)
{
	int j = 1;
	LinkList q, p = L;
	if (!L)
		return ERROR;
	else if (i == 1)
	{
		L = p->next;
		e = p->data;
		free(p);
	}
	else
	{
		while (p->next&&j<i - 1)
		{
			j++;
			p = p->next;
		}
		if (!p->next || j > i - 1)
			return ERROR;
		q = p->next;
		p->next = q->next;
		e = q->data;
		free(q);
	}
	return OK;
}

void ListTraverse(LinkList L, void(*visit)(ElemType))
{
	LinkList p = L;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}
/*************************************************************/
//���ұ�L����e����equal()�����Ľ�㣬ŵ�ҵ����򷵻�ָ��ý���ָ�룬pָ��ý���ǰ��
//����ý������Ԫ��㣬��p=NULL
LinkList Point(LinkList L, ElemType e, Status(*equal)(ElemType, ElemType), LinkList &p)
{
	int j, i = LocateElem(L, e, equal);//���ұ�L����e����equal()�����Ľ��
	if (i)
	{
		if (i == 1)
		{
			p = NULL;
			return L;
		}
		p = L;//������Ԫ��㣬��pָ���һ��1�����
		for (j = 2; j < i; j++)//pָ�����ҽ���ǰ��
			p = p->next;
		return p->next;//�������ҵ�����ָ��
	}
	return NULL;
}

/*************************ͼ���ڽӱ�洢**************************************/
int LocateVex(ALGraph G, VertexType u)//ŵG�д��ڶ���u(����������ͬ)���򷵻ظö�����ͼ�е�λ��(���)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
		if (strcmp(u.name, G.vertices[i].data.name) == 0)
			return i;
	return -1;
}

void CreateGraph(ALGraph &G)//
{
	int i, j, k;
	VertexType v1, v2;//��������
	ElemType e;//�����Ԫ������(�洢������Ϣ)
	char s[3] = "��";
	printf("������ͼ������(����ͼ:0 ������:1 ����ͼ:2 ������:3): ");
	scanf("%d", &G.kind);
	if (G.kind < 2)
		strcpy(s, "��");
	printf("������ͼ�Ķ�����,����: ");
	scanf("%d,%d", &G.vexnum, &G.arcnum);
	printf("������%d�������ֵ(<%d���ַ�): \n", G.vexnum, MAX_NAME);
	for (i = 0; i < G.vexnum; i++)
	{
		Input(G.vertices[i].data);//���붥����Ϣ
		G.vertices[i].firstarc = NULL;
	}
	printf("������%d��%s��", G.arcnum, s);
	switch (G.kind)
	{
	case DG:printf("��β ��ͷ: \n"); break;
	case DN:printf("��β ��ͷ ������Ϣ: \n"); break;
	case UDG:printf("����1 ����2: \n"); break;
	case UDN:printf("����1 ����2 �ߵ���Ϣ:\n"); break;
	default:
		break;
	}
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%s %s", v1.name, v2.name);
		i = LocateVex(G, v1);//��β
		j = LocateVex(G, v2);//��ͷ
		e.info = NULL;			//���������e��ֵ����ͼ�޻�(��)��Ϣ
		if (G.kind % 2)//��
			InputArc(e.info);
		e.adjvex = j;//��ͷ
		ListInsert(G.vertices[i].firstarc, 1, e);//��e���ڵ�һ��i��Ԫ��(����)�ı�ͷ//��� �����һ��
		if (G.kind >= 2)//����
		{
			e.adjvex = i;
			ListInsert(G.vertices[j].firstarc, 1, e);//���ڵ�j����ͷ(�룬�����һ��)
		}
	}
}

void CreateFromFile(ALGraph &G, char *filename)//���ļ�����G
{
	int i, k, j;
	VertexType v1, v2;
	ElemType e;
	FILE *f;
	f = fopen(filename, "r");
	fscanf(f, "%d", &G.kind);
	fscanf(f, "%d", &G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
	{
		InputFromFile(f, G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
	}
	fscanf(f, "%d", &G.arcnum);
	for (k = 0; k < G.arcnum; k++)
	{
		fscanf(f, "%s %s", v1.name, v2.name);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		e.info = NULL;
		if (G.kind % 2)
			InputArcFromFile(f, e.info);
		e.adjvex = j;
		ListInsert(G.vertices[i].firstarc, 1, e);
		if (G.kind >= 2)
		{
			e.adjvex = i;
			ListInsert(G.vertices[j].firstarc, 1, e);
		}
	}
	fclose(f);
}

VertexType GetVex(ALGraph G, int v)//v��G�Ķ��㣬����v��ֵ
{
	if (v >= G.vexnum || v < 0)
		exit(EXIT_FAILURE);
	return G.vertices[v].data;
}

Status PutVex(ALGraph &G, VertexType v, VertexType value)//v��G�Ķ��㣬��v����ֵ
{
	int k = LocateVex(G, v);//kΪ����v��G�е����
	if (k != -1)
	{
		G.vertices[k].data = value;
		return OK;
	}
	return ERROR;
}

int FirstAdjVex(ALGraph G, int v)//v��G �е�ĳ��������ţ�����v�еĵ�һ���ڽӶ�������
{
	ArcNode *p = G.vertices[v].firstarc;//pָ�򶥵�v�ĵ�һ���ڽӶ������
	if (p)//����v���ڽӶ���
		return p->data.adjvex;//����v�ĵ�һ���ڽӶ�������
	else
		return -1;
}

Status Equalvex(ElemType a, ElemType b)
{
	if (a.adjvex == b.adjvex)//����Ķ�λ��(���)��ͬ
		return OK;
	else
		return ERROR;
}

int NextAdjVex(ALGraph G, int v, int w)//v��G��ĳ���������ţ�w��v���ڽӶ������ţ�����v��(�����w��)��һ���ڽӶ�������
{															//ŵw��v�����һ���ڽӶ��㣬�򷵻�-1
	LinkList p, p1;
	ElemType e;//�����Ԫ������(�洢������Ϣ)
	e.adjvex = w;
	p = Point(G.vertices[v].firstarc, e, Equalvex, p1);//pָ�򶥵�v���������ڽӶ���Ϊw�Ľ��
	if (!p || !p->next)//δ�ҵ�w��w�����һ���ڽӵ�
		return -1;
	else
		return p->next->data.adjvex;
}

void InsertVex(ALGraph &G, VertexType v)//��ͼG�������¶���v(�������붥����صĻ�,��InsertArc()ȥ��)
{
	G.vertices[G.vexnum].data = v;
	G.vertices[G.vexnum].firstarc = NULL;
	G.vexnum++;
}

Status InsertArc(ALGraph &G, VertexType v, VertexType w)//��G������<v,w>,ŵG������ģ�������Գƻ�<w,v>
{
	ElemType e;//�����Ԫ������(�洢������Ϣ)
	int i, j;
	char s1[3] = "��", s2[3] = "-";
	if (G.kind < 2)//����
	{
		strcpy(s1, "��");
		strcpy(s2, "~");//ʸ������ ����Aָ��B
	}
	i = LocateVex(G, v);//��β��ߵ����
	j = LocateVex(G, w);//��ͷ��ߵ����
	if (i < 0 || j < 0)
		return ERROR;
	G.arcnum++;
	e.adjvex = j;//��ͷ�����ֵ
	e.info = NULL;
	if (G.kind % 2)//��
	{
		printf("������ %s %s %s %s ����Ϣ: ", s1, v.name, s2, w.name);
		InputArc(e.info);
	}
	ListInsert(G.vertices[i].firstarc, 1, e);//��e���ڻ�β�ı�ͷ//�γ�һ��
	if (G.kind >= 2)//����
	{
		e.adjvex = i;//��β����
		ListInsert(G.vertices[j].firstarc, 1, e);//��e���ڻ�ͷ�ı�ͷ
	}
	return OK;
}

Status DeleteArc(ALGraph &G, VertexType v, VertexType w)//��G��ɾ����<v,w>,ŵ������ɾ���Գƻ�<w,v>
{
	int i, j, n;
	ElemType e;
	i = LocateVex(G, v);//i�Ƕ���v(��β)�����
	j = LocateVex(G, w);//j�Ƕ���w(��ͷ)�����
	if (i < 0 || j < 0 || i == j)
		return ERROR;
	e.adjvex = j;//��ͷ�����ֵ
	n = LocateElem(G.vertices[i].firstarc, e, Equalvex);//�ڻ�β�������һ�ͷ���㣬�����������е�λ�򸳸�n
	if (n)
	{
		ListDelete(G.vertices[i].firstarc, n, e);//�ڻ�β������ɾ����ͷ���㣬����e������ֵ
		G.arcnum--;
		if (G.kind % 2)//��
			free(e.info);
		if (G.kind >= 2)//����ɾ���Գƻ�<w,v>
		{
			e.adjvex = i;//��β�����ֵ
			n = LocateElem(G.vertices[j].firstarc, e, Equalvex);//�ڻ�ͷ�������ҵ���β���㣬����λ�򸳸�n
			ListDelete(G.vertices[j].firstarc, n, e);//�ڻ�ͷ������ɾ����β����
		}
		return OK;
	}
	else
		return ERROR;
}

Status DeleteVex(ALGraph &G, VertexType v)//ɾ��G�ж���v����صĻ�(��)
{
	int i, k;
	LinkList p;
	k = LocateVex(G, v);//kΪ��ɾ������v�����
	if (k < 0)
		return ERROR;
	for (i = 0; i < G.vexnum; i++)
		DeleteArc(G, v, G.vertices[i].data);//ɾ���ɶ���v���������л�
	if (G.kind < 2)//����
		for (i = 0; i < G.vexnum; i++)
			DeleteArc(G, G.vertices[i].data, v);//ɾ�����򶥵�v�����л�
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;//pָ�򻡽��ĵ�����
		while (p)//δ����β
		{
			if (p->data.adjvex > k)
				p->data.adjvex--;//���-1 ��Ϊǰ��
			p = p->next;//pָ����һ���
		}
	}
	for (i = k + 1; i < G.vexnum; i++)
		G.vertices[i - 1] = G.vertices[i];//����v����Ķ�������ǰ��
	G.vexnum--;
	return OK;
}

void DestroyGraph(ALGraph &G)
{
	int i;
	for (i = G.vexnum - 1; i >= 0; i--)
		DeleteVex(G, G.vertices[i].data);//����ɾ�����㼰��صĻ�
}

void Display(ALGraph &G)

{
	int i;
	ArcNode *p;
	char s1[3] = "��", s2[3] = "-";//����
	if (G.kind < 2)//����
	{
		strcpy(s1, "��");
		strcpy(s2, "~");
	}
	switch (G.kind)
	{
	case DG:printf("����ͼ\n"); break;
	case DN:printf("������\n"); break;
	case UDG:printf("����ͼ\n"); break;
	case UDN:printf("������\n"); break;
	default:
		break;
	}
	printf("%d������,������: ", G.vexnum);
	for (i = 0; i < G.vexnum; i++)
		Visit(GetVex(G, i));//���ʵ�i������
	printf("\n%d��%s:\n", G.arcnum, s1);
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;//pΪָ�����Ϊi�Ķ���ĵ�1����
		while (p)
		{
			if (G.kind <= 1 || i < p->data.adjvex)//��������������е�һ��
			{
				printf("%s%s%s\t", G.vertices[i].data.name, s2, G.vertices[p->data.adjvex].data.name);
				if (G.kind % 2)//��
					OutputArc(p->data.info);//������ߵ���Ϣ
			}
			p = p->nextarc;//pָ����һ������
		}
		printf("\n");
	}
}

typedef int SElemType;
/*****************************��ջ************************/

/*********************************˳��ջ�洢�ṹ************************/
#define STACK_INIT_SIZE 10//��ʼ������
#define STACK_INCREMENT 2//��������
struct SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;//�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
};
/************************************************************************/
void InitStack(SqStack &S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(EXIT_FAILURE);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{
	free(S.base);
	S.top = S.base = NULL;
	S.stacksize = 0;
}

Status ClearStack(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}

Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}

int StackLength(SqStack S)
{
	return S.top - S.base;
}
/****************************����ջ��Ԫ��***********************/
Status GetTop(SqStack S, SElemType &e)
{
	if (S.top > S.base)
	{
		e = *(S.top - 1);
		return OK;
	}
	else
		return ERROR;
}

void Push(SqStack &S, SElemType e)
{
	if (S.top - S.base == S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof(SElemType));
		if (!S.base)
			exit(EXIT_FAILURE);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*(S.top)++ = e;
}

Status Pop(SqStack &S, SElemType &e)
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}

void StackTraverse(SqStack S, void(*visit)(SElemType))
{
	while (S.top>S.base)
	{
		visit(*S.base++);
	}
	printf("\n");
}
