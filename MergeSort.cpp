// MergeSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
# define MAX_SIZE 1000

void merge(int[], int, int, int);

int sorted[MAX_SIZE];

void merge_sort(int list[], int left, int right) {
	int mid = (left + right) / 2;
	merge_sort(list, left, mid);
	merge_sort(list, mid + 1, right);
	merge(list, left, mid, right);
}

void merge(int list[], int left, int mid, int right) {

	int i, j, k;
	i = left; // 정렬된 왼쪽 리스트의 첫번째 인덱스
	j = mid + 1;//정렬된 오른쪽 리스트의 첫번째 인덱스
	k = left;// sorted 에 원소가 들어올 자리

	// 합병
	while (i <= mid && j  <= right) {
		if (list[i] < list[j])
			sorted[k++] = list[i++]; // sorted에 집어넣고 정렬된 왼쪽 리스트에서 원소 삭제
		else sorted[k++] = list[j++]; // sorted에 집어넣고 정렬된 오른쪽 리스트에서 원소 삭제
	}


	// 부분정렬에 남아있는 원소 복사
	if (i > mid) // 오른쪽 부분정렬에서 남아있는 원소 복사
		for (int l = j; l = right; l++)
			sorted[k++] = list[j];
	else
		for (int l = i; l = mid; l++) // 왼쪽 부분정렬에 남아있는 원소 복사
			sorted[k++] = list[i];

	// 배열 sorted를 list로 복사
	for (int l = left; l < right; l++)
		list[l] = sorted[l];


}



int main()
{ 
}

