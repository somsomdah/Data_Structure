// ArrayListType.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#define MAX_LIST_SIZE 100

// element라는 타입 지정
typedef int element;  

// array list 구현
typedef struct { 
	int list[MAX_LIST_SIZE]; // list의 원소들을 저장하는 배열
	int length; // list의 길이
}ArrayListType;

// 리스트 초기화
void init(ArrayListType *L) {
	L->length = 0; // 리스트의 길이를 0으로 초기화
}

int is_empty(ArrayListType *L) {
	return (L->length == 0);
}

int is_full(ArrayListType *L) {
	return (L->length == MAX_LIST_SIZE);
}

// 삽입 연산
void add(ArrayListType *L, int position, element item) {

	// 리스트에 자리가 있고, 삽입하는 위치가 원소들 사이이면
	if (!is_full(L) && (position >= 0)&&(position<=L->length)) {

		// 리스트의 마지막부터 삽입하고자 하는 위치까지
		for (int i = L->length - 1; i >= position; i--)
			L->list[i + 1] = L->list[i]; // 리스트를 한칸씩 이동하여 삽입하려는 위치에 자리를 만듦
		L->list[position] = item; // 원소 삽입
		L->length++; // 리스트 길이 증가
	}
}

element delete_(ArrayListType *L, int position) {

	element item = L->list[position];
	for (int i = position; i < (L->length - 1); i++)
		L->list[i] = L->list[i + 1];

	L->length--;
	return item;
}

int main(){
	ArrayListType a, *p;
	p = &a;
	add(p, 1, 1);
	add(p, 1, 3);
	add(p, 2, 5);
	//int A[] = a.list;
	//printf("%s", a.list);
	for (int i = 0; i < a.length; i++) {
		printf("%d", p->list[i]);
	}

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
