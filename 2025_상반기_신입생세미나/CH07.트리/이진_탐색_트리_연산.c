#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct treenode {
	char key;
	struct treenode* left;
	struct treenode* right;
} treenode;

//이진 탐색 트리에서 키값이 x인 노드 위치 탐색
treenode* searchbst(treenode* root, char x) {
	treenode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	printf("\n 찾는 키가 없습니다.");
	return p;
}

// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입
treenode* insertnode(treenode* p, char x) {
	treenode* newnode;
	if (p == NULL) {
		newnode = (treenode*)malloc(sizeof(treenode));
		newnode->key = x;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	else if (x < p->key) p->left = insertnode(p->left, x);
	else if (x > p->key) p->right = insertnode(p->right, x);
	else printf("\n 이미 같은 키가 있습니다. \n");

	return p;
}

// 루트 노드부터 탐색하여 키 값과 같은 노드를 찾아 삭제
void deletenode(treenode* root, element key) {
	treenode* parent, * p, * succ, * succ_parent;
	treenode* child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	// 삭제할 노드가 없는 경우
	if (p == NULL) {
		printf("\n 찾는 키가 이진 트리에 없습니다!");
		return;
	}

	// 삭제할 노드가 단말 노드일 경우
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// 삭제할 노드가 자식 노드를 한 개 가질 경우
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	// 삭제할 노드가 자식 노드를 두 개 가진 경우
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) {
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}
	free(p);
}

// 이진 탐색 트리를 중위 순회하면서 출력
void displayinorder(treenode* root) {
	if (root) {
		displayinorder(root->left);
		printf("%c_", root->key);
		displayinorder(root->right);
	}
}

void menu() {
	printf("\n*--------------------------*");
	printf("\n\t1 : 트리 출력");
	printf("\n\t2 : 문자 삽입");
	printf("\n\t3 : 문자 삭제");
	printf("\n\t4 : 문자 검색");
	printf("\n\t5 : 종료");
	printf("\n*--------------------------*");
	printf("\n메뉴 입력 >> ");
}

int main() {
	treenode* root = NULL;
	treenode* foundednode = NULL;
	char choice, key;

	root = insertnode(root, 'G');
	insertnode(root, 'I');
	insertnode(root, 'H');
	insertnode(root, 'D');
	insertnode(root, 'B');
	insertnode(root, 'M');
	insertnode(root, 'N');
	insertnode(root, 'A');
	insertnode(root, 'J');
	insertnode(root, 'E');
	insertnode(root, 'Q');

	while (1) {
		menu();
		scanf(" %c", &choice);

		switch (choice - '0') {
		case 1: printf("\t[이진 트리 출력] ");
			displayinorder(root); printf("\n");
			break;

		case 2: printf("삽입할 문자를 입력하세요 : ");
			scanf(" %c", &key);
			insertnode(root, key);
			break;

		case 3: printf("삭제할 문자를 입력하세요 : ");
			scanf(" %c", &key);
			deletenode(root, key);
			break;

		case 4: printf("찾을 문자를 입력하세요 : ");
			scanf(" %c", &key);
			foundednode = searchbst(root, key);
			if (foundednode != NULL)
				printf("\n %c를 찾았습니다. \n", foundednode->key);
			else printf("\n 문자를 찾지 못했습니다. \n");
			break;

		case 5: return 0;

		default: printf("없는 메뉴입니다. 메뉴를 다시 선택하세요. \n");
			break;
		}
	}
}