#pragma once
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OK 1

typedef int Status;
/**************************ͼ������洢�ṹ*************************/

#define INFINITY INT_MAX     //�������ֵ����������
#define MAX_VERTEX_NUM 26	//��󶥵���
typedef int VRType;           //���嶥��Ĺ�ϵ����Ϊ���ͣ���INFINITY������һ��
enum GraphKind { DG, DN, UDG, UDN };//����ͼ ��  ����ͼ ��

typedef char InfoType;//���ߵ����

typedef struct  //�߻�����Ϣ�ṹ
{
	VRType adj;      //�����ϵ�ṹ ����Ȩ����1(��)0(��)��ʾ�Ƿ����ڣ��Դ�ȨͼΪȨֵ
	InfoType *info;   //�û������Ϣָ��
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];


#define MAX_NAME 9//���������ַ�������󳤶�+1
struct VertexType
{
	char name[MAX_NAME];//��������
};

struct MGraph
{
	VertexType vexs[MAX_VERTEX_NUM];			//��������
	AdjMatrix arcs;								//�ڽӾ���
	int vexnum, arcnum;							 //�������ͻ���
	GraphKind kind;								//ͼ�������־
};
typedef MGraph Graph;
/******************������Ϣ���͵Ķ��弰����********************************/
//
//#define MAX_NAME 9//���������ַ�������󳤶�+1
//
//struct VertexType
//{
//	char name[MAX_NAME];//��������
//};
void Visit(VertexType ver)
{
	printf("%s ", ver.name);
}

void Input(VertexType &ver)
{
	scanf("%s", ver.name);
}

void InputFormFile(FILE *f, VertexType &ver)
{
	fscanf(f, "%s", ver.name);
}
/************************��(��)�������Ϣ���͵Ķ��弰����**********************************/

#define MAX_INFO 20 //���������Ϣ�ַ�������󳤶�+1
/*typedef char InfoType;*/      //���ߵ����

void InputArc(InfoType * &arc)//��֮���׵����뻡(��)�������Ϣ   //��ָ������ã��ı���ֵ
{
	char temp[MAX_INFO];
	int m;
	printf("������û��������Ϣ(<%d���ַ�):", MAX_INFO);
	gets_s(temp);
	m = strlen(temp);
	if (m)
	{
		arc = (char *)malloc((m + 1) * sizeof(char));
		strcpy(arc, temp);
	}
}

void InputArcFormFile(FILE * f, InfoType * &arc)//���ļ����뻡(��)�������Ϣ
{
	char temp[MAX_INFO];
	fgets(temp, MAX_INFO, f);
	arc = (char *)malloc((strlen(temp) + 1) * sizeof(char));//����\0
	strcpy(arc, temp);
}

void OutputArc(InfoType *arc)//������׵Ļ�(��)�������Ϣ
{
	printf("%s\n", arc);
}

/*************************************tͼ���ڽӾ���洢��������********************************/

int LocateVex(MGraph G, VertexType u)//ŵͼ�д��ڶ���u���򷵻�����;�е�λ��(���)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (strcmp(u.name, G.vexs[i].name) == 0)
			return i;
	return -1;
}

void CreateDG(MGraph &G)//��������ͼG
{
	int i, j, k, IncInfo;		//IncInfoΪ0 �򻡲��������Ϣ
	VertexType v1, v2;			//��������
	printf("����������ͼ�Ķ����������������Ƿ��������Ϣ(��:1 ��:0):");
	scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
	printf("������%d�������ֵ(����<%d���ַ�):\n", G.vexnum, MAX_NAME);

	for (i = 0; i < G.vexnum; i++)		//���춥������
		Input(G.vexs[i]);

	for (i = 0; i < G.vexnum; i++)//��ʼ����ά�ڽӾ���(��(��)����Ϣ)
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = 0;//ͼ��������
			G.arcs[i][j].info = NULL;
		}
	printf("������%d�����Ļ�β ��ͷ:\n", G.arcnum);
	for (k = 0; k < G.arcnum; k++)
	{
		scanf("%s %s", v1.name, v2.name);
		getchar();//\0
		i = LocateVex(G, v1);//��β
		j = LocateVex(G, v2);//��ͷ
		G.arcs[i][j].adj = 1;//����ͼ
		if (IncInfo)//�������Ϣ
			InputArc(G.arcs[i][j].info);
	}
	G.kind = DG;//���ı�־
}

