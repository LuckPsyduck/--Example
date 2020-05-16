#pragma once
#include<iostream>
#include<iomanip>
#include<stdlib.h>


template<class T>
class CBSTree
{
private:
	CBSTree<T> *left;//������ָ��
	CBSTree<T> *right;//������ָ��
public:
	T data;//������

						//���캯��
	CBSTree() :left(NULL), right(NULL) { }
	CBSTree(T item, CBSTree<T> *left1 = NULL, CBSTree<T> *right1 = NULL)
		:data(item), left(left1), right(right1) { }
		
	CBSTree<T> *&Left() { return left; }
	CBSTree<T> *&Right() { return right; }

	//��ʼ����������������������ָ���ÿ�
	void InitBSTree(CBSTree<T> *&BST);

	//�ж϶����������Ƿ�Ϊ��
	bool BSTreeEmpty(CBSTree<T> *&BST);

	//�Ӷ����������в���Ԫ��
	bool Find(CBSTree<T> *&BST, T item);

	//���¶����������еĽ��ֵ
	bool Update(CBSTree<T> *&BST, const T item, T newc);

	//������������в���Ԫ��
	void Insert(CBSTree<T> *&BST, const T &item);

	//�Ӷ�����������ɾ��Ԫ��
	bool Delete(CBSTree<T> *&BST, T item);

	//�������齨��һ�ö���������
	void CreateBSTree(CBSTree<T> *&BST, T a[], int n);

	//���������������������е����н��
	void Inorder(CBSTree<T> *&BST);

	//����������������
	int BSTreeDepth(CBSTree<T> *&BST);

	//����������������н����
	int BSTreeCount(CBSTree<T> *&BST);

	//�����������������Ҷ�ӽ����
	int BSTreeLeafCount(CBSTree<T> *&BST);

	//���ն����������Ĺ�����ʾ�������������
	void PrintBSTree(CBSTree<T> *&BT);

	//���������������ʹ֮��Ϊһ�ÿ���
	void ClearBSTree(CBSTree<T> *&BT);
};

