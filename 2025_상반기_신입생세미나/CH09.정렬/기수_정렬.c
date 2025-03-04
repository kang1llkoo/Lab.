#include <stdio.h>
#include <stdlib.h>
#define radix 10 // 정렬할 자료들의 키값이 10진수 ▶ radix를 10으로 정의
#define digit 2 // 정렬할 자료들의 키값이 두 자리 ▶ digit을 2로 정의

// 큐 연산
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
// 큐 >>

// 배열 a에 있는 n개 원소에 대해 기수 정렬 수행
void radixsort(element a[], int n) {
	int i, bucket, d, factor = 1;

	// 정렬할 자료의 기수(radix)에 따라 열 개의 버킷을 큐로 생성
	lqueuetype* q[radix];
	for (bucket = 0; bucket < radix; bucket++)
		q[bucket] = createlinkedqueue();

	// 키값의 자릿수만큼(두 번 기수 정렬) 반복 수행
	for (d = 0; d < digit; d++) {
		for (i = 0; i < n; i++)
			enqueue(q[(a[i] / factor) % radix], a[i]);
		for (bucket = 0, i = 0; bucket < radix; bucket++)
			while (!isempty(q[bucket])) a[i++] = dequeue(q[bucket]);
		printf("\n\n %d 단계 : ", d + 1);
		for (i = 0; i < n; i++) printf(" %d", a[i]);

		factor = factor * radix;
	}
}

void main() {
	element list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = 8;
	printf("\n <<<<< 기수 정렬 수행 >>>>>");
	radixsort(list, size);
}