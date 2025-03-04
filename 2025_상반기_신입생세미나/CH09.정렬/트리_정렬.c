#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct treenode {
	element key;
	struct treenode* left;
	struct treenode* right;
} treenode;

// ��� x�� �����ϴ� ����
treenode* insertnode(treenode* p, element x) {
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

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ��θ� ���
void displayinorder(treenode* root) {
	if (root) {
		displayinorder(root->left);
		printf("%d ", root->key);
		displayinorder(root->right);
	}
}

// Ʈ�� ���� ����
void treesort(element a[], int n) {
	treenode* root = NULL;
	root = insertnode(root, a[0]);

	for (int i = 1; i < n; i++)
		insertnode(root, a[i]);
	displayinorder(root);
}

int main() {
	element list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = 8;
	printf("\n <<<<< Ʈ�� ���� ���� >>>>> \n\n");
	treesort(list, size);
}