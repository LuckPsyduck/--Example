#include"Static_searchtable.h"
void main()
{
	SSTable st;
	int i;
	long s;
	char filename[13];
	printf("please enter filename :\n");
	scanf("%s", filename);

	Create_SeqFromFile(st, filename);
	for (i = 1; i <= st.length; i++)
		st.elem[i].total = st.elem[i].politics + st.elem[i].Chinese + st.elem[i].English + st.elem[i].math + st.elem[i].physics + \
		st.elem[i].chemistry + st.elem[i].biology;
	printf("׼��֤��  ����  ���� ���� ���� ��ѧ ���� ��ѧ ���� �ܷ�\n");
	Traverse(st, Visit);

	printf("������������˵Ŀ���: ");
	InputKey(s);
	i = Search_Seq(st, s);
	if (i)
		Visit(st.elem[i]);
	else
		printf("δ�ҵ�!\n");
	Destroy(st);
}
