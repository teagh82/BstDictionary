#pragma once
#include "BinSrchTree.h"

class Dictionary : public BinSrchTree
{
public:
	Dictionary(void) { }
	~Dictionary(void) { }

	void printAllWords() {         // BST의 모든 노드 출력 : 즉 사전의 모든 단어 출력
		printf("    >> 나의 단어장:\n");
		if (!isEmpty()) inorder(root);  // inorder()로 모든 노드 출력
	}

	void searchWord(char* word) { // 인자 word로 BST 탐색
		BinaryNode *node = search(word);
		if (node != NULL) {  // 노드를 찾았으면
			printf("    >> ");
			node->display();	// 노드 디스플레이
		}
		else		// 노드를 못 찾았으면
			printf("    >> 등록되지 않은 단어: %s\n", word);
	}
	void searchMeaning(char *m) {
		BinaryNode *node = (isEmpty()) ? NULL : searchByMeaning(root, m);
		if (node != NULL) {  	// 노드를 찾았으면
			printf("    >> ");
			node->display();	// 노드 디스플레이
		}
		else		 	// 노드를 못 찾았으면
			printf("    >> 등록되지 않은 의미: %s\n", m);
	}

	BinaryNode *searchByMeaning(BinaryNode *node, char* m) {
		if (node == NULL || node->compareMeaning(m) == 0)	// 의미 m으로 탐색
			return node;

		BinaryNode *theNode = searchByMeaning(node->getLeft(), m);  // left 서브트리에서 탐색
		if (theNode != NULL) return theNode;

		return searchByMeaning(node->getRight(), m);	// right 서브트리에서 탐색
	}
};
