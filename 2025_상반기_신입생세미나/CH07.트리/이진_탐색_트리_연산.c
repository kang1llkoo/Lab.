#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct treenode {
	char key;
	struct treenode* left;
	struct treenode* right;
} treenode;

//���� Ž�� Ʈ������ Ű���� x�� ��� ��ġ Ž��
treenode* searchbst(treenode* root, char x) {
	treenode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	printf("\n ã�� Ű�� �����ϴ�.");
	return p;
}

// ������ p�� ����Ű�� ���� ���Ͽ� ��� x�� ����
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
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ�. \n");

	return p;
}

// ��Ʈ ������ Ž���Ͽ� Ű ���� ���� ��带 ã�� ����
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

	// ������ ��尡 ���� ���
	if (p == NULL) {
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!");
		return;
	}

	// ������ ��尡 �ܸ� ����� ���
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// ������ ��尡 �ڽ� ��带 �� �� ���� ���
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	// ������ ��尡 �ڽ� ��带 �� �� ���� ���
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

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ���
void displayinorder(treenode* root) {
	if (root) {
		displayinorder(root->left);
		printf("%c_", root->key);
		displayinorder(root->right);
	}
}

void menu() {
	printf("\n*--------------------------*");
	printf("\n\t1 : Ʈ�� ���");
	printf("\n\t2 : ���� ����");
	printf("\n\t3 : ���� ����");
	printf("\n\t4 : ���� �˻�");
	printf("\n\t5 : ����");
	printf("\n*--------------------------*");
	printf("\n�޴� �Է� >> ");
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
		case 1: printf("\t[���� Ʈ�� ���] ");
			displayinorder(root); printf("\n");
			break;

		case 2: printf("������ ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);
			insertnode(root, key);
			break;

		case 3: printf("������ ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);
			deletenode(root, key);
			break;

		case 4: printf("ã�� ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);
			foundednode = searchbst(root, key);
			if (foundednode != NULL)
				printf("\n %c�� ã�ҽ��ϴ�. \n", foundednode->key);
			else printf("\n ���ڸ� ã�� ���߽��ϴ�. \n");
			break;

		case 5: return 0;

		default: printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���. \n");
			break;
		}
	}
}