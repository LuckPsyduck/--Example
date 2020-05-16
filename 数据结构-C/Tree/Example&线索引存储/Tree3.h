#include"Tree2.h"
enum PointTag { Link, Thread };//link(0):ָ��,Thread(1):����
struct BiThrNode
{
	TElemType data;//�ڵ��ֵ
	BiThrNode *lchild, *rchild;//���Һ���ָ��
	PointTag LTag, RTag;//���ұ�־
};
typedef BiThrNode * BiThrTree;

//�Ȱ��������������������еĽڵ�ֵ������������������0/�ո� ��ʾ�սڵ�
void CreateBiThrTree(BiThrTree &T)
{
	TElemType ch;
	scanf(form, &ch);
	if (ch == Nil)//�ڵ��ֵΪ��
		T = NULL;
	else
	{
		T = (BiThrTree)malloc(sizeof(BiThrNode));//���ɸ��ڵ�
		if (!T)
			exit(EXIT_FAILURE);
		T->data = ch;
		CreateBiThrTree(T->lchild);//�ݹ鹹��������
		if (T->lchild)//������
			T->LTag = Link;//�����ӱ�־��ֵ��ָ�룩
		CreateBiThrTree(T->rchild);//�ݹ鹹��������
		if (T->rchild)//���Һ���
			T->RTag = Link;//���Һ��ӱ�־��ֵ��ָ�룩
	}
}

BiThrTree pre;//ȫ�ֱ�����ʼ��ָ��ոշ��ʹ���

			  /**************ͨ�������������������������������֮��preָ�����һ���ڵ�****************/
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);//�ݹ�������������
		if (!p->lchild)//û������
		{
			p->LTag = Thread;//����Ϊ������ǰ����
			p->lchild = pre;//����ָ��Ϊǰ��
		}
		if (!pre->rchild)//ǰ��û���Һ���
		{
			pre->RTag = Thread;//ǰ�����ұ�־Ϊ��������̣�
			pre->rchild = p;//ǰ���Һ���ָ��ָ�����̣���ǰ�ڵ�p��
		}
		pre = p;//����preָ��p��ǰ��
		InThreading(p->rchild);//�ݹ�������������
	}
}

/**************�������������T������������������,Thrtָ��ͷ�ڵ�**************/
void InOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))//����ͷ�ڵ�
		exit(EXIT_FAILURE);
	Thrt->LTag = Link;//����ͷ�ڵ㣬���־Ϊָ��
	Thrt->RTag = Thread;//�ұ�־Ϊ����
	Thrt->rchild = Thrt;//�Һ���ָ���ָ
	if (!T)//ŵ������TΪ�գ�������ָ���ָ
		Thrt->lchild = Thrt;
	else
	{
		Thrt->lchild = T;//ͷ��������ָ��ָ����ڵ�
		pre = Thrt;//pre�ĳ�ֵָ��ͷ�ڵ�
		InThreading(T);//�����������������������preָ��������������һ���ڵ�
		pre->rchild = Thrt;//���һ�������Һ���ָ��ָ��ͷ���
		pre->RTag = Thread;//���һ�������ұ�־Ϊ����
		Thrt->rchild = pre;//ͷ�����Һ���ָ��ָ��������������һ�����
	}
}

/**************�����������������T�ķǵݹ��㷨**************/
void InOrderTraverse_Thr(BiThrTree T, void(*Visit)(TElemType))
{
	BiThrTree p;
	p = T->lchild;//pָ����ڵ�
	while (p != T)//�������������ʱ��P==T
	{
		while (p->LTag == Link)//�ɸ��ڵ�һֱ�ҵ���������������
			p = p->lchild;
		Visit(p->data);//���ʽ��
		while (p->RTag == Thread&&p->rchild != T)//p->rchild����������̣����Ҳ��Ǳ��������һ�����
		{
			p = p->rchild;//pָ������
			Visit(p->data);//���ʺ�̽��
		}//ŵp->rchild�������������Һ��ӣ���pָ���Һ��ӣ�����ѭ���������������������ĵ�һ�����
		p = p->rchild;
	}
}

