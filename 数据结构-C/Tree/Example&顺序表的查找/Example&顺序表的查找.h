#include<stdio.h>
#include<stdlib.h>

#define ERROR -1
#define OK 1

typedef int Status;

/******************************����Ԫ�����͵Ķ��弰����****************************/

typedef long KeyType;
#define key number //�ؼ���Ϊ׼��֤��

struct ElemType
{
	long number;//�ؼ���
	char name[9];
	int politics;
	int Chinese;
	int English;
	int math;
	int physics;
	int chemistry;
	int biology;
	int total;
};
struct ElemType c;


void Visit(ElemType c)
{
	printf("%-8ld%-8s%4d%5d%5d%5d%5d%5d%5d%5d\n", c.number, c.name, c.politics, c.Chinese, \
		c.English, c.math, c.physics, c.chemistry, c.biology, c.total);
}

void InputFormFile(FILE *f, ElemType &c)
{                                          //���ļ��У��������ݣ������ָ�ʽ
	fscanf(f, "%ld%s%d%d%d%d%d%d%d", &c.number, c.name, &c.politics, &c.Chinese, \
		&c.English, &c.math, &c.physics, &c.chemistry, &c.biology);
}

void InputKey(KeyType &k)
{
	scanf("%ld", &k);
}
//һ��Ҫ�����ţ�ʹ���γ�һ������
#define EQ(a,b)((a)==(b))
#define LT(a,b)((a)<(b))
#define LQ(a,b)((a)<=(b))

/************************************************************/

/*****************��̬���ұ�Ļ�������****************/

struct SSTable
{
	ElemType *elem;//�ṹ��ָ��
	int length;//����
};

/*�������ļ����쾲̬˳����ұ�*/
void Create_SeqFromFile(SSTable &ST, char *filename)
{
	int i;
	FILE *f;
	f = fopen(filename, "r");
	fscanf(f, "%d", &ST.length);//�������ȵ�ST.length
	ST.elem = (ElemType *)calloc(ST.length + 1, sizeof(ElemType));//��0�ŵ�Ԫ���ã�,�Ѿ���ʼ��Ϊ0
	if (!ST.elem)
		exit(EXIT_FAILURE);
	for (i = 1; i <= ST.length; i++)
		InputFormFile(f, ST.elem[i]);//���뵽�ṹ�������,���ڽṹ������
	fclose(f);
}

/*�ؽ���̬����Ϊ���ؼ��ַǽ�������*/
void Ascend(SSTable &ST)
{
	int i, j, k;
	for (i = 1; i < ST.length; i++)//�����㷨(���ֱȽ�)
	{
		k = i;//k�浱ǰ�ؼ�����С��Ԫ��
		ST.elem[0] = ST.elem[i];//��ǰ���Ƚϵ�Ԫ�ش���0��Ԫ��
		for(j=i+1;j<=ST.length;j++)
			if LT(ST.elem[j].key,ST.elem[0].key)
			{
				k = j;//����ǰ����Сֵ��Ŵ���k
				ST.elem[0] = ST.elem[j];//��Сֵ����0��Ԫ��
			}
		if (k != i)//��ǰ���Ƚϵ�Ԫ�ز�����С�ģ��򽻻�Ԫ��
		{
			ST.elem[k] = ST.elem[i];
			ST.elem[i] = ST.elem[0];
		}
	}
}

//�ɺ�n������Ԫ�ص�����r���찴�ؼ��ַǽ�����ұ�ST
void Create_OrdFile(SSTable &ST, char *filename)
{
	Create_SeqFromFile(ST, filename);
	Ascend(ST);
}

Status Destroy(SSTable &ST)
{
	free(ST.elem);
	ST.elem = NULL;
	ST.length = 0;
	return OK;
}

/*************������ؼ��ֵ���key������Ԫ�أ������±�************/
int Search_Seq(SSTable ST, KeyType key)
{
	int i;
	ST.elem[0].key = key;
	for (i = ST.length; !EQ(ST.elem[i].key, key); i--);
	return i;
}

//�۰����Ԫ�ص���key������Ԫ��
int Search_Bin(SSTable ST, KeyType key)
{
	int mid, low = 1, high = ST.length;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if EQ(key, ST.elem[mid].key)
			return mid;
		else if LT(key, ST.elem[mid].key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

void Traverse(SSTable ST, void(*Visit)(ElemType))
{
	int i;
	ElemType *p = ++ST.elem;
	for (i = 1; i <= ST.length; i++)
		Visit(*p++);
}
