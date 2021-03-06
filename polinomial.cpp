// polinomial.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#define MAX(a,b) (a>b?a:b)
#define MAX_DEGREE 101

typedef struct {
	int degree;
	int coef[MAX_DEGREE];
}polynomial;

polynomial poly_add1(polynomial a, polynomial b) {
	polynomial c;

	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = a.degree;
	int degree_b = b.degree;
	c.degree = MAX(a.degree, b.degree);

	while (Apos <= a.degree&Bpos <= b.degree) {

		if (degree_a > degree_b) {
			c.coef[Cpos++] = a.coef[Apos++];
			degree_a--;
		}

		else if (degree_a == degree_b) {
			c.coef[Cpos++] = a.coef[Apos++] + b.coef[Bpos++];
			degree_a--; degree_b--;
		}

		else{
			c.coef[Cpos++] = b.coef[Bpos++];
			degree_b--;
		}
	}


	return c;
}

int main()
{
	polynomial a = { 5,{3,6,0,0,10} };
	polynomial b = { 4, {7,0,7,5,1} };
	polynomial c = poly_add1(a, b);
	//printf("%d",c.degree);
	for (int i = 0; i < c.degree; i++) {
		printf("%d", c.coef[i]);
	}

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
