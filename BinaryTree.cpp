// BinaryTree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

//중순위 운행
void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}
}

//전순위 운행
void preorder(TreeNode *root) {
	if (root) {
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//후순위 운행
void postorder(TreeNode *root){
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->data);
	}
	}


int get_node_count(TreeNode *node) {
	int count = 0;
	if (node != NULL) {
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	}
	return count;
}


int main(){
	/*
	TreeNode *n1, *n2, *n3;
	n1 = (TreeNode *)malloc(sizeof(TreeNode));
	n2 = (TreeNode *)malloc(sizeof(TreeNode));
	n3 = (TreeNode *)malloc(sizeof(TreeNode));

	n1->data=10; n1->left=n2; n1->right=n3;
	n2->data=10; n2->left=NULL; n2->right=NULL;
	n3->data=10; n3->left=NULL; n3->right=NULL;
	*/
	
	TreeNode n1 = { 1,NULL,NULL };
	TreeNode n2 = { 4,&n1,NULL };
	TreeNode n3 = { 16, NULL,NULL };
	TreeNode n4 = { 25,NULL,NULL };
	TreeNode n5 = { 20,&n3,&n4 };
	TreeNode n6 = { 20,&n2,&n5 };
	TreeNode *root = &n6;
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
