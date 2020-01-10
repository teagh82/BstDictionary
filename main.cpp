#include "Dictionary.h"
#include <conio.h>

void help() {
	printf("[사용법] i-추가 d-삭제 w-단어검색 m-의미검색 p-출력 q-종료 =>");
}

// 이진 탐색 트리를 사용하는 영어 사전 프로그램 
void main()
{
	char command;
	char word[80];
	char meaning[200];
	Dictionary tree;

	do {
		help();
		command = getche();	// 문자 입력
		printf("\n");
		switch (command) {
		case 'i':
			printf("  > 삽입 단어: "); gets(word);		// string 입력 : word
			printf("  > 단어 설명 : "); gets(meaning);		// string 입력 : meaning
			tree.insert(new BinaryNode(word, meaning));
			break;
		case 'd':
			printf("  > 삭제 단어: "); gets(word);  // word: 삭제할 단어 입력을 받는다.
			tree.remove(word);
			break;
		case 'p':
			tree.printAllWords();  // BST에 있는 모든 노드를 프린트한다.
			printf("\n");
			break;
		case 'w':
			printf("  > 검색 단어: "); gets(word);  // word: 검색할 ‘단어’ 입력을 받는다.
			tree.searchWord(word);
			break;
		case 'm':
			printf("  > 검색 의미: "); gets(word);	 // word: 검색할 ‘의미’ 입력을 받는다.
			tree.searchMeaning(word);
			break;
		}
	} while (command != 'q');
}