void CreateDN(MGraph &G)//����������
{
	int i, j, k, IncInfo;
	VRType w;//�����ϵ����
	VertexType v1, v2;//��������
	printf("�������������Ķ����������������Ƿ��������Ϣ(��:1 ��:0):");
	scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
	printf("������%d�������ֵ(����<%d���ַ�):\n", G.vexnum, MAX_NAME);
	for (i = 0; i < G.vexnum; i++)
		Input(G.vexs[i]);
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = INFINITY;//����������
			G.arcs[i][j].info = NULL;
		}
	printf("������%d�����Ļ�β ��ͷ:\n", G.arcnum);
	for (k = 0; k < G.arcnum; k++)
	{
		scanf("%s %s %d%*c", v1.name, v2.name, &w);
		i = LocateVex(G, v1);//��β
		j = LocateVex(G, v2);//��ͷ
		G.arcs[i][j].adj = w;//������
		if (IncInfo)
			InputArc(G.arcs[i][j].info);
	}
	G.kind = DN;
}

void CreateUDG(MGraph &G)//��������ͼ
{
	int i, j, k, IncInfo;
	VertexType v1, v2;		//��������
	printf("����������ͼ�Ķ����������������Ƿ��������Ϣ(��:1 ��:0):");
	scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
	printf("������%d�������ֵ(����<%d���ַ�):\n", G.vexnum, MAX_NAME);
	for (i = 0; i < G.vexnum; i++)
		Input(G.vexs[i]);
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = 0;
			G.arcs[i][j].info = NULL;
		}
	printf("������%d�����Ķ���1 ���� 2:\n", G.arcnum);
	for (k = 0; k < G.arcnum; k++)
	{
		scanf("%s %s", v1.name, v2.name);
		getchar();
		i = LocateVex(G, v1);//����1�����
		j = LocateVex(G, v2);//����2�����
		G.arcs[i][j].adj = 1;//ͼ
		if (IncInfo)
			InputArc(G.arcs[i][j].info);
		G.arcs[j][i] = G.arcs[i][j];//����������Ԫ�ĵ���Ϣ��ͬ
	}
	G.kind = UDG;
}

void CreateUDN(MGraph &G)//������
{
	int i, j, k, IncInfo;
	VRType w;		//�����ϵ����//Ȩֵ
	VertexType v1, v2;
	printf("�������������Ķ����������������Ƿ��������Ϣ(��:1 ��:0):");
	scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
	printf("������%d�������ֵ(����<%d���ַ�):\n", G.vexnum, MAX_NAME);
	for (i = 0; i < G.vexnum; i++)
		Input(G.vexs[i]);
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = INFINITY;
			G.arcs[i][j].info = NULL;
		}
	printf("������%d�����Ķ���1 ���� 2 Ȩֵ :\n", G.arcnum);
	for (k = 0; k < G.arcnum; k++)
	{
		scanf("%s %s %d", v1.name, v2.name, &w);
		getchar();
		i = LocateVex(G, v1);//����1�����
		j = LocateVex(G, v2);//����2�����
		G.arcs[i][j].adj = w;//��
		if (IncInfo)
			InputArc(G.arcs[i][j].info);
		G.arcs[j][i] = G.arcs[i][j];//����
	}
	G.kind = UDN;
}

void CreateGraph(MGraph &G)
{
	printf("������ͼG������(����ͼ:0 ������:1 ����ͼ:2 ������:3):");
	scanf("%d", &G.kind);
	switch (G.kind)
	{
	case DG:CreateDG(G); break;
	case DN:CreateDN(G); break;
	case UDG:CreateUDG(G); break;
	case UDN:CreateUDN(G); break;
	default:
		break;
	}
}

