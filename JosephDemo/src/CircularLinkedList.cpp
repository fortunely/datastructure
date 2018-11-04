/*
 * CircularLinkedList.cpp
 *
 *  Created on: 2018年10月22日
 *      Author: Think
 */

#include "CircularLinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

CircularLinkedList::CircularLinkedList() {
	head = NULL;
	tail = NULL;
}

CircularLinkedList::~CircularLinkedList() {
	Destroy();
}

/**
 * 初始化链表
 */
Status CircularLinkedList::Init()
{
	// 创建虚拟头节点
	head = new Node(NULL, 0);

	if(head)
	{
		tail = head;
		return OK;
	}

	return ERROR;
}

/**
 * 销毁链表
 * @description 与初始化操作相对, 删除所有链表节点, 包括头节点
 */
Status CircularLinkedList::Destroy()
{
	if(head)
	{
		Node *curNode = head;

		while(head != tail)
		{
			curNode = head->next;
			delete head;
			head = curNode;
		}

		// release tail
		if(head)
		{
			delete head;
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
 * 求链表长度(有效节点)节点个数
 * @description 从虚拟头节点的下一个节点开始计算有效节点数
 */
int CircularLinkedList::Length()
{
	if(!head)
	{
		cout <<"The list is NULL"<<endl;
		exit(-1);
	}

	Node *curNode = head->next;
	int n = 0;
	while(curNode != head)
	{
		n ++;
		curNode = curNode->next;
	}

	return n;
}

/**
 * 判断链表是否为空
 * @description 判断依据: 虚拟头节点head == NULL
 * 注: 长度为0 不代表链表为空
 */
bool CircularLinkedList::IsEmpty()
{
	return (head == tail);
}

/**
 * 在指定位置生产节点, 并插入数据
 * @param pos [in] 待插入位置. 从头节点的后继开始为0计数，所需要经过的节点数。范围：0~n-1
 * @param value [in] 待插入节点数据域
 */
Status CircularLinkedList::Insert(int pos, int value)
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
 * 删除指定位置节点
 * @param pos [in] 待插入位置. pos有效范围: [0, n), 0代表虚拟节点后面一个节点, 虚拟节点无法通过此API删除
 *
 */
Status CircularLinkedList::Remove(int pos)
{
	Node *preNode = NULL;
	Node *curNode = NULL;
	Node *nextNode = NULL;

	if(pos < 0 || pos >= Length())
	{
		cout << "Remove node with error position"<<endl;
		exit (-1);
	}
	else if(pos == 0)
	{// find the prior node, namely , head node
		preNode = head;
	}
	else if(pos < this->Length())
	{
		// find the prior node
		preNode = GetAddress(pos - 1);
	}

	if(!preNode)
	{
		return ERROR;
	}

	curNode = preNode->next;
	if(curNode)
	{
		nextNode = curNode->next;
		preNode->next = nextNode;
		delete curNode;
	}

	return OK;
}

/**
 * 读取指定位置节点数据
 */
int CircularLinkedList::GetValue(int pos)
{
	// find the  node
	Node *curNode = GetAddress(pos);
	if(curNode != NULL)
	{
		return curNode->data;
	}
	else
	{
		return 0;
	}
}

/**
 * 获取位置节点的地址
 * @param pos [in] 从头节点的后继开始为0计数，所需要经过的节点数。范围：[0, n-1], n是链表长度(有效数据节点数)
 * @return 节点的地址
 */
Node* CircularLinkedList::GetAddress(int pos)
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

	// 顺序查找位置pos的节点
	int i = 0;
	Node *curNode = head->next;
	while(curNode != NULL)
	{
		if(i == pos)
		{
			return curNode;
		}

		i ++;

		curNode = curNode->next;
	}

	return NULL;
}

/**
 * 搜索第一个出现的元素值的节点位置
 * @param value 待查找值
 * @return 链表第一个节点的数据域=value的位置
 * - ERROR 错误
 * - >=0 位置序号
 */
int CircularLinkedList::SearchPosition(int value)
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
 * 更新指定位置节点数据
 * @param pos [in] 待更新节点位置
 * @param value [in] 待更新节点要修改的目标值
 * @return 更新结果
 * - OK 正常更新
 * - ERROR 没有找到待更新节点, 可能由位置错误或者链表为空导致
 */
Status CircularLinkedList::Update(int pos, int value)
{
	// find the node
	Node *curNode = GetAddress(pos);
	if(curNode != NULL)
	{
		curNode->data = value;
		return OK;
	}

	return ERROR;
}

/**
 * 清除链表数据(不包含头节点)
 */
Status CircularLinkedList::ClearList()
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
 * 顺序打印链表节点数据
 */
Status CircularLinkedList::PrintList()
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
 * 反转链表, 除虚拟头节点
 */
Status CircularLinkedList::ReverseList()
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
