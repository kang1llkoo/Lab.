#include <stdio.h>
#include <stdlib.h>
#define max_element 100

// ���� ���� 1���� �迭�� �� ������ ������ ����ü�� ���� ����
typedef struct {
	int heap[max_element];
	int size;
} heaptype;

// ���� �� ����
heaptype* createheap() {
	heaptype* h = (heaptype*)malloc(sizeof(heaptype));
	h->size = 0;
	return h;
}

// ���� item ����
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

// ���� ��Ʈ�� �����Ͽ� ��ȯ
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

// 1���� �迭 ���� ���� ���
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