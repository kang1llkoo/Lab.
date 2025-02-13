#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 이중 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	struct ListNode* llink;
	char data[4];
	struct ListNode* rlink;
} listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
} linkedList_h;

// 공백 이중 연결 리스트를 생성
linkedList_h* createLinkedList_h(void) {
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

// 이중 연결 리스트를 순서대로 출력
void printList(linkedList_h* DL) {
	listNode* p;
	printf("DL = (");
	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

// pre 뒤에 노드를 삽입하는 연산
void insertNode(linkedList_h* DL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (DL->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DL->head = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL) // 삽입 자리에 다음 노드가 있는 경우
			newNode->rlink->llink = newNode;
	}
}

// 이중 연결 리스트에서 old 노드를 삭제하는 연산
void deleteNode(linkedList_h* DL, listNode* old) {
	if (DL->head == NULL) return;
	else if (old == NULL) return;
	else {
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		free(old); // 삭제 노드의 메모리 해제
	}
}

// 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* DL, char* x) {
	listNode* temp;
	temp = DL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->rlink;
	}
	return temp;
}

int main() {
	linkedList_h* DL;
	listNode* p;
	DL = createLinkedList_h();
	printf("(1) 이중 연결 리스트 생성하기! \n");
	printList(DL); getchar();

	printf("(2) 이중 연결 리스트에 [월] 노드 삽입하기! \n");
	insertNode(DL, NULL, "월");
	printList(DL); getchar();

	printf("(3) 이중 연결 리스트의 [월] 노드에 [수] 노드 삽입하기! \n");
	p = searchNode(DL, "월"); insertNode(DL, p, "수");
	printList(DL); getchar();

	printf("(4) 이중 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기! \n");
	p = searchNode(DL, "수"); insertNode(DL, p, "금");
	printList(DL); getchar();

	printf("(2) 이중 연결 리스트에서 [수] 노드 삭제하기! \n");
	p = searchNode(DL, "수"); deleteNode(DL, p);
	printList(DL); getchar();

	return 0;
}