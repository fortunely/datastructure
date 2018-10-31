/*
 * Node.h
 *
 *  Created on: 2018��10��22��
 *      Author: Think
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	int data;
	Node *next;

public:
	Node();
	Node(Node* next, int value);
	virtual ~Node();
};

#endif /* NODE_H_ */
