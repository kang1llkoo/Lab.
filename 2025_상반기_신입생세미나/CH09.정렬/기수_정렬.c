#include <stdio.h>
#include <stdlib.h>
#define radix 10 // ������ �ڷ���� Ű���� 10���� �� radix�� 10���� ����
#define digit 2 // ������ �ڷ���� Ű���� �� �ڸ� �� digit�� 2�� ����

// ť ����
typedef int element;

typedef struct qnode {
	element data;
	struct qnode* link;
} qnode;

typedef struct {
	qnode* front, * rear;
} lqueuetype;

lqueuetype* createlinkedqueue() {
	lqueuetype* lq;
	lq = (lqueuetype*)malloc(sizeof(lqueuetype));
	lq->front = NULL;
	lq->rear = NULL;
	return lq;
}

int isempty(lqueuetype* lq) {
	if (lq->front == NULL) return 1;
	else return 0;
}

void enqueue(lqueuetype* lq, element item) {
	qnode* newnode = (qnode*)malloc(sizeof(qnode));
	newnode->data = item;
	newnode->link = NULL;
	if (lq->front == NULL) {
		lq->front = newnode;
		lq->rear = newnode;
	}
	else {
		lq->rear->link = newnode;
		lq->rear = newnode;
	}
}

element dequeue(lqueuetype* lq) {
	qnode* old = lq->front;
	element item;
	if (isempty(lq)) return 0;
	else {
		item = old->data;
		lq->front = lq->front->link;
		if (lq->front == NULL)
			lq->rear = NULL;
		free(old);
		return item;
	}
}
// ť >>

// �迭 a�� �ִ� n�� ���ҿ� ���� ��� ���� ����
void radixsort(element a[], int n) {
	int i, bucket, d, factor = 1;

	// ������ �ڷ��� ���(radix)�� ���� �� ���� ��Ŷ�� ť�� ����
	lqueuetype* q[radix];
	for (bucket = 0; bucket < radix; bucket++)
		q[bucket] = createlinkedqueue();

	// Ű���� �ڸ�����ŭ(�� �� ��� ����) �ݺ� ����
	for (d = 0; d < digit; d++) {
		for (i = 0; i < n; i++)
			enqueue(q[(a[i] / factor) % radix], a[i]);
		for (bucket = 0, i = 0; bucket < radix; bucket++)
			while (!isempty(q[bucket])) a[i++] = dequeue(q[bucket]);
		printf("\n\n %d �ܰ� : ", d + 1);
		for (i = 0; i < n; i++) printf(" %d", a[i]);

		factor = factor * radix;
	}
}

void main() {
	element list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = 8;
	printf("\n <<<<< ��� ���� ���� >>>>>");
	radixsort(list, size);
}