#pragma once
#include <stdio.h>
#include <string.h>
#define MAX_WORD_SIZE 40
#define MAX_MEANING_SIZE 200

class Record
{
protected:
	char word[MAX_WORD_SIZE];		// 단어: 키 필드
	char meaning[MAX_MEANING_SIZE];	// 의미
public:
	Record(char* word = (char*)"", char* meaning = (char*)"") { set(word, meaning); }	// 생성자
	~Record() {}
	void set(char* w, char* m) {	// 데이터 word와 meaning 설정
		strcpy(word, w);
		strcpy(meaning, m);
	}
	int compare(Record *n) { return compare(n->word); }  // 단어 비교 (인자: 객체 변수)
	int compare(char* w) { return strcmp(w, word); }        // 단어 비교 (인자: word 변수)
	int compareMeaning(char* m) { return strcmp(meaning, m); }  //의미 비교 (인자: m 변수)
	void display() { printf(" %12s : %-40s\n", word, meaning); } //단어, 의미 디스플레이
	void copy(Record *n) { set(n->word, n->meaning); }        // 인자 n을 this에 복사
};
