// BinarySerchTree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>


typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode
;

//탐색 - 재귀
TreeNode *search(TreeNode *node, int key) {

	if (key == NULL)
		return NULL;

	if (node->data == key)
		return node;
	else if (key < node->data)
		return search(node->left, key);
	else
		return search(node->right, key);
}


//탐색 - 반복
TreeNode *search2(TreeNode *node, int key) {

	while (node != NULL) {
		if (key == node->data)
			return node;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}

	return NULL;
}

// 삽입 연산
void insert_node(TreeNode **root, int key) { // root는 트리의 노드를 가리키는 포인터의 포인터, key는 삽입할 값
	TreeNode *p, *t; // t는 방문 위치, p는 현재 위치의부모노드

	// 삽입 위치 찾기
	while (t != NULL) {
		if (key == t->data)
			return; // key 값이 트리 안에 있다면 삽입 불가

		// 자식 노드로 내려가면서 삽입 위치 찾기
		p = t;
		if (key < t->data)
			t = t->left;
		else
			t = t->right;

		// 최종 t 노드가 삽입 될 위치
	}

	//노드 삽입
	TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode)); 
	n->data = key;
	n->left = n->right = NULL;

	// 삽입된 노드와 부모 노드 연결
	if (p != NULL) {
		if (key < p->data)
			p->left = n;
		else
			p->right = n;
	}
	else
		*root = n; // p==NULL(부모가 없음)이라면 새로 삽입된 노드가 루트, 즉 빈 트리에 삽입됨
}


// 삭제

void delete_node(TreeNode **root, int key) {

	TreeNode *t, *p, *child, *succ, *succ_p;// 방문위치(삭제 노드), t의 부모노드, t의 자식노드,선행자,succ의 부모노드
	p = NULL, t = *root;
	
	//key를 갖는 노드(삭제하려는 노드) 탐색
	while (t != NULL && t->data != key) {
		p = t;
		t = (key < t->data) ? t->left : t->right; //최종 t는 key의 위치
	}
	if (t == NULL) { // 트리에 키가 없을 경우
		printf("key is not in tree");
		return;
	}

	// a) 자식이 없는 경우 - 삭제할 노드가 단말노드인 경우
	if (t->left == NULL && t->right == NULL) {
		if (p != NULL) {
			if (p->left == t)
				p->right = NULL;
			else
				p->left = NULL;
		}
		else // 루트를 삭제한 경우
			*root = NULL;
	}

	//b) 자식이 하나인 경우
	else if (t->left == NULL || t->right == NULL) {

		child = (t->left != NULL) ? t->left : t->right;

		if (p != NULL) {
			if (p->left == t)
				p->left = child;
			else
				p->right = child;
		}
		else
			*root = NULL;
	}

	//c) 자식이 두 개인 경우 - 삭제되는 위치에 계승자 삽입
	else {

		succ_p = t;
		succ = t->right; // 계승자 : 중순위 후계자

		// 계승자 찾기
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}

		// 계승자의 부모와 계승자의 자식을 연결
		if (succ_p->left = succ) {
		succ_p->left = succ->right;
		succ_p->right = succ->right;
		}

		// 계승자를 삭제된 위치 t에 삽입(키 값 복사)
		t->data= succ->data;
		t = succ;
	}
	free(t);

}


int main()
{
    std::cout << "Hello World!\n"; 
}

