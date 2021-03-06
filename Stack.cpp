// Stack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#define max 100

// 배열을 이용한 스택의 구현
typedef int element;
typedef struct{
	element stack[max];
	int top;
}Stack;

//스택 초기화
void init(Stack *s) {
	s->top = -1;
}

//공백상태 검출
int is_empty(Stack *s) {
	return (s->top == -1);
}

//포화상태 검출
int is_full(Stack *s) {
	return(s->top == max - 1);
}

//삽입
void push(Stack *s, element item) {
	s->stack[++(s->top)] = item; //s->top을 증가시킨 후 item을 top에 삽입
}

element pop(Stack *s, element item) {
	return s->stack[(s->top)--];//s->stack[s->top]을 반환한 후 top 증가
}

// peek
element peek(Stack *s) {
	return s-> stack[s->top];
}

int main()
{
}