VertexType GetVex(MGraph G, int v)//v��G�е�ĳ���������ţ�����v��ֵ
{
	if (v >= G.vexnum || v < 0)
		exit(EXIT_FAILURE);
	return G.vexs[v];//���ظö������Ϣ
}

Status PutVex(MGraph &G, VertexType v, VertexType value)//v��G�е�ĳ�����㣬��v����ֵvalue
{
	int k = LocateVex(G, v);//kΪ����v��ͼG�е����
	if (k < 0)
		return ERROR;
	G.vexs[k] = value;
	return OK;
}

int FirstAdjVex(MGraph G, int v)//v��G��ĳ���������ţ�����v�ĵ�һ���ڽӶ�������
{
	int i;
	VRType j = 0;
	if (G.kind % 2)//(DG,DN,UDG,UDN)
		j = INFINITY;//��
	for (i = 0; i < G.vexnum; i++)
		if (G.arcs[i][j].adj != j)
			return i;
	return -1;
}

int NextAdjVex(MGraph G, int v, int w)//v��G��ĳ���������ţ�w��v���ڽӶ������ţ�����v��(�����w��)��һ���ڽӶ�������
{
	int i;
	VRType j = 0;
	if (G.kind % 2)//(DG,DN,UDG,UDN)
		j = INFINITY;
	for (i = w + 1; i < G.vexnum; i++)
		if (G.arcs[v][i].adj != j)
			return i;
	return -1;
}

void InsertVex(MGraph &G, VertexType v)//����¶���v(�������붥����صĻ�)
{
	int i;
	VRType j = 0;
	if (G.kind % 2)//(DG,DN,UDG,UDN)
		j = INFINITY;
	G.vexs[G.vexnum] = v;
	for (i = 0; i <= G.vexnum; i++)//��������������
	{
		G.arcs[G.vexnum][i].adj = G.arcs[i][G.vexnum].adj = j;
		G.arcs[G.vexnum][i].info = G.arcs[i][G.vexnum].info = NULL;
	}
	G.vexnum++;
}

Status InsertArc(MGraph &G, VertexType v, VertexType w)//��G����ӻ�<v,w>,ŵG������ģ�����ӶԳƻ�<w,v>
{
	int i, v1, w1;
	v1 = LocateVex(G, v);//��β
	w1 = LocateVex(G, w);//��ͷ
	if (v1 < 0 || w1 < 0)
		return ERROR;
	G.arcnum++;
	if (G.kind % 2)//��
	{
		printf("������˻���ߵ�Ȩֵ: ");
		scanf("%d", &G.arcs[v1][w1].adj);
	}
	else//ͼ
		G.arcs[v1][w1].adj = 1;
	printf("�Ƿ��иû���ߵ������Ϣ(0:�� 1:��): ");
	scanf("%d", &i);
	getchar();
	if (i)
		InputArc(G.arcs[v1][w1].info);
	if (G.kind > 1)//����
		G.arcs[w1][v1] = G.arcs[v1][w1];
	return OK;
}

Status DeleteArc(MGraph &G, VertexType v, VertexType w)//��G��ɾ����<v,w>,ŵG������ģ���ɾ���Գƻ�<w,v>
{
	int v1, w1;
	VRType j = 0;
	if (G.kind % 2)//��
		j = INFINITY;
	v1 = LocateVex(G, v);//��β
	w1 = LocateVex(G, w);//��ͷ
	if (v1 < 0 || w1 < 0)
		return ERROR;
	if (G.arcs[v1][w1].adj != j)//��<v,w>����
	{
		G.arcs[v1][w1].adj = j;//ɾ����<v,w>
		if (G.arcs[v1][w1].info)//������������Ϣ
		{
			free(G.arcs[v1][w1].info);
			G.arcs[v1][w1].info = NULL;
		}
		if (G.kind >= 2)//����ɾ���ԳƵ�
			G.arcs[w1][v1] = G.arcs[v1][w1];
		G.arcnum--;
	}
	return OK;
}

