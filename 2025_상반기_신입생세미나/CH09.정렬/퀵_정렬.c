#include <stdio.h>
typedef int element;
int size, i = 0;

// 주어진 부분집합 내 피벗 위치 확정하여 분할 위치를 정하는 연산
int partition(element a[], int begin, int end) {
	int pivot, L, R, t;
	element temp;
	L = begin;
	R = end;
	pivot = (int)((begin + end) / 2.0); // 중간 위치 원소를 피벗으로 선택

	printf("\n [ %d단계 : pivot = %d ] \n", ++i, a[pivot]);
	while (L < R) {
		while ((a[L] < a[pivot]) && (L < R)) L++;
		while ((a[R] >= a[pivot]) && (L < R)) R--;
		if (L < R) { // L과 R의 원소를 자리 교환
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;

			if (L == pivot) // L이 피벗인 경우
				pivot = R; // 변경된 피벗 위치 저장
		} // if (L < R)
	} // while(L < R)

	// (L=R)이 된 경우,
	// 더 이상 진행할 수 없으므로 R 원소와 피벗 원소의 자리를 교환하여 마무리
	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;
	for (t = 0; t < size; t++) printf(" %d", a[t]); // 현재의 정렬 상태 출력
	printf("\n");
	return R; // 정렬되어 확정된 피벗의 위치 반환
}

void quicksort(element a[], int begin, int end) {
	int p;
	if (begin < end) {
		p = partition(a, begin, end); // 피벗 위치에 의해 분할 위치 결정
		quicksort(a, begin, p - 1); // 피벗 왼쪽 부분집합에 대해 퀵 정렬 재귀호출
		quicksort(a, p + 1, end); // 피벗 오른쪽 부분집합에 대해 퀵 정렬 재귀호출
	}
}

void main() {
	element list[8] = { 69, 10, 30 ,2, 16, 8, 31, 22 };
	size = 8;
	printf("\n [초기 상태] \n");
	for (int i = 0; i < size; i++) printf(" %d", list[i]);
	printf("\n");

	quicksort(list, 0, size - 1);
}