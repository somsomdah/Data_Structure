// Heap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

typedef struct {
	int key;
}element;

typedef struct {
	int heap_size; // heap의 크기(노드의 갯수)
	element heap[sizeof(heap_size)/sizeof(int)]; // 힙을 저장하는 배열
}HeapType;

void init(HeapType *h) {

	h->heap_size = 0;
}


//삽입 프로그램 (upheap)
void insert_max_heap(HeapType *h, element item){
	int i;
	i = ++(h->heap_size); // heap_size를 증가시키고 i에 대입

	while (i != 1 && (item.key > h->heap[i / 2].key)) { // i는 현재노드,item의 값이 heap의 부모노드보다 크면
		h->heap[i] = h->heap[i / 2]; //부모노드 끌어내림
		i /= 2;// 탐색 위치 이동 
	} // 최종결과 : i= 새로운 노드의 위치 인덱스

	h->heap[i] = item; // 알맞은 위치에 item 삽입
}

// 삭제 (downheap) : max heap의 경우 최대값 반환
element delete_max_heap(HeapType *h){

	int parent, child; // parent=현재위치 인덱스, child는 자식노드 인덱스
	element item, temp;
	item = h->heap[1];//heap의 첫번째 원소(가장 큰 원소), retrun 값
	temp = h->heap[(h->heap_size)--]; // heap의 마지막 원소를 temp에 저장하고 heap_size 감소
	parent = 1, child = 2; // 부모노드와 자식노드의 인덱스

	while (child <= h->heap_size) { // 자식노드의 인덱스가 heap_size를 넘어가지 않는다면(배열의 끝까지 탐색)

		if((child < h->heap_size)&&(h->heap[child].key < h->heap[child+1].key))//왼쪽 자식노드의 크기가 작다면
			child++; // 결과 : child는 자식노드 중 큰 값의 인덱스가 됨

		if (temp.key >= h->heap[child].key)
			break; // 마지막원소보다 child에 있는 원소가 작거나 같다면(위치 찾음), break

		h->heap[parent] = h->heap[child]; // 자식 원소자리를 끌어올린다.;

		parent = child; // 현재위치 변경(자식노드 중 큰 값의 인덱스로)
		child *= 2;
	}

	h->heap[parent] = temp;
	return item;


}

void heap_sort(element a[], int n) {
	int i;
	HeapType h;

	init(&h);
	for (i = 0; i < n; i++)
		insert_max_heap(&h, a[i]);

	for (i = n - 1; i > 0; i--)
		a[i] = delete_max_heap(&h);
}

int main()
{

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
