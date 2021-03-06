// TopologicalSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 100
#define MAX_VERTICES 100

// 배열을 이용한 스택의 구현
typedef int element;
typedef struct {
	element stack[MAX];
	int top;
}StackType;

//스택 초기화
void init(StackType *s) {
	s->top = -1;
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

//삽입
void push(StackType *s, element item) {
	s->stack[++(s->top)] = item; //s->top을 증가시킨 후 item을 top에 삽입
}

//삭제
element pop(StackType *s) {
	return s->stack[(s->top)--];//s->stack[s->top]을 반환한 후 top 증가
}

// 그래프 노드
typedef struct GraphNode {
	int vertex;
	struct GraphNode *link;
}GraphNode;

// 그래프
typedef struct GraphType {
	int n; // 정점의 개수
	GraphNode *adj_list[MAX_VERTICES]; // 인접리스트
	GraphNode *tail_pointer[MAX_VERTICES];
}GraphType;

// 그래프 초기화
void init_graph(GraphType *g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		g->adj_list[i] = NULL;
	}
	for (int i = 0; i < MAX_VERTICES; i++) {
		g->tail_pointer[i] = NULL;
	}
}

void top_sort(GraphType *g) {

	StackType s;
	GraphNode *node;

	// 진입차수 배열 생성
	int *in_degree = (int *)malloc(g->n * sizeof(int)); 
	
	// 초기화
	for (int i = 0; i < g->n; i++) 
		in_degree[i] = 0; 

	// 진입차수
	for (int i = 0; i < g->n; i++) {

		GraphNode *node = g->adj_list[i];

		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	init(&s);

	// 진입차수가 0인 노드의 vertex값 찾기
	for (int i = 0; i < g->n; i++)
		if (in_degree[i] == 0)
			push(&s, i);

	// 노드 출력
	printf("위상정렬 결과 : ");
	if (is_empty(&s)) {
		printf("impossible\n");
		return;
	}
	while (!is_empty(&s)) {

		int w = pop(&s); 

		printf("%d ", w);

		node = g->adj_list[w];

		while (node != NULL) {
			int u = node->vertex;
			in_degree[u]--; // 출럭된 정점의 에지 제거
			if (in_degree[u] == 0)
				push(&s, u);
			node = node->link;
		}
	}

	for (int i = 0; i < g->n; i++) {
		if (in_degree[i] != 0) {
			printf("impossible\n");
			return;
		}
	}
		;

	free(in_degree);
	printf("\n");

	return;
}

GraphType* build_graph(char file_name[]) {

	FILE *rf = fopen(file_name, "r");
	char buffer[100];
	fgets(buffer, sizeof(buffer), rf);
	char *ptr;
	ptr = strtok(buffer, " ");
	int number_of_vertices = atoi(ptr); // 정점의 수
	ptr = strtok(NULL, " ");
	int number_of_edges = atoi(ptr); // 에지의 수

	int arr[MAX_VERTICES];
	
	int j = 0;
	for (int i = 0; i < number_of_edges; i++) {
		fgets(buffer, sizeof(buffer), rf);
		ptr = strtok(buffer, " ");

		while (ptr != NULL) {
			arr[j] = atoi(ptr); // 이하 정수를 arr 배열에 저장
			j++;
			ptr = strtok(NULL, " ");
		}

	}

	fclose(rf);


	GraphType *g = (GraphType *)malloc(sizeof(GraphType));
	init_graph(g);
	g->n = number_of_vertices;
	

	for (int i = 0; i < number_of_edges; i++) { // i번째 에지

		GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));

		int a = arr[2 * i]; 
		int b = arr[2 * i + 1]; // 에지 <a,b>

		// 인접 리스트 시작
		if ((g->tail_pointer[a]) == NULL) {
			
			g->adj_list[a]= node;

			node->vertex = b;
			node->link = NULL;

			g->tail_pointer[a] = g->adj_list[a];

			printf("\n[%d]", a);
			printf("- %d", b);
			

		}

		// 인접 리스트에 노드 연결
		else {
			
			g->tail_pointer[a]->link = node;

			node->vertex = b;
			node->link = NULL;

			g->tail_pointer[a] = g->tail_pointer[a]->link;

			printf("- %d", b);
			
		}
		
	}
	printf("\n");
	return g;

}


int main()
{
	char file1[] = "C:/Users/OWNER/Desktop/dag/dag1.txt";
	char file2[] = "C:/Users/OWNER/Desktop/dag/dag2.txt";
	char file3[] = "C:/Users/OWNER/Desktop/dag/dag3.txt";
	char file4[] = "C:/Users/OWNER/Desktop/dag/dag4.txt";
	char file5[] = "C:/Users/OWNER/Desktop/dag/dag5.txt";

	printf("\n-----[dag1]-----");
	GraphType *g1 = build_graph(file1);
	top_sort(g1);

	printf("\n-----[dag2]-----");
	GraphType *g2 = build_graph(file2);
	top_sort(g2);

	printf("\n-----[dag3]-----");
	GraphType *g3 = build_graph(file3);
	top_sort(g3);

	printf("\n-----[dag4]-----");
	GraphType *g4 = build_graph(file4);
	top_sort(g4);

	printf("\n-----[dag5]-----");
	GraphType *g5 = build_graph(file5);
	top_sort(g5);

	// 기후에너지 시스템공학과 1773139 장다솜
}