Status DeleteVex(MGraph &G, VertexType v)//ɾ������v����صĻ�
{
	int i, j, k;
	k = LocateVex(G, v);//kΪ��ɾ����������
	if (k < 0)
		return ERROR;
	for (i = 0; i < G.vexnum; i++)
		DeleteArc(G, v, G.vexs[i]);//ɾ���ɶ���v���������еĻ�
	if (G.kind < 2)//����
		for (i = 0; i < G.vexnum; i++)//ɾ�����򶥵�v�����л�
			DeleteArc(G, G.vexs[i], v);

	for (j = k + 1; j < G.vexnum; j++)
		G.vexs[j - 1] = G.vexs[j];//ǰ��

								  //���ƶ�����ɾ��
	for (i = 0; i < G.vexnum; i++)
		for (j = k + 1; j < G.vexnum; j++)
			G.arcs[i][j - 1] = G.arcs[i][j];//ɾ����ɾ������֮�ҵľ���Ԫ��

	for (i = 0; i < G.vexnum; i++)
		for (j = k + 1; j < G.vexnum; j++)//ɾ����ɾ������֮�µľ���Ԫ��
			G.arcs[j - 1][i] = G.arcs[j][i];

	G.vexnum--;
	return OK;
}

void DestroyGraph(MGraph &G)//����ͼG
{
	int i;
	for (i = G.vexnum - 1; i >= 0; i--)
		DeleteVex(G, G.vexs[i]);
}

void Display(MGraph G)
{
	int i, j;
	char s[7] = "������", s1[3] = "��";
	switch (G.kind)
	{
	case DG:strcpy(s, "����ͼ"); strcpy(s1, "��"); break;
	case DN:strcpy(s, "������"); strcpy(s1, "��"); break;
	case UDG:strcpy(s, "����ͼ");
	case UDN:;
	default:
		break;
	}
	printf("%d ������ %d �� %s �� %s ���������� : ", G.vexnum, G.arcnum, s1, s);
	for (i = 0; i < G.vexnum; i++)
		Visit(GetVex(G, i));
	printf("\nG.arcs.adj:\n");
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
			printf("%12d", G.arcs[i][j].adj);
		printf("\n");
	}
	printf("G.arcs.info: \n");
	if (G.kind < 2)
		printf("��β ��ͷ �� %s ����Ϣ:\n", s1);
	else
		printf("���� 1 ���� 2 �� %s ����Ϣ:\n", s1);
	for (i = 0; i<G.vexnum; i++)
		if (G.kind < 2)//����
		{
			for (j = 0; j<G.vexnum; j++)
				if (G.arcs[i][j].info)
				{
					printf("%5s %5s ", G.vexs[i].name, G.vexs[j].name);
					OutputArc(G.arcs[i][j].info);
				}
		}
		else//���� ��������� �Գ�
			for (j = i + 1; j<G.vexnum; j++)
				if (G.arcs[i][j].info)
				{
					printf("%5s %5s ", G.vexs[i].name, G.vexs[j].name);
					OutputArc(G.arcs[i][j].info);
				}
}

void CreateFromFile(MGraph &G, char *filename, int IncInfo)//���ļ�����ͼ����
{
	int i, j, k;
	VRType w = 0;
	VertexType v1, v2;
	FILE *f;
	f = fopen(filename, "r");
	fscanf(f, "%d", &G.kind);
	if (G.kind % 2)//��
		w = INFINITY;

	fscanf(f, "%d", &G.vexnum);
	for (i = 0; i < G.vexnum; i++)
		InputFormFile(f, G.vexs[i]);//���ļ����붥����Ϣ

	fscanf(f, "%d", &G.arcnum);
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = w;//������
			G.arcs[i][j].info = NULL;
		}
	if (!(G.kind % 2))//ͼ
		w = 1;
	for (k = 0; k < G.arcnum; ++k)//�������еĻ�
	{
		fscanf(f, "%s %s", v1.name, v2.name);
		if (G.kind % 2)
			fscanf(f, "%d", &w);//Ȩֵ
		i = LocateVex(G, v1);//��β
		j = LocateVex(G, v2);//��ͷ
		G.arcs[i][j].adj = w;
		if (IncInfo)
			InputArcFormFile(f, G.arcs[i][j].info);
		if (G.kind > 1)//����
			G.arcs[j][i] = G.arcs[i][j];
	}
	fclose(f);
}

