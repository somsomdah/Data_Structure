
// GraphSearch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
# define MAX_VERTICES 100



// 1. DFS

typedef struct GraphNode {
	int vertex;
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
	int n; // 정점의 개수
	GraphNode *adj_list[MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];

void dfs_list(GraphType *g, int v) {
	
	visited[v] = true;

	printf("%d", v);
	for (GraphNode *w = g->adj_list[v]; w; w = w->link) // w에 인접한 정점들에 대하여
		if (!visited[w->vertex])// 방문하지 않았으면
			dfs_list(g, w->vertex); // 인접 정점을 시작정접으로 하여 dfs 수행

}

void bfs_list(GraphType *g, int v) {
	
	QueueType q;

	visited[v] = true;
	printf("%d", v);

	enqueue(&q, v); // 큐에 정점 삽입

	while (!is_empty(&q)) {

		v = dequeue(&q); // 큐에서 정점 제거

		for (GraphNode *w = g->adj_lsit[v]; w; w = w->link) { // 인접리스트 방문

			if (!visited[w->vertex]) { // 방문하지 않은 정점

				visited[w->vertex] = true;
				printf("%d", w->vertex);
				enqueue(&q, w->vertex); // 큐에 삽입
			}
		}
	}





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
