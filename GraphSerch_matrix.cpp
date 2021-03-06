// GraphSerch_matrix.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "Queue.h"
#define MAX_VERTICES 100

typedef struct GraphNode {
	int vertex;
}GraphNode;

typedef struct GraphType {
	int n; // 정점의 개수
	GraphNode *adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];

// DFS 알고리즘
void dfs_mat(GraphType *g, int v) { // 그래프 g, 시작정점 v

	visited[v] = true; // 정점 방문 표시

	printf("d", v); // 방문한 정점 출력

	for (int w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w]) // 인접 정점에 대하여
			dfs_mat(g, w); // dfs serch 수행
	}
}

// BFS 알고리즘
void bfs_mat(GraphType *g, int v) {
	
	QueueType q;

	visited[v] = true; // 방문 여부 체크
	printf("%d", v);  // 정점 출력
	enqueue(&q, v); // 출력된 정점 큐에 저장

	while (!is_empty(&q)) {
		v = dequeue(&q);

		for(int w=0;w<g->n;w++)

			if (g->adj_mat[v][w] && !visited[w]) { // 인접한 정점들에 대하여

				visited[w] = true;
				printf("%d", w);
				enqueue(&q,w); // q에 저장
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