/************************�����������(��Ҫʹ�ö���)***********************************************/

/*************************���в���*****************************/
typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	QNode *next;
}*QueuePtr;

struct LinkQueue
{
	QueuePtr front, rear;
};

void InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));//ͷ���
	if (!Q.front)
		exit(EXIT_FAILURE);
	Q.front->next = NULL;
}

void DestroyQueue(LinkQueue &Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

void ClearQueue(LinkQueue &Q)
{
	DestroyQueue(Q);
	InitQueue(Q);
}

Status QueueEmpty(LinkQueue Q)
{
	if (Q.front->next == NULL)
		return true;
	else
		return false;
}

int QueueLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p = Q.front;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetHead(LinkQueue Q, QElemType &e)//���ض�ͷԪ��
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;//��ͷԪ��
	e = p->data;
	return OK;
}

void EnQueue(LinkQueue &Q, QElemType e)//�����βԪ��
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(EXIT_FAILURE);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;//p���β���
}

Status DeQueue(LinkQueue &Q, QElemType &e)//ɾ����ͷԪ�أ���e����
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;//�൱�ڵڶ���
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}

void QueueTraverse(LinkQueue Q, void(*visit)(QElemType))
{
	QueuePtr p = Q.front->next;//��ͷ���
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}

/************************������������㷨******************************/
bool visite[MAX_VERTEX_NUM];
void(*VisitFunc)(VertexType);

void BFSTraverse(Graph G, void(*Visit)(VertexType))
{
	int v, u, w;
	LinkQueue Q;//ʹ�ø�������Q�ͷ��ʱ�־����visite
	for (v = 0; v < G.vexnum; v++)
		visite[v] = FALSE;//��ʼ�����ʱ�־����visite
	InitQueue(Q);
	for(v=0;v<G.vexnum;v++)
		if (!visite[v])//����vδ������
		{
			visite[v] = TRUE;//�޸ķ��ʱ�־
			Visit(GetVex(G, v));//���ʶ���v
			EnQueue(Q, v);//�������
			while (!QueueEmpty(Q))
			{
				DeQueue(Q, u);//���ӣ�����u
				for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, u, w))//���ڵĽ��//�൱�ڸ������ӽ��
					if (!visite[w])											//һ��һ��ķ���
					{
						visite[w] = TRUE;
						Visit(GetVex(G, w));//����ֱϵ���ڵĶ������
						EnQueue(Q, w);//Ȼ������ӣ��´��ڷ�����ֱϵ���ڵ�
					}
			}//��ʵ������൱�ڲ��������ֻ�����䶥���ֱϵ���ӵ㣬Ȼ����������
		}
	printf("\n");
}
/**************************************************************************/

/*************************�����������(����Ҫ�õ�����,ʹ�õݹ�)**********************************/
void DFS(Graph G, int v)//��v�����ݹ����ȱ���ͼ
{
	int w;
	visite[v] = TRUE;
	VisitFunc(GetVex(G, v));//���ʶ���v
	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))//�Ӷ���v�ĵ�һ���ڽӵ㿪ʼ
		if (!visite[w])
			DFS(G, w);//��v��δ���ʵ����Ϊw���ڽӵ�ݹ����
}

void DFSTraverse(Graph G, void(*Visit)(VertexType))//�ӵ�һ�����㿪ʼ
{
	int v;
	VisitFunc = Visit;
	for (v = 0; v < G.vexnum; v++)
		visite[v] = FALSE;
	for (v = 0; v < G.vexnum; v++)
		if (!visite[v])//v��δ����
			DFS(G, v);
	printf("\n");
}
/************************************************************/
