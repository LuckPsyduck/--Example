#pragma once
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>

template<class T> class BSTree;

template<class T> 
struct TNode
{
private:
	TNode<T>  *left;    //������ָ��
	TNode<T>  *right;   //������ָ��
public:
	friend class BSTree<T>;
	T data;//������
		 
	TNode() :left(NULL), right(NULL) { }  //���캯��
	TNode(T item, TNode<T> *left1, TNode<T> *right1)
		:data(item), left(left1), right(right1) { }
};

template<class T> 
class BSTree
{
private:
	int size;
public:

	//���캯��,������ָ���ÿ�
	BSTree(TNode<T> *&root) { root = NULL; size = 0; }

	//��ClearBST()�����õĺ���
	void DeleteTree(TNode<T> *&root);

	//�ͷſռ�
	void FreeBST(TNode<T> *&root);

	//����������������н����
	int BSTSize();

	//�ж϶����������Ƿ�Ϊ��
	int BSTEmpty(TNode<T> *&root);

	//ȡ��ָ��
	TNode<T> *GetRoot(TNode<T> *&root);

	//�Ӷ����������в���Ԫ��
	TNode<T> *BSTLocate(TNode<T> *&root, T item);

	//������������в���Ԫ��
	void BSTInsert(TNode<T> *&root, T item);

	//�Ӷ�����������ɾ��Ԫ��
	void BSTDelete(TNode<T> *&root, T item);

	//���������������������е����н��
	void Inorder(TNode<T> *&root);

	//����������������
	int BSTreeDepth(TNode<T> *&root);

	//����������������н����
	int BSTreeCount(TNode<T> *&root);

	//�����������������Ҷ�ӽ����
	int BSTreeLeafCount(TNode<T> *&root);

	//���������������ʹ֮��Ϊһ�ÿ���
	void ClearBSTree(TNode<T> *&root);
};
