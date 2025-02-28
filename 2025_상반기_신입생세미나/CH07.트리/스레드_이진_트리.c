#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treenode {
	char data;
	struct treenode* left;
	struct treenode* right;
	int isthreadright;
} treenode;

treenode* makerootnode(char data, treenode* leftnode, treenode* rightnode, int isthreadright) {
	treenode* root = (treenode*)malloc(sizeof(treenode));
	root->data = data;
	root->left = leftnode;
	root->right = rightnode;
	root->isthreadright = isthreadright;
}

treenode* findthreadsuccessor(treenode* p) {
	treenode* q = p->right;
	if (q == NULL) return q;
	if (p->isthreadright == 1) return q;
	while (q->left != NULL) q = q->left;
	return q;
}

void threadinorder(treenode* root) {
	treenode* q;
	q = root;
	while (q->left) q = q->left;
	do {
		printf("%3c", q->data);
		q = findthreadsuccessor(q);
	} while (q);
}

void main() {
	// (A*B-C/D) 수식 이진 트리 만들기
	treenode* n7 = makerootnode('D', NULL, NULL, 0);
	treenode* n6 = makerootnode('C', NULL, NULL, 1);
	treenode* n5 = makerootnode('B', NULL, NULL, 1);
	treenode* n4 = makerootnode('A', NULL, NULL, 1);
	treenode* n3 = makerootnode('/', n6, n7, 0);
	treenode* n2 = makerootnode('*', n4, n5, 0);
	treenode* n1 = makerootnode('-', n2, n3, 0);

	n4->right = n2;
	n5->right = n1;
	n6->right = n3;

	printf("\n 스레드 이진 트리의 중위 순회 : ");
	threadinorder(n1);
}