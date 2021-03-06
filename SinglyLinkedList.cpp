// SinglyLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

typedef int element;

typedef struct ListNode {
	element data; // 데이터값
	struct ListNode *link; // link라는 ListNode 구조체 선언, 가리키는 곳의 주소
} ListNode;

// 삽입연산
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) {

	// 헤드의 포인터에 주소가 없는 경우== 공백리스트인 경우
	if (phead == NULL) {
		new_node->link = NULL; // 새로운 노드의 link값은 NULL
		*phead = new_node; // phead가 가리키는 주소의 내용은 new_node
	}
	// p값이 없는 경우 p가 마지막 노드(가리키는 곳 없음)
	else if (p == NULL) {
		new_node->link = *phead; // new node
		*phead = new_node;//첫번째 노드로 삽입
	}
	else { // 중간에 삽입
		new_node->link = p->link;//새로운 노드가 가리키는 곳=p가 가리키던 곳=p다음 노드
		p->link = new_node; // 선행노드가 가리키는 곳=새로운 노드

	}
}

//삭제 연산
void remove_node(ListNode **phead, ListNode *p, ListNode *removed) {

	if (p == NULL)
		*phead = (*phead)->link;//헤드가 가리키는 곳의 값=헤드 가리키던 곳
	else
		p->link = removed->link;//선행노드가 가리키는 곳=삭제된 노드가 가리키던 곳;
	free(removed); //메모리 반납
}

//방문 연산 : 리스트의 상위 노드를 순차적으로 방문하여 데이터를 출력
// 반복 기법
void visit_repeat(ListNode *head) {
	ListNode *p = head;// p가 가리키는 곳=헤드가 가리키는 곳(p에 저장된 주소=헤드에 저장된 주소)
	while (p != NULL) {
		printf("%d->",p->data);
		p = p->link; // p=p가 가리키는 곳의 주소
	}
	printf("\n");
}

// 재귀 기법
void visit_recur(ListNode *head) {
	ListNode* p = head;//p가 가리키는 곳=헤드가 가리키는 곳
	if (p != NULL) {
		printf("%d->", p->data);//p가 가리키는곳의 데이터 출력
		visit_recur(p->link);// p가 가리키는곳을 인자로 visit_recur를 다시 실행
	}
}

// 탐색 연산 : 데이터로 노드의 위치를 찾는 연산
ListNode *search(ListNode *head, int x) {
	ListNode *p = head; // p의 값 == head의 값, p가 가리키는 곳 ==head가 가리키는 곳

	while (p != NULL) { // p가 NUll이 아닌 동안에
		if (p->data == x)//
			return p;
		p = p->link;
	}
	return p;
}

//병합 연산
ListNode *concat(ListNode *head1, ListNode *head2) {
	ListNode* p;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else {
		p = head1;//p에 head1 대입(주소)
		while (p->link != NULL)//p가 가리키는 곳이 NULL이 아닌 동안
			p = p->link;//p는 p가 가리키는 곳
		//루프를 빠져나오면 p==head1의 마지막 노드
		p->link = head2;//p가 가리키는 곳==head2 : head1과 head2를 연결
		return head1;
	}	
}

//역순
ListNode *reverse(ListNode *head) {
	ListNode *p, *q, *r;
	//p : 아직 처리되지 않은 노드
	//q : 현재 역순으로 만든 노드
	//r : 이미 역순으로 만든 노드
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;//p==p가 가리키던 곳
		q->link = r;//q가 가리키는 곳==r
	}
	return q;
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
