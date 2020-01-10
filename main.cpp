#include "Dictionary.h"
#include <conio.h>

void help() {
	printf("[����] i-�߰� d-���� w-�ܾ�˻� m-�ǹ̰˻� p-��� q-���� =>");
}

// ���� Ž�� Ʈ���� ����ϴ� ���� ���� ���α׷� 
void main()
{
	char command;
	char word[80];
	char meaning[200];
	Dictionary tree;

	do {
		help();
		command = getche();	// ���� �Է�
		printf("\n");
		switch (command) {
		case 'i':
			printf("  > ���� �ܾ�: "); gets(word);		// string �Է� : word
			printf("  > �ܾ� ���� : "); gets(meaning);		// string �Է� : meaning
			tree.insert(new BinaryNode(word, meaning));
			break;
		case 'd':
			printf("  > ���� �ܾ�: "); gets(word);  // word: ������ �ܾ� �Է��� �޴´�.
			tree.remove(word);
			break;
		case 'p':
			tree.printAllWords();  // BST�� �ִ� ��� ��带 ����Ʈ�Ѵ�.
			printf("\n");
			break;
		case 'w':
			printf("  > �˻� �ܾ�: "); gets(word);  // word: �˻��� ���ܾ �Է��� �޴´�.
			tree.searchWord(word);
			break;
		case 'm':
			printf("  > �˻� �ǹ�: "); gets(word);	 // word: �˻��� ���ǹ̡� �Է��� �޴´�.
			tree.searchMeaning(word);
			break;
		}
	} while (command != 'q');
}
