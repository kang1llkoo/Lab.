#include <stdio.h>
#define SIZE 8

// 힙 재구성 함수 (최대 힙)
void makeheap(int a[], int h, int m) {
    int temp = a[h]; // 부모 노드 값 저장
    int j;

    for (j = 2 * h; j <= m; j *= 2) {
        if (j < m && a[j] < a[j + 1]) { // 두 자식 중 더 큰 값 선택
            j++;
        }

        if (temp >= a[j]) { // 부모가 자식보다 크다면 힙 성질 유지됨
            break;
        }

        a[j / 2] = a[j]; // 부모 노드를 자식 값으로 대체
    }
    a[j / 2] = temp; // 원래 부모 노드를 올바른 위치에 저장
}

// 힙 정렬
void heapsort(int a[], int n) {
    int i, temp;

    // 최대 힙 구성
    for (i = n / 2; i >= 1; i--) {
        makeheap(a, i, n);
    }

    // 정렬 수행
    for (i = n - 1; i >= 1; i--) {
        temp = a[1];     // 루트(최댓값)과 마지막 요소를 교환
        a[1] = a[i + 1];
        a[i + 1] = temp;

        makeheap(a, 1, i);
    }
}

int main() {
    int list[SIZE + 1] = { 0, 69, 10, 30, 2, 16, 8, 31, 22 }; // 1번 인덱스부터 사용
    int size = SIZE;

    printf("정렬 전 배열 : ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", list[i]);
    }

    heapsort(list, size);

    printf("\n정렬 후 배열 : ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", list[i]);
    }

    return 0;
}