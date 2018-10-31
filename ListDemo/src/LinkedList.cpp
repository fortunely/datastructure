/*
 * LinkedList.cpp
 *
 *  Created on: 2018��10��22��
 *      Author: Think
 */

#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
}

LinkedList::~LinkedList() {
	Destroy();
}

/**
 * ��ʼ������
 */
Status LinkedList::Init()
{
	// ��������ͷ�ڵ�
	head = new Node(NULL, 0);

	if(head != NULL)
	{
		return OK;
	}

	return ERROR;
}

/**
 * ��������
 * @description ���ʼ���������, ɾ����������ڵ�, ����ͷ�ڵ�
 */
Status LinkedList::Destroy()
{
	if(head)
	{
		Node *curP = head;

		while(head)
		{
			curP = head->next;
			delete head;
			head = curP;
		}

		return OK;
	}
	else
	{
		cout <<"The list is NULL"<<endl;
				return ERROR;
	}
}

/**
 * ��������(��Ч�ڵ�)�ڵ����
 * @description ������ͷ�ڵ����һ���ڵ㿪ʼ������Ч�ڵ���
 */
int LinkedList::Length()
{
	if(!head)
	{
		cout <<"The list is NULL"<<endl;
		exit(-1);
	}

	Node *curP = head->next;
	int n = 0;
	while(curP != NULL)
	{
		n ++;
		curP = curP->next;
	}

	return n;
}

/**
 * �ж������Ƿ�Ϊ��
 * @description �ж�����: ����ͷ�ڵ�head == NULL
 * ע: ����Ϊ0 ����������Ϊ��
 */
bool LinkedList::IsEmpty()
{
	return (head == NULL);
}

/**
 * ��ָ��λ�������ڵ�, ����������
 * @param pos [in] ������λ��. ��ͷ�ڵ�ĺ�̿�ʼΪ0����������Ҫ�����Ľڵ�������Χ��0~n-1
 * @param value [in] ������ڵ�������
 */
Status LinkedList::Insert(int pos, int value)
{
	if(IsEmpty())
	{
		cout <<"The list is NULL. Pls Create an List and init it first."<<endl;
		exit(-1);
	}

	// create a new Node
	Node *newNode = new Node(NULL, value);

	if(pos == 0)
	{
		newNode->next = head->next;
		head->next = newNode;
	}
	else if(pos >0 && pos <= Length())
	{
		// find the predecessor node to be inserted
		Node *p = GetAddress(pos-1);

		// insert the new Node to List
		if(p != NULL)
		{
			if(p->next != NULL)
			{// not tail
				newNode->next  = p->next;
			}
			p->next = newNode;
		}
	}
	else
	{
		cout<<"Error: Input param Pos is illegal(<0)"<<endl;
		return ERROR;

	}

	return OK;
}

/**
 * ɾ��ָ��λ�ýڵ�
 * @param pos [in] ������λ��. pos��Ч��Χ: [0, n), 0��������ڵ����һ���ڵ�, ����ڵ��޷�ͨ����APIɾ��
 *
 */
Status LinkedList::Remove(int pos)
{
	// find the prior node
	Node *curP = GetAddress(pos);
	if(curP == NULL)
	{
		return ERROR;
	}

	// get the node to be delete
	Node *tmp = curP->next;

	// delete the node
	if(tmp != NULL)
	{// not NULL node
		if(tmp->next != NULL)
		{// not tail
			curP->next = tmp->next;
			tmp->next = NULL;
		}
		else
		{
			curP->next =  NULL;
			delete tmp;
		}
	}

	return OK;
}

/**
 * ��ȡָ��λ�ýڵ�����
 */
int LinkedList::GetValue(int pos)
{
	// find the  node
	Node *curP = GetAddress(pos);
	if(curP != NULL)
	{
		return curP->data;
	}
	else
	{
		return 0;
	}
}

/**
 * ��ȡλ�ýڵ�ĵ�ַ
 * @param pos [in] ��ͷ�ڵ�ĺ�̿�ʼΪ0����������Ҫ�����Ľڵ�������Χ��[0, n-1], n��������(��Ч���ݽڵ���)
 * @return �ڵ�ĵ�ַ
 */
Node* LinkedList::GetAddress(int pos)
{
	// valid list is null or not
	if(!head)
	{
		cout <<"The list is NULL"<<endl;
		exit(-1);
	}

	// valid intput param
	if(pos < 0 || pos >= Length())
	{
		cout <<"Insert position is out of the list's bounds"<<endl;
		exit(-1);
	}

	// ˳�����λ��pos�Ľڵ�
	int i = 0;
	Node *curP = head->next;
	while(curP != NULL)
	{
		if(i == pos)
		{
			return curP;
		}

		i ++;

		curP = head->next;
	}

	return NULL;
}

/**
 * ������һ�����ֵ�Ԫ��ֵ�Ľڵ�λ��
 * @param value ������ֵ
 * @return �����һ���ڵ��������=value��λ��
 * - ERROR ����
 * - >=0 λ�����
 */
int LinkedList::SearchPosition(int value)
{
	// valid list is null or not
	if(!head)
	{
		cout <<"The list is NULL"<<endl;
		exit(-1);
	}

	// sequential search
	Node *p = head->next;
	int i = 0;
	while(p != NULL)
	{
		i ++;
		if(p->data == value)
			return i;
		else
			p = p->next;
	}

	cout<< "Can't find the value in list"<<endl;
	return ERROR;
}

/**
 * ����ָ��λ�ýڵ�����
 * @param pos [in] �����½ڵ�λ��
 * @param value [in] �����½ڵ�Ҫ�޸ĵ�Ŀ��ֵ
 * @return ���½��
 * - OK ��������
 * - ERROR û���ҵ������½ڵ�, ������λ�ô����������Ϊ�յ���
 */
Status LinkedList::Update(int pos, int value)
{
	// find the node
	Node *curP = GetAddress(pos);
	if(curP != NULL)
	{
		curP->data = value;
		return OK;
	}

	return ERROR;
}

/**
 * �����������(������ͷ�ڵ�)
 */
Status LinkedList::ClearList()
{
	// valid list is null or not
	if(!head)
	{
		cout <<"The list is NULL"<<endl;
		exit(-1);
	}

	Node *p = head->next;
	Node *tmp = NULL;

	while(p!=NULL)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}

	head->next = NULL;

	return OK;
}

/**
 * ˳���ӡ����ڵ�����
 */
Status LinkedList::PrintList()
{
	// valid list is null or not
	if(IsEmpty())
	{
		cout <<"The list is NULL. Pls Create an List and init it first."<<endl;
		return ERROR;
	}

	cout <<"List:[ ";
	if(Length() == 0)
	{
		cout<<"NULL";
	}
	else
	{
		Node *p = head->next;

		while(p != NULL)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
	}
	cout <<"] "<<endl;
	return OK;
}

/**
 * ��ת����, ������ͷ�ڵ�
 */
Status LinkedList::ReverseList()
{
	// valid list is null or not
	if(IsEmpty())
	{
		cout <<"The list is NULL. Pls Create an List and init it first."<<endl;
		exit(-1);
	}

	if(Length() == 0)
	{
		cout <<"The list length = 0. Pls insert new Node."<<endl;
		exit(-1);
	}

	// reverse List
	Node *pre = head->next; // precursor Node
	Node *cur = pre->next;  // current Node
	Node *nxt = NULL;       // successor Node

	while(cur != NULL)
	{
		nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}

	// set the tail Node
	head->next->next = NULL;

	// set the head Node's next field
	head->next = pre;

	return OK;
}
