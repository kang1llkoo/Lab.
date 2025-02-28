#include <stdio.h>
#include <stdlib.h>
#define max_element 100

// 힙에 대한 1차원 배열과 힙 원소의 개수를 구조체로 묶어 선언
typedef struct {
	int heap[max_element];
	int size;
} heaptype;

// 공백 힙 생성
heaptype* createheap() {
	heaptype* h = (heaptype*)malloc(sizeof(heaptype));
	h->size = 0;
	return h;
}

// 힙에 item 삽입
void insertheap(heaptype* h, int item) {
	int i;
	h->size = h->size + 1;
	i = h->size;
	while ((i != 1) && (item > h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

// 힙의 루트를 삭제하여 반환
int deleteheap(heaptype* h) {
	int parent, child;
	int item, temp;
	item = h->heap[1];
	temp = h->heap[h->size];
	h->size = h->size - 1;
	parent = 1;
	child = 2;
	while (child <= h->size) {
		if ((child < h->size) && (h->heap[child]) < h->heap[child + 1])
			child++;
		if (temp >= h->heap[child]) break;
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;
	return item;
}

// 1차원 배열 힙의 내용 출력
void printheap(heaptype* h) {
	int i;
	printf("Heap : ");
	for (int i = 1; i <= h->size; i++) {
		printf("[%d] ", h->heap[i]);
	}
}

void main() {
	int i, n, item;
	heaptype* heap = createheap();
	insertheap(heap, 10);
	insertheap(heap, 45);
	insertheap(heap, 19);
	insertheap(heap, 11);
	insertheap(heap, 96);

	printheap(heap);

	n = heap->size;
	for (i = 1; i <= n; i++) {
		item = deleteheap(heap);
		printf("\n delete : [%d] ", item);
	}
}