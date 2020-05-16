#include "stdafx.h"
#include "HList.h"//����ɢ�з�
using namespace std;

template class LHList<ElemType>;

//���캯��,��ʼ��ɢ�б�
template<class T>
LHList<T>::LHList(int MaxSize)
{
	m = MaxSize;
	HT = new LNode*[m];
	for (int i = 0; i<m; i++)
		HT[i] = NULL;
}

//��������,���һ��ɢ�б�
template<class T>
LHList<T>::~LHList()
{
	LNode* p;//data next
	for (int i = 0; i<m; i++) 
	{
		p = HT[i];
		while (p != NULL)
		{
			HT[i] = p->next;
			delete p;
			p = HT[i];
		}
	}
	delete[]HT;
}

//���ڿ��ŵ�ַ���Ľ�ɢ�б�
template<class T>
void LHList<T>::CreateHashTable(T A[], int n)//����A[0..n-1]�н�㽨��ɢ�б�T[0..m-1]
{
	int i;
	if (n > m) //�ÿ��Ŷ�ַ�������ͻʱ,װ�����Ӧ��벻����1 //��ʾ��������
	{
		cerr << "Load factor>1:\n"; 
		return;
	}
	for (i = 0; i<n; i++) //���ν�A[0..n-1]���뵽ɢ�б�T[0..m-1]��//�����ǰ�˳��ģ����չؼ���������
		Insert(A[i]);
}

//��ɢ�б����һ��Ԫ��
template<class T>
void LHList<T>::Insert(T item)
{
	int d = HashAddress(item, m);//����item��ɢ�е�ַ // ͨ��������ȷ��λ�ã�
	LNode* p = new LNode;	//Ϊ��Ԫ�ط���洢���	
	p->data = item;//���½����뵽d������ı�ͷ
	p->next = HT[d];
	HT[d] = p;//����ͷԪ��
}

//��ɢ�б��в���һ��Ԫ��
template<class T>
T *LHList<T>::Search(T item)
{
	int d = HashAddress(item, m);//����item��ɢ�е�ַ
	LNode* p = HT[d];//�õ���Ӧ������ı�ͷָ��
	//�Ӹõ�������˳�����ƥ���Ԫ��,
	//�����ҳɹ����ظ�Ԫ�صĵ�ַ
	while (p != NULL)
	{
		if (p->data == item) 
			return &(p->data);
		else 
			p = p->next;
	}
	return NULL;	//����ʧ�ܷ��ؿ�ָ��
}

//��ɢ�б���ɾ��һ��Ԫ��
template<class T>
bool LHList<T>::Delete(T item)
{
	int d = HashAddress(item, m);//����item��ɢ�е�ַ
	LNode* p = HT[d];	//pָ���Ӧ������ı�ͷָ��
	
	if (p == NULL)//��������Ϊ�գ���ɾ��ʧ�ܷ��ؼ�
		return false;

	if (p->data == item)	//����ͷ���Ϊ��ɾ���Ľ��,��ɾ�����󷵻���
	{
		HT[d] = p->next;
		delete p;
		return true;
	}
	//�ӵڶ����������ұ�ɾ����Ԫ��,
	//�����ҳɹ���ɾ������������
	LNode* q = p->next;
	while (q != NULL)
	{
		if (q->data == item) 
		{
			p->next = q->next;
			delete q;
			return true;
		}
		else
		{ 
			p = q; //ǰ��
			q = q->next; 
		}
	}
	return false;	//û�п�ɾ����Ԫ��,�򷵻ؼ�
}

//��ʾ���ɢ�б��е�����Ԫ��
template<class T>
void LHList<T>::PrintHashList()
{
	LNode* p; int n = 0;
	for (int i = 0; i<m; i++) 
	{
		p = HT[i];
		n++;
		cout << setw(3) << i << ':';
		while (p)
		{
			n++;
			cout << setw(3) << p->data;
			if (n % 5 == 0) 
				cout << endl;
			p = p->next;
		}
	}
}


