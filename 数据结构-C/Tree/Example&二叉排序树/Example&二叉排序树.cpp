#include"BinarySortTree.h"
void main()
{
	BiTree dt, p;
	int i, n;
	KeyType j;
	ElemType r;
	Status k;
	FILE *f;

	f = fopen("T.txt", "r");
	fscanf(f, "%d", &n);
	InitDSTable(dt);//����ն���������
	for (i = 0; i < n; i++)//I�����ڶ���������dt�в���n������Ԫ��
	{
		InputFromFile(f, r);
		k = InsertBST(dt, r);
		if (!k)
			printf("����������dt���Ѿ����ڹؼ���Ϊ%d�����ݣ���(%d,%d)�޷����뵽dt��\n", r.key, r.key, r.others);
	}
	fclose(f);
	printf("�����������������dt:\n");//ȷ��dt�Ƿ�����
	TraverseDSTable(dt, Visit);
	printf("\n");

	printf("�������������:\n");//ȷ��dt����̬
	PostOrderTraverse(dt, Visit);
	printf("\n");

	printf("����������ҵĹؼ��ֵ�ֵ:");
	InputKey(j);
	p = SearchBST(dt, j);
	/*ͨ���������������ͺ��򣩱����������������Ϳ���ȷ����������������̬*/
	if (p)
	{
		printf("dt�д��ڹؼ���Ϊ %d �Ľ��", j);
		DeleteBST(dt, j);
		printf("ɾ���˽����������������dt:\n");
		TraverseDSTable(dt, Visit);
		printf("\n");

		printf("�������������:\n");
		PostOrderTraverse(dt, Visit);
		printf("\n");
	}
	else
		printf("dt�в����ڹؼ���Ϊ%d�Ľ��\n", j);
	DestroyDSTable(dt);
}