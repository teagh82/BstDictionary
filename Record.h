#pragma once
#include <stdio.h>
#include <string.h>
#define MAX_WORD_SIZE 40
#define MAX_MEANING_SIZE 200

class Record
{
protected:
	char word[MAX_WORD_SIZE];		// �ܾ�: Ű �ʵ�
	char meaning[MAX_MEANING_SIZE];	// �ǹ�
public:
	Record(char* word = (char*)"", char* meaning = (char*)"") { set(word, meaning); }	// ������
	~Record() {}
	void set(char* w, char* m) {	// ������ word�� meaning ����
		strcpy(word, w);
		strcpy(meaning, m);
	}
	int compare(Record *n) { return compare(n->word); }  // �ܾ� �� (����: ��ü ����)
	int compare(char* w) { return strcmp(w, word); }        // �ܾ� �� (����: word ����)
	int compareMeaning(char* m) { return strcmp(meaning, m); }  //�ǹ� �� (����: m ����)
	void display() { printf(" %12s : %-40s\n", word, meaning); } //�ܾ�, �ǹ� ���÷���
	void copy(Record *n) { set(n->word, n->meaning); }        // ���� n�� this�� ����
};
