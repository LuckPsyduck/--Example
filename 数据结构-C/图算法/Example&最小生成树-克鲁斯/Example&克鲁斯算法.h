#pragma once
#include"ͼ������.h"

struct side//ͼ�ı���Ϣ�洢�ṹ
{
	int a, b;//������
	VRType weight;
};

void Kruskal(MGraph G)
{
	int set[MAX_VERTEX_NUM], senumber = 0, sb, i, j, k;
	side se[MAX_VERTEX_NUM*(MAX_VERTEX_NUM - 1) / 2];//�洢����Ϣ��Ȼ������������ȡ���������ϵ��ų�
													 //�����ϵ����ɶԳ�������ģ����б�ֻ����һ��	
	for(i=0;i<G.vexnum;i++)		//�������еıߣ�������Ȩֵ����嵽se��														
		for(j=i+1;j<G.vexnum;j++)//��������ֻ����������
			if (G.arcs[i][j].adj < INFINITY)//i,j֮���б�
			{
				k = senumber - 1;
				while (k >= 0)
					if (se[k].weight > G.arcs[i][j].adj)
					{
						se[k + 1] = se[k];
						k--;
					}
					else
						break;
				se[k + 1].a = i;//����Ȩֵ˳�����װ�룬�γ�����
				se[k + 1].b = j;
				se[k + 1].weight = G.arcs[i][j].adj;
				senumber++;
			}
	printf("i se[i].a se[i].b se[i].weight\n");
	for (i = 0; i < senumber; i++)//0-9
		printf("%d %4d %7d %9d\n", i, se[i].a, se[i].b, se[i].weight);
	for (i = 0; i < G.vexnum; i++)//��ʼ��
		set[i] = i;
	printf("��С�����������ĸ�����Ϊ:\n");
	j = 0;//jָʾse��ǰҪ������С�������ıߵ���ţ���ֵΪ0
	k = 0;//kָʾ��ǰ������С�������ı���
	while (k<G.vexnum-1)//��С����������G.vexnum-1����(��0��ʼ)
	{
		if (set[se[j].a] != set[se[j].b])//j����ָ��2���㲻����ͬһ������
		{
			printf("(%s-%s)\n", G.vexs[se[j].a].name, G.vexs[se[j].b].name);
			sb = set[se[j].b];
			for (i = 0; i < G.vexnum; i++)
				if (set[i] == sb)	//�����붥��se[j].b��ͬһ��������
					set[i] = set[se[i].a];	//���˶��㲢�뵽����se[j].a���ڵļ���,�Ӷ�����������
			k++;	//��ǰ������С�������ı���+1//ֻ��ѭ�����ҵĴ���
		}
		j++;	//jָʾse��һ��Ҫ������С�������ı����
	}
}

