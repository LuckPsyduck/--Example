#include "stdafx.h"
#include "BSTree.h"

template class CBSTree<char>;//ģ����ʵ�����������ز�����

using namespace std;

//��ʼ��������,��������ָ���ÿ�
template<class T>
void CBSTree<T>::InitBSTree(CBSTree<T> *&BST)
{
	BST = NULL;
}

//�ж϶������Ƿ�Ϊ��
template<class T>
bool CBSTree<T>::BSTreeEmpty(CBSTree<T> *&BST)
{
	return BST == NULL;
}

//�Ӷ����������в���Ԫ��
template<class T>
bool CBSTree<T>::Find(CBSTree<T> *&BST, T item)
{
	if (BST == NULL)
		return false;
	else 
	{
		if (item == BST->data)
		{
			item = BST->data;
			return true;
		}
		else if (item<BST->data)//�ݹ����������
			return Find(BST->left, item);
		else                  //�ݹ����������
			return Find(BST->right, item);
	}
}

//���¶����������еĽ��ֵ
template<class T>
bool CBSTree<T>::Update(CBSTree<T> *&BST, const T item, T newc)//�滻
{
	if (BST == NULL) 
		return false;
	else 
	{
		if (item == BST->data) 
		{
			BST->data = newc;
			return true;
		}
		else if (item<BST->data)
			return Update(BST->left, item, newc);
		else
			return Update(BST->right, item, newc);
	}
}

//������������в���Ԫ��
template<class T>
void CBSTree<T>::Insert(CBSTree<T> *&BST, const T &item)
{
	if (BST == NULL)
	{
		CBSTree<T> *p = new CBSTree<T>;
		p->data = item;
		p->left = p->right = NULL;
		BST = p;
	}
	else if (item == BST->data) 
		return;
	else if (item<BST->data)
		Insert(BST->left, item);  //���������в���Ԫ��
	else
		Insert(BST->right, item);//���������в���Ԫ��
}

//�Ӷ�����������ɾ��Ԫ��
// �Ӷ����������в���ֵΪitem�Ľ��, ָ��tָ����ȽϵĽ��ָ��,sָ��t��˫�׽��,��������㿪ʼ�Ƚ�														
template<class T>
bool CBSTree<T>::Delete(CBSTree<T> *&BST, T item)
{													
	CBSTree<T> *t = BST, *s = NULL;
	while (t != NULL) //Ѱ�Ҵ��ȽϽ��
	{
		if (item == t->data)
			break;
		else if (item<t->data)
		{
			s = t;//sָ����ȽϽ���˫��
			t = t->left;
		}
		else 
		{ 
			s = t;
			t = t->right;
		}
	}
	if (t == NULL) //��û���ҵ���ɾ���Ľ�㣬�򷵻ؼ�
		return false;

	//�����ֲ�ͬ���ɾ���Ѳ��ҵ���t���
	if (t->left == NULL && t->right == NULL)//��t���(����ɾ���Ľ��)ΪҶ�ӽ���������д���
	{ 
		if (t == BST)
			BST = NULL;
		else if (t == s->left) 
			s->left = NULL;
		else 
			s->right = NULL;
		delete t;
	}
	else if (t->left == NULL || t->right == NULL)//��t���Ϊ����֧����������д���
	{ 
		if (t == BST) //ɾ���������
		{  
			if (t->left == NULL) 
				BST = t->right;
			else  
				BST = t->left;
		}
		else //ɾ�����������ʱ,������������д���
		{
			if (t == s->left && t->left != NULL)
				s->left = t->left;
			else if (t == s->left && t->right != NULL)
				s->left = t->right;
			else if (t == s->right && t->left != NULL)
				s->right = t->left;
			else if (t == s->right && t->right != NULL)
				s->right = t->right;
		}
		delete t;  //����t���,��tָ����ָ��Ľ��
	}
	else if (t->left != NULL && t->right != NULL)//��t���Ϊ˫��֧����������д���
	{												//p��ʼָ��t���,q��ʼָ��p�����������ĸ����
		CBSTree<T> *p = t, *q = t->left;								
		while (q->right != NULL)//����t��������ǰ����㣬���ҽ�����q���Ϊt��������ǰ�����,p���Ϊq����˫�׽��
		{ 
			p = q;
			q = q->right; 
		}
		t->data = q->data;//q����ֵ����t���
		if (p == t)       //ɾ��������Ϊ�յ�q���,ʹ�������������ӵ������ڵ�����λ��
			t->left = q->left;//���Ի�ͼ�о�
		else 
			p->right = q->left;
		delete q;//����q���
	}
	return true;//ɾ�������󷵻���
}

//�������齨��һ�ö���������
template<class T>
void CBSTree<T>::CreateBSTree(CBSTree<T> *&BST, T a[], int n)
{
	BST = NULL;
	for (int i = 0; i<n; i++)
		Insert(BST, a[i]);
}

//���������������������е����н��
template<class T>
void CBSTree<T>::Inorder(CBSTree<T> *&BST)
{
	if (BST != NULL) 
	{
		Inorder(BST->left);
		cout << BST->data << ' ';
		Inorder(BST->right);
	}
}

//����������������
template<class T>
int CBSTree<T>::BSTreeDepth(CBSTree<T> *&BST)
{
	if (BST == NULL) //���ڿ���,����0�������ݹ�
		return 0;
	else
	{  
		int dep1 = BSTreeDepth(BST->left);//���������������
		int dep2 = BSTreeDepth(BST->right);//���������������
		if (dep1>dep2) //�����������
			return dep1 + 1;
		else 
			return dep2 + 1;
	}
}

//����������������н����
template<class T>
int CBSTree<T>::BSTreeCount(CBSTree<T> *&BST)
{
	if (BST == NULL) 
		return 0;
	else
		return BSTreeCount(BST->left) + BSTreeCount(BST->right) + 1;
}

//�����������������Ҷ�ӽ����
template<class T>
int CBSTree<T>::BSTreeLeafCount(CBSTree<T> *&BST)
{
	if (BST == NULL) 
		return 0;
	else if (BST->left == NULL && BST->right == NULL)
		return 1;
	else 
		return BSTreeLeafCount(BST->left) + BSTreeLeafCount(BST->right);
}

//���ն������Ĺ�����ʾ�������������
template<class T>
void CBSTree<T>::PrintBSTree(CBSTree<T> *&BST)
{
	if (BST == NULL) return;//��Ϊ��ʱ����
	else {//����ִ�����²���
		cout << BST->data;//���������ֵ
		if (BST->left != NULL || BST->right != NULL)
		{
			if (BST->left != NULL)
				cout << '(';//���������
			PrintBSTree(BST->left);//���������
			if (BST->right != NULL)
				cout << ',';//����������Ϊ����������ŷָ���
			PrintBSTree(BST->right);//���������
			if (BST->left != NULL&&BST->right != NULL)
				cout << ')';
		}//���������
	}
}

//�������������,ʹ֮��Ϊһ�ÿ���
template<class T>
void CBSTree<T>::ClearBSTree(CBSTree<T> *&BST)
{
	if (BST != NULL)//���������ǿ�ʱ�������²���
	{
		ClearBSTree(BST->left);   //ɾ��������
		ClearBSTree(BST->right);  //ɾ��������
		delete BST;               //ɾ�������
		BST = NULL;				//�ø�ָ��Ϊ��
	}
}             

