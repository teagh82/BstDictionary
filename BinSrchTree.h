#include "binaryTree.h"
class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void) { }
	~BinSrchTree(void){ }

	BinaryNode* search( char* key ) {
	    BinaryNode* node = search ( root, key );  //!!! parent class����:root=> protected
	    if( node != NULL )
		//printf("Ž�� ����: Ű���� %d�� ���= 0x%x\n", node->getData(), node );
		printf("");
	    else
		//printf("Ž�� ����: Ű���� %d��I ��� ����\n", key );
		printf("");
	    return node;
	}

	BinaryNode* search( BinaryNode *n, char* key ) {
	    if( n == NULL ) return NULL;
   	    if( n->compare(key) == 0 ) return n;
	    else if ( n->compare(key) < 0 ) return search( n->getLeft(), key );
	    else return search( n->getRight(), key );
	}

	void insert( BinaryNode* n ) {
		if( n == NULL ) return;
		if( isEmpty() ) root = n;
		else insert( root, n );
	}

	void insert( BinaryNode* r, BinaryNode* n ) {
		if( n->compare(r) == 0 ) return;
		else if( n->compare(r) > 0 ) {
			if( r->getLeft() == NULL ) r->setLeft(n);
			else insert( r->getLeft(), n );
		}
		else {
			if( r->getRight() == NULL ) r->setRight(n);
			else insert( r->getRight(), n );
		}
	}

	//���� ��������
	void remove(char* data) {
		if (isEmpty()) return;

		BinaryNode *parent = NULL;
		BinaryNode *node = root;

		while (node != NULL && node->compare(data) != 0) {
			parent = node;
			node = ( node->compare(data) < 0)
				? node->getLeft()
				: node->getRight();
		}

		if (node == NULL) {
			printf("    >> ��ϵ��� ���� �ܾ�! : ");
			printf(data);
			printf("\n");
			return;
		}
		else remove(parent, node);
	}

	void remove(BinaryNode *parent, BinaryNode *node) {
		// case 1
		if (node->isLeaf()) {
			if (parent == NULL) root = NULL;
			else {
				if (parent->getLeft() == node) parent->setLeft(NULL);
				else parent->setRight(NULL);
			}
		}
		// case 2
		else if (node->getLeft() == NULL || node->getRight() == NULL) {
			BinaryNode *child = (node->getLeft() != NULL)
				? node->getLeft()
				: node->getRight();
			if (node == root) root = child;
			else {
				if (parent->getLeft() == node) parent->setLeft(child);
				else parent->setRight(child);
			}
		}
		// case 3
		else {
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();
			while (succ->getLeft() != NULL) {
				succp = succ;
				succ = succ->getLeft();
			}

			if (succp->getLeft() == succ) succp->setLeft(succ->getRight());
			else succp->setRight(succ->getRight());

			node->setData(succ->getData());
			node = succ;
		}
		delete node;
	}  // end of remove()

	//���ο� ��������
	void newRemove(char* data) {
		if (isEmpty()) return;

		BinaryNode *parent = NULL;
		BinaryNode *node = root;

		while (node != NULL && node->compare(data) != 0) {
			parent = node;
			node = ( node->compare(data) < 0)
				? node->getLeft()
				: node->getRight();
		}

	if( node == NULL ) {
		printf("    >> ��ϵ��� ���� �ܾ�! : ");
		printf(data);
		printf("\n");
		return;
	}
	else newRemove ( parent, node );
}

	void newRemove (BinaryNode *parent, BinaryNode *node) {
	// case 1
	if( node->isLeaf() ) {
		if( parent == NULL ) root = NULL;
		else {
			if( parent->getLeft() == node ) parent->setLeft(NULL);
			else parent->setRight(NULL);
		}
	}
	// case 2
	else if( node->getLeft()== NULL|| node->getRight()==NULL ) {
		BinaryNode *child = (node->getLeft() != NULL )
			? node->getLeft()
			: node->getRight();
		if( node == root ) root = child;
		else {
			if( parent->getLeft() == node ) parent->setLeft(child); 
			else parent->setRight(child); 
		}
	}
	// case 3
	else {
		BinaryNode* succp = node;
		BinaryNode* succrp = node;
		BinaryNode* succ = node->getRight();
		BinaryNode* succr = node->getLeft();

		while (succ->getLeft() != NULL) {
			succp = succ;
			succ = succ->getLeft();
		}

		while (succr->getRight() != NULL) {
			succrp = succr;
			succr = succr->getRight();
		}

		if ((node->getData() - succr->getData()) > (succ->getData() - node->getData())) {	//���ʼ���Ʈ�� �� ���� ū ���� ����� ���̰� ������ ����Ʈ�� �� ���� ���� ������ ������ ũ�ٸ�
			if( succp->getLeft() == succ ) succp->setLeft(succ->getRight());
			else succp->setRight(succ->getRight());
			node->setData(succ->getData());
			node = succ;
		}
		else {
			if (succrp->getRight() == succr) succrp->setRight(succr->getLeft());
			else succrp->setLeft(succr->getLeft());
			node->setData(succr->getData());
			node = succr;
		}

		
	}
	delete node;
  }  // end of newRemove()
};  // end of class BinSrchTree
