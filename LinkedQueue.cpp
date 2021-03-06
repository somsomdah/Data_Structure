// LinkedQueue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

typedef int element;

typedef struct QueueNode{
	int data;
	struct QueueNode *link;
}QueueNode;

typedef struct {
	struct QueueNode *front;
	struct QueueNode *rear;
}LinkedQueue;

// 삽입
void enqueue(LinkedQueue *q, element item) {
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode)); //새로운 노드
	if (temp == null)
		printf("메모리 할당 에러");
	else {
		temp->data = item;
		temp->link = NULL;
		/* if(is_empty(q)){
			q->front=temp;
			q->rear=temp;
			else{
		*/
		(q->rear)->link = temp;//큐의 마지막이었던 곳이 가리키는 곳 : 새로운 노드
		q->rear = temp;//큐의 마지막 : 새로운 노드
	}
}

//삭제
element dequeue(LinkedQueue *q) {
	QueueNode *temp = q->front; //temp은 큐의 처음
	element item = temp->data;;

	//if(is empty(q)) 
	//printf("큐가 공백상태"
	//else
	q->front = (q->front)->link;//q의 front 바꾸기
	if (q->front == NULL)//삭제 후 공백상태
		q->rear == NULL;
	free(temp);//temp 메모리 반납
	return item;
}


int main()
{
    std::cout << "Hello World!\n"; 
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
