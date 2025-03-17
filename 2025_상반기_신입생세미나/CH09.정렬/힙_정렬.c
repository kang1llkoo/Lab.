#include <stdio.h>
#define SIZE 4

// 힙 재구성 (최대 힙)
void makeheap(int a[], int h, int m) { 
    // makeheap(list, 부모 노드 index, 힙 크기)
    int temp = a[h]; // 부모 노드 값 저장
    int j;
    
    for (j = 2 * h + 1; j < m; j = 2 * j + 1) {
        // j = 왼쪽 자식, j+1 = 오른쪽 자식
        if (j + 1 < m && a[j] < a[j + 1]) { // 두 자식 중 더 큰 값 선택
            j++;
        }
        if (temp >= a[j]) { // 부모가 자식보다 크다면 힙 성질 유지됨
            break;
        }
        a[(j - 1) / 2] = a[j]; // 부모 노드를 자식 값으로 대체
    }
    a[(j - 1) / 2] = temp; // 원래 부모 노드를 올바른 위치에 저장
}

// 힙 정렬
void heapsort(int a[], int n) {
    int i, temp;

    // 최대 힙 구성
    for (i = (n - 2) / 2; i >= 0; i--) {
        makeheap(a, i, n);
    }

    // 정렬 수행
    for (i = n - 1; i > 0; i--) {
        temp = a[0];     // 루트(최댓값)과 마지막 요소를 교환
        a[0] = a[i];
        a[i] = temp;

        makeheap(a, 0, i);
    }
}

int main() {
    int list[SIZE] = {32, 10, 45, 8};
    int size = SIZE;

    printf("정렬 전 배열 : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }

    heapsort(list, size);

    printf("\n정렬 후 배열 : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }

    return 0;
}
