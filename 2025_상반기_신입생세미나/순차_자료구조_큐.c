#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 4

typedef char element;
typedef struct {
	element queue[Q_SIZE]; // 1차원 배열 큐 선언
	int front, rear;
}QueueType;

// 공백 순차 큐 생성
QueueType* createQueue() {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1; // front 초깃값 설정
	Q->rear = -1; // rear 초깃값 설정
	return Q;
}

// 순차 큐 공백 상태 확인
int isEmpty(QueueType* Q) {
	if (Q->front == Q->rear) {
		printf("Queue is Empty!");
		return 1;
	}
	else return 0;
}

// 순차 큐 포화상태 확인
int isFull(QueueType* Q) {
	if (Q->rear == Q_SIZE - 1) {
		printf("Queue is full!");
		return 1;
	}
	else return 0;
}

// 순차 큐의 rear에 원소 삽입
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) return; // 포화 상태이면 삽입 중단
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

// 순차 큐의 front에서 원소 삭제
element deQueue(QueueType* Q) {
	if (isEmpty(Q)) return; // 공백 상태이면 삭제 중단
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

// 순차 큐의 가장 앞에 있는 원소 검색
element peek(QueueType* Q) {
	if (isEmpty(Q)) return; // 공백 상태이면 검색 중단
	else return Q->queue[Q->front + 1];
}

// 순차 큐 원소 출력
void printQ(QueueType* Q) {
	int i;
	printf(" Queue : [");
	for (i = Q->front + 1; i <= Q->rear; i++)
		printf("%c", Q->queue[i]);
	printf("]");
}

void main(void) {
	QueueType* Q1 = createQueue();
	element data;
	printf("\n ***** 순차 큐 연산 ***** \n");
	printf("\n 삽입 A>>"); enQueue(Q1, 'A'); printQ(Q1);
	printf("\n 삽입 B>>"); enQueue(Q1, 'B'); printQ(Q1);
	printf("\n 삽입 C>>"); enQueue(Q1, 'C'); printQ(Q1);
	data = peek(Q1); printf(" peek item : %c \n", data);
	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t 삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t\t삭제 데이터 : %c", data);

	printf("\n 삽입 D>>"); enQueue(Q1, 'D'); printQ(Q1);
	printf("\n 삽입 E>>"); enQueue(Q1, 'E'); printQ(Q1);
}