/*
 * main.cpp
 *
 *  Created on: 2018年10月22日
 *      Author: Think
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	cout<<"This is Linked List Demo."<<endl;

	cout<<"Create&Init List:"<<endl;
	LinkedList *list = new LinkedList();
	list->Init();
	list->PrintList();

	// 顺序插入100~109到链表中
	cout<<"Insert List:"<<endl;
	int i ;
	const int base = 100;
	for(i = base; i < base+10; i ++)
	{
		list->Insert(0, i);
	}
	list->PrintList();

	list->Remove(3);
	list->PrintList();

	cout<<"Reverse List:"<<endl;
	list->ReverseList();
	list->PrintList();

	return 0;
}


