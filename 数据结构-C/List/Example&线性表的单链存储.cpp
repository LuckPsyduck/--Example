#include"SqList.h"
void print(ElemType c)
{
	printf("%4d", c);
}
Status equal(ElemType c1, ElemType c2)
{
	if (c1 == c2)
		return true;
	else
		return false;
}
void main()
{
	LinkList L;
	ElemType e, e0;
	Status i;
	int j, k;
	InitList(L);//��ʼ��

	for (j = 1; j <= 5; j++)
		i = ListInsert(L, 1, j);

	printf("��L�ı�ͷ���β���1-5��L=��\n");
	ListTraverse(L, print);
	i = ListEmpty(L);
	printf("i=%d(0 �գ�1 �ǿ�),��ĳ���=%d\n", i, ListLength(L));
	ClearList(L);
	printf("��պ�L=��\n");
	ListTraverse(L, print);

	i = ListEmpty(L);
	printf("i=%d(0 �գ�1 �ǿ�),��ĳ���=%d\n", i, ListLength(L));

	for (j = 1; j <= 10; j++)
		ListInsert(L, j, j);
	printf("��L�ı�β���β���1-10��L=��\n");
	ListTraverse(L, print);

	for (j = 0; j <= 1; j++)
	{
#ifdef  SLL//�����ھ�̬����
		k = LocateElem(L, j);
		if (k)
			printf("ֵΪ%d��Ԫ�ص�λ��Ϊ%d\n", j, k);
#else//����������
		k = LocateElem(L, j, equal);//�������j ��Ԫ����ȵ�λ��
		if (k)
			printf("��%d��Ԫ�ص�ֵΪ%d\n", j, k);
#endif //  SLL
		else
			printf("û��ֵΪ%d��Ԫ��", j);
	}

	for (j = 1; j <= 2; j++)
	{
		GetElem(L, j, e0);//��j��Ԫ�ظ�e0

		i = PriorElem(L, e0, e);//����ǰ��
		if (i == ERROR)
			printf("Ԫ��%d��ǰ����", e0);
		else
			printf("Ԫ��%d��ǰ��Ϊ%d\n", e0, e);
	}

	for (j = ListLength(L) - 1; j <= ListLength(L); j++)
	{
		GetElem(L, j, e0);
		i = NextElem(L, e0, e);
		if (i == ERROR)
			printf("Ԫ��%d�޺��\n", e0);
		else
			printf("Ԫ��%d�ĺ��Ϊ%d\n", e0, e);
	}

	k = ListLength(L);
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(L, j, e);
		if (i == ERROR)
			printf("ɾ����%d��Ԫ��ʧ��\n", j);
		else
			printf("ɾ����%d��Ԫ�سɹ�����ֵΪ%d\n", j, e);
	}

	printf("�������L��Ԫ��: ");
	ListTraverse(L, print);
	DestroyList(L);
#ifdef  SLL
	printf("����L��L=%p\n", L);
#endif //  SLL
}