/**************ͨ�������������������****************************************/
void PreThreading(BiThrTree p)//��������
{
	if (!pre->rchild)//p��ǰ��û���Һ���
	{
		pre->RTag = Thread;//pre���Һ���ָ��Ϊ����
		pre->rchild = p;//p��ǰ���ĺ��ָ��p
	}
	if (!p->lchild)//pû������
	{
		p->LTag = Thread;//p������ָ��Ϊ����
		p->lchild = pre;//p������ָ��ָ��ǰ��
	}
	pre = p;
	if (p->LTag == Link)//������
		PreThreading(p->lchild);
	if (p->RTag == Link)//���Һ���
		PreThreading(p->rchild);
}

/**************�������������T��ͷ�����Һ���ָ��ָ��������������һ�����**************/
void PreOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))//����ͷ�ڵ�
		exit(EXIT_FAILURE);
	Thrt->LTag = Link;//���־Ϊָ��(����)
	Thrt->RTag = Thread;//�ұ�־Ϊ����
	Thrt->rchild = Thrt;//�Һ���ָ���ָ
	if (!T)//ŵ������TΪ�գ�������ָ���ָ
		Thrt->lchild = Thrt;
	else
	{
		Thrt->lchild = T;//ͷ��������ָ��ָ����ڵ�
		pre = Thrt;//pre�ĳ�ֵָ��ͷ�ڵ�
		PreThreading(T);//�����������������������preָ��������������һ���ڵ�
		pre->RTag = Thread;//���һ�������ұ�־Ϊ����
		pre->rchild = Thrt;//���һ�������Һ���ָ��ָ��ͷ���
		Thrt->rchild = pre;//ͷ�����Һ���ָ��ָ��������������һ�����
	}
}

/**************�����������������T�ķǵݹ��㷨**************/
void PreOrderTraverse_Thr(BiThrTree T, void(*Visit)(TElemType))
{
	BiThrTree p;
	p = T->lchild;//pָ����ڵ�
	while (p != T)//�������������ʱ��P==T
	{
		Visit(p->data);//���ʽ��
		if (p->LTag == Link)//����
			p = p->lchild;
		else
			p = p->rchild;//pָ���Һ��ӻ��Ҽ�
	}
}

/**************ͨ���������������������****************************************/
void PostThreading(BiThrTree p)//��������
{
	if (p)
	{
		PostThreading(p->lchild);
		PostThreading(p->rchild);
		if (!p->lchild)//pû������
		{
			p->LTag = Thread;//p������ָ��Ϊ����
			p->lchild = pre;//p������ָ��ָ��ǰ��
		}
		if (!pre->rchild)//p��ǰ��û���Һ���
		{
			pre->RTag = Thread;//pre���Һ���ָ��Ϊ����
			pre->rchild = p;//p��ǰ���ĺ��ָ��p
		}
		pre = p;
	}
}

/**************�������������T��ͷ�����Һ���ָ��ָ��������������һ�����**************/
void PostOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))//����ͷ�ڵ�
		exit(EXIT_FAILURE);
	Thrt->LTag = Link;//���־Ϊָ��(����)
	Thrt->RTag = Thread;//�ұ�־Ϊ����
	Thrt->rchild = Thrt;//�Һ���ָ���ָ
	if (!T)//ŵ������TΪ�գ�������ָ���ָ
		Thrt->lchild = Thrt;
	else
	{
		Thrt->lchild = Thrt->rchild = T;//ͷ��������ָ��ָ����ڵ�
		pre = Thrt;//pre�ĳ�ֵָ��ͷ�ڵ�
		PostThreading(T);//����������к�����������preָ�������������һ���ڵ�
		if (pre->RTag != Link)
		{
			pre->RTag = Thread;//���һ�������ұ�־Ϊ����
			pre->rchild = Thrt;//���һ�������Һ���ָ��ָ��ͷ���
		}
	}
}

void PostOrderTraverse_Thr(BiThrTree T, void(*Visit)(TElemType))
{

}
/********************ɾ��������********************************************/
void DestotyBiThree(BiThrTree &T)
{
	if (T)
	{
		if (T->LTag == Link)
			DestotyBiThree(T->lchild);
		if (T->RTag == Link)
			DestotyBiThree(T->rchild);
		free(T);
		T = NULL;
	}
}


/********************ɾ��ͷ���********************************************/
void DestroyBiThrThree(BiThrTree &Thrt)
{
	if (Thrt)
	{
		if (Thrt->lchild)
			DestotyBiThree(Thrt->lchild);//ɾ�������
		free(Thrt);
		Thrt = NULL;
	}
}

