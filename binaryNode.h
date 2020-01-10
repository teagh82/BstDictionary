#ifndef _binaryNode
#define _binaryNode
#include <stdio.h>
#include <stdlib.h>
#include "Record.h"

class BinaryNode : public Record
{
protected:
	int data;
	BinaryNode*left;
	BinaryNode *right;

public:
	BinaryNode(char* w, char* m, int val = 0, BinaryNode *l = NULL, BinaryNode *r = NULL)
		:data(val), left(l), right(r){set(w, m);}
	~BinaryNode(){}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode *l) { left = l; }
	void setRight(BinaryNode *r) { right = r; }
	int	 getData() { return data; }
	BinaryNode*	getLeft() { return left; }
	BinaryNode*	getRight() { return right; }
	bool isLeaf() { return left == NULL && right == NULL; }


};

#endif





