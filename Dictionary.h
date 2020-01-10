#pragma once
#include "BinSrchTree.h"

class Dictionary : public BinSrchTree
{
public:
	Dictionary(void) { }
	~Dictionary(void) { }

	void printAllWords() {         // BST�� ��� ��� ��� : �� ������ ��� �ܾ� ���
		printf("    >> ���� �ܾ���:\n");
		if (!isEmpty()) inorder(root);  // inorder()�� ��� ��� ���
	}

	void searchWord(char* word) { // ���� word�� BST Ž��
		BinaryNode *node = search(word);
		if (node != NULL) {  // ��带 ã������
			printf("    >> ");
			node->display();	// ��� ���÷���
		}
		else		// ��带 �� ã������
			printf("    >> ��ϵ��� ���� �ܾ�: %s\n", word);
	}
	void searchMeaning(char *m) {
		BinaryNode *node = (isEmpty()) ? NULL : searchByMeaning(root, m);
		if (node != NULL) {  	// ��带 ã������
			printf("    >> ");
			node->display();	// ��� ���÷���
		}
		else		 	// ��带 �� ã������
			printf("    >> ��ϵ��� ���� �ǹ�: %s\n", m);
	}

	BinaryNode *searchByMeaning(BinaryNode *node, char* m) {
		if (node == NULL || node->compareMeaning(m) == 0)	// �ǹ� m���� Ž��
			return node;

		BinaryNode *theNode = searchByMeaning(node->getLeft(), m);  // left ����Ʈ������ Ž��
		if (theNode != NULL) return theNode;

		return searchByMeaning(node->getRight(), m);	// right ����Ʈ������ Ž��
	}
};
