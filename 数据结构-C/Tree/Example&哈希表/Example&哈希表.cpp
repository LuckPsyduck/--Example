#include"hash.h"
#define N 15
void Visit(int p, ElemType r)
{
	printf("address=%d(%d,%d)\n", p, r.key, r.order);
}
void main()
{
	ElemType r[N];
	HashTable h;
	int i, n, p = 0;
	Status j;
	KeyType k;
	FILE *f;
	f = fopen("T.txt", "r");
	do
	{
		i = fscanf(f, "%d %d", &r[p].key, &r[p].order);
		if (i != -1)
			p++;
	} while (!feof(f) && p < N);
	fclose(f);
	InitHashTable(h);
	for (i = 0; i < p - 1; i++)
	{
		j = InsertHash(h, r[i]);
		if (j == DUPLICATE)
			printf("�������йؼ���Ϊ%d�ļ�¼���޷��ٲ����¼(%d,%d)\n",r[i].key,r[i].key,r[i].order);
	}
	printf("����ϣ���ַ��˳�������ϣ��:\n");
	TraverseHash(h, Visit);
	printf("����������ҵĹؼ���:");
	scanf("%d", &k);
	j = SearchHash(h, k, p, n);
	if (j == SUCCESS)
		Visit(p, h.elem[p]);
	else
		printf("δ�ҵ�\n");
	j = InsertHash(h, r[i]);
	if (j == ERROR)
		j = InsertHash(h, r[i]);
	printf("����ϣ���ַ��˳������ؽ���Ĺ�ϣ��:\n");
	TraverseHash(h, Visit);

	printf("��������Ҽ�¼�Ĺؼ���:\n");
	scanf("%d", &k);
	j = SearchHash(h, k, p, n);
	if (j == SUCCESS)
		Visit(p, h.elem[p]);
	else
		printf("δ�ҵ�\n");
	DestroyHashTable(h);
}