// LinkedStack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

typedef int element;

//노드
typedef struct StackNode{
	element data; // 원소의 값
	struct StackNode *link; //원소가 가리키는 곳(그 다음 원소)
}StackNode;

//스택
typedef struct {
	StackNode *top; //스택에서 가장 마지막 노드
}LinkedStack;

void push(LinkedStack *s, element item){
	
	//Stacknode타입의 temp에 메모리 할당, 새로운 원소가 들어갈 자리
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	
	if (temp = NULL)
		return;
	else {
		temp->data = item; //새로운 원소의 데이터
		temp->link = s->top; //새로운 원소가 가리키는 곳=원래 스택의 top
		s->top = temp;//스택의 top
	}

}

element pop(LinkedStack *s) {

	if (s->top == NULL)
		return; // 아니면 exit(1)
	else {
		StackNode *temp = s->top;//temp는 가장 마지막 원소
		int item = temp->data;//item에 temp의 값 대입
		s->top = (s->top)->link; // 스택에서 가장 마지막 노드는 원래 마지막이었던 노드가 가리키는 곳
		free(temp);
		return item;
	}
	
}



int main()
{
    std::cout << "Hello World!\n"; 
}

