/*
 * LinkedList.h
 *
 *  Created on: 2018年10月22日
 *      Author: Think
 */

#ifndef CIRCULARLINKEDLIST_H_
#define CIRCULARLINKEDLIST_H_

#include "Node.h"


typedef int Status;

#define OK     0
#define ERROR  -1


/**
 * 单链表类
 * @description 带虚拟头节点
 */
class CircularLinkedList {
private:
	Node *head;
	Node *tail;

public:
	CircularLinkedList();
    virtual ~CircularLinkedList();

    Status Init();          // 初始化链表
    Status Destroy();       // 销毁链表

    bool IsCircularList();  // 判断是否为循环链表

    int Length();           // 求链表长度(有效节点)节点个数
    bool IsEmpty();         // 链表是否为空
    Status Insert(int pos, int value);  // 在指定位置生产节点, 并插入数据
    Status Remove(int pos);  // 删除指定位置节点
    int GetValue(int pos);   // 读取指定位置节点数据
    Node* GetAddress(int pos); // 获取知道位置节点的地址
    int SearchPosition(int value); // 搜索第一个出现的元素值的节点位置
    Status Update(int pos, int value); // 更新指定位置节点数据
    Status ClearList(); // 清除链表数据(不包含头节点)
    Status PrintList(); // 顺序打印链表节点数据
    Status ReverseList();   // 反转链表
};

#endif /* CIRCULARLINKEDLIST_H_ */
