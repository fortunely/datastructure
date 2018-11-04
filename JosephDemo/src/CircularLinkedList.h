/*
 * LinkedList.h
 *
 *  Created on: 2018��10��22��
 *      Author: Think
 */

#ifndef CIRCULARLINKEDLIST_H_
#define CIRCULARLINKEDLIST_H_

#include "Node.h"


typedef int Status;

#define OK     0
#define ERROR  -1


/**
 * ��������
 * @description ������ͷ�ڵ�
 */
class CircularLinkedList {
private:
	Node *head;
	Node *tail;

public:
	CircularLinkedList();
    virtual ~CircularLinkedList();

    Status Init();          // ��ʼ������
    Status Destroy();       // ��������

    bool IsCircularList();  // �ж��Ƿ�Ϊѭ������

    int Length();           // ��������(��Ч�ڵ�)�ڵ����
    bool IsEmpty();         // �����Ƿ�Ϊ��
    Status Insert(int pos, int value);  // ��ָ��λ�������ڵ�, ����������
    Status Remove(int pos);  // ɾ��ָ��λ�ýڵ�
    int GetValue(int pos);   // ��ȡָ��λ�ýڵ�����
    Node* GetAddress(int pos); // ��ȡ֪��λ�ýڵ�ĵ�ַ
    int SearchPosition(int value); // ������һ�����ֵ�Ԫ��ֵ�Ľڵ�λ��
    Status Update(int pos, int value); // ����ָ��λ�ýڵ�����
    Status ClearList(); // �����������(������ͷ�ڵ�)
    Status PrintList(); // ˳���ӡ����ڵ�����
    Status ReverseList();   // ��ת����
};

#endif /* CIRCULARLINKEDLIST_H_ */
