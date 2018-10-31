/*
 * Node.cpp
 *
 *  Created on: 2018Äê10ÔÂ22ÈÕ
 *      Author: Think
 */

#include "Node.h"
#include <cstdlib>

Node::Node() {
	data = 0;
	next = NULL;
}

Node::Node(Node* newNext, int newValue)
{
	data = newValue;
	next = newNext;
}

Node::~Node()
{
	// TODO Auto-generated destructor stub
}

