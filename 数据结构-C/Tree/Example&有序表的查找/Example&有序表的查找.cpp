#pragma warning (disable:4996)
#include"Staticsearchtable.h"
void main()
{
	SSTable st;
	int i;
	KeyType s;
	Create_SeqFromFile(st, "T.txt");
	printf("�����Ϊ:\n");
	Traverse(st, Visit);
	printf("\n");
	printf("please enter key:\n");
	InputKey(s);
	i = Search_Bin(st, s);
	if (i)
		printf("%d �ǵ� %d �����ݵĹؼ���\n", st.elem[i].key, i);
	else
		printf("δ�ҵ���\n");
	Destroy(st);
}
