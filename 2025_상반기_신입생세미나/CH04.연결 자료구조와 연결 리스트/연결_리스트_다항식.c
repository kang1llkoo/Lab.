#include <stdio.h>
#include <stdlib.h>

// 다항식 리스트의 노드 구조를 구조체로 정의
float coef;
typedef struct ListNode {
	float coef;
	int expo;
	struct ListNode* link;
} ListNode;

// 다항식 리스트의 head 노드를 구조체로 정의
typedef struct ListHead {
	ListNode* head;
} ListHead;

// 공백 다항식 리스트를 생성하는 연산
ListHead* createLinkedList(void) {
	ListHead* L;
	L = (ListHead*)malloc(sizeof(ListHead));
	L->head = NULL;
	return L;
}

// 다항식 리스트에 마지막 노드를 추가하는 연산
void appendTerm(ListHead* L, float coef, int expo) {
	ListNode* newNode;
	ListNode* p;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	else {
		p = L->head;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = newNode;
	}
}

// 두 다항식의 덧셈을 구하는 연산
void addPoly(ListHead* A, ListHead* B, ListHead* C) {
	ListNode* pA = A->head;
	ListNode* pB = B->head;
	float sum;

	// 두 다항식에 노드가 있는 동안 반복 수행
	while (pA && pB) {
		// 다항식 A의 지수가 다항식 B의 지수와 같은 경우
		if (pA->expo == pB->expo) {
			sum = pA->coef + pB->coef;
			appendTerm(C, sum, pA->expo);
			pA = pA->link; pB = pB->link;
		}
		// 다항식 A의 지수가 다항식 B의 지수보다 큰 경우
		else if (pA->expo > pB->expo) {
			appendTerm(C, pA->coef, pA->expo);
			pA = pA->link;
		}
		// 다항식 A의 지수가 다항식 B의 지수보다 작은 경우
		else {
			appendTerm(C, pB->coef, pB->expo);
			pB = pB->link;
		}
	}
	// 다항식 A에 남아 있는 노드 복사
	for (; pA != NULL; pA = pA->link)
		appendTerm(C, pA->coef, pA->expo);

	// 다항식 B에 남아 있는 노드 복사
	for (; pB != NULL; pB = pB->link)
		appendTerm(C, pB->coef, pB->expo);
}

// 다항식 리스트를 출력하는 연산
void printPoly(ListHead* L) {
	ListNode* p = L->head;
	for (; p; p = p->link) {
		printf("%3.0fx^%d", p->coef, p->expo);
		if (p->link != NULL) printf("+");
	}
}

void main(void) {
	ListHead* A, * B, * C;

	// 공백 다항식 리스트 A, B, C 생성
	A = createLinkedList();
	B = createLinkedList();
	C = createLinkedList();

	appendTerm(A, 4, 3);
	appendTerm(A, 3, 2);
	appendTerm(A, 5, 1);
	printf("\n A(x) =");
	printPoly(A);

	appendTerm(B, 4, 3);
	appendTerm(B, 3, 2);
	appendTerm(B, 5, 1);
	appendTerm(B, 1, 0);
	printf("\n A(x) =");
	printPoly(B);

	addPoly(A, B, C);
	printf("\n C(x) =");

	printPoly(C);

	getchar();
}