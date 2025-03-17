#include <stdio.h>
#define max 30
typedef int element;
int size;
element sorted[max]; // 원소를 병합하변서 정렬할 상태로 저장할 배열

void merge(element a[], int m, int middle, int n) { 
	// merge(list, 0, 0, 1)
	// merge(list, 2, 2, 3)
	// merge(list, 0, 1, 3)
	int i, j, k, t;
	i = m; // 첫 번째 부분집합 시작 위치 설정
	j = middle + 1; // 두 번째 부분집합 시작 위치 설정
	k = m; // 배열 sorted에 정렬된 원소를 저장할 위치 설정

	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle) for (t = j; t <= n; t++, k++) sorted[k] = a[t];
	else for (t = i; t <= middle; t++, k++) sorted[k] = a[t];

	for (t = m; t <= n; t++) a[t] = sorted[t];
	printf("\n 병합 정렬 >> ");
	for (t = 0; t < size; t++)printf("%4d ", a[t]);
}

void mergeSort(element a[], int m, int n) {
	// mergeSort(list, 0, 3)
	// mergeSort(list, 0, 1)
	// mergeSort(list, 2, 3)
	int middle;
	if (m < n) {
		middle = (m + n) / 2;
		mergeSort(a, m, middle); // 앞부분에 대한 분할 작업 수행
		mergeSort(a, middle + 1, n); // 뒷부분에 대한 분할 작업 수행
		merge(a, m, middle, n); // 부분집합에 대해 정렬과 병합 작업 수행
	}
}

void main() {
	int t;
	element list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = 8;
	printf("\n 정렬할 원소 >> ");
	for (t = 0; t < size; t++) printf("%4d ", list[t]);

	printf("\n\n<<<<<<<<<< 병합 정렬 수행 >>>>>>>>>>\n");
	mergeSort(list, 0, size - 1);
}
