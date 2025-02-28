#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define max(a,b) ((a>b)?a:b)

typedef int element;

typedef struct treenode {
	element key;
	struct treenode* left;
	struct treenode* right;
} treenode;

treenode* LL_rotate(treenode* parent) {
	treenode* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

treenode* RR_rotate(treenode* parent) {
	treenode* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

treenode* LR_rotate(treenode* parent) {
	treenode* child = parent->left;
	parent->left = RR_rotate(child);
	return LL_rotate(parent);
}

treenode* RL_rotate(treenode* parent) {
	treenode* child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}

// ���� Ʈ���� ���� ���
int getheight(treenode* p) {
	int height = 0;
	if (p != NULL) height = max(getheight(p->left), getheight(p->right)) + 1;
	return height;
}

// ���� Ʈ���� ���̸� �̿��� ���� �μ�(BF) ���ϴ� ����
int getbf(treenode* p) {
	if (p == NULL) return 0;
	return getheight(p->left) - getheight(p->right);
}

// BF�� �˻��Ͽ� �ұ����� �߻��� ���, ȸ�� ���� ȣ��
treenode* rebalance(treenode** p) {
	int bf = getbf(*p);

	if (bf > 1) {
		if (getbf((*p)->left) > 0)
			*p = LL_rotate(*p);
		else *p = LR_rotate(*p);
	}
	else if (bf < -1) {
		if (getbf((*p)->right) < 0)
			*p = RR_rotate(*p);
		else *p = RL_rotate(*p);
	}
	return *p;
}

// AVL Ʈ���� ��带 ����, ���� Ž�� ����ó�� ���� �� rebalance() ȣ��
treenode* insert_avl_node(treenode** root, element x) {
	if (*root == NULL) {
		*root = (treenode*)malloc(sizeof(treenode));
		(*root)->key = x;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (x < (*root)->key) {
		(*root)->left = insert_avl_node(&((*root)->left), x);
		*root = rebalance(root);
	}
	else if (x > (*root)->key) {
		(*root)->right = insert_avl_node(&((*root)->right), x);
		*root = rebalance(root);
	}
	else {
		printf("\n �̹� ���� Ű�� �ֽ��ϴ�. \n");
		exit(1);
	}
	return *root;
}

// ���� Ž�� Ʈ���� ��� ����
treenode* insert_bst_node(treenode* p, element x) {
	treenode* new;
	if (p == NULL) {
		new = (treenode*)malloc(sizeof(treenode));
		new->key = x;
		new->left = NULL;
		new->right = NULL;
		return new;;
	}
	else if (x < p->key) p->left = insert_bst_node(p->left, x);
	else if (x > p->key) p->right = insert_bst_node(p->right, x);
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ� \n");

	return p;
}

// ���� Ž�� Ʈ���� avl Ʈ������ Ű�� x�� Ž���ϴ� ����
treenode* searchtree(treenode* root, element x) {
	treenode* p;
	int count = 0;
	p = root;
	while (p != NULL) {
		count++;
		if (x < p->key) p = p->left;
		else if (x == p->key) {
			printf("%3d��°�� Ž�� ����", count);
			return p;
		}
		else p = p->right;
	}
	count++;
	printf("%3d��°�� Ž�� ����, ã�� Ű�� �����ϴ�.", count);
	return p;
}

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ����
void displayinorder(treenode* root) {
	if (root) {
		displayinorder(root->left);
		printf("_%d ", root->key);
		displayinorder(root->right);
	}
}

int main() {
	treenode* root_avl = NULL;
	treenode* root_bst = NULL;

	/////////////////////////////////////////////////
	root_avl = insert_avl_node(&root_avl, 50);
	insert_avl_node(&root_avl, 60);
	insert_avl_node(&root_avl, 70);
	insert_avl_node(&root_avl, 90);
	insert_avl_node(&root_avl, 80);
	insert_avl_node(&root_avl, 75);
	insert_avl_node(&root_avl, 73);
	insert_avl_node(&root_avl, 72);
	insert_avl_node(&root_avl, 78);

	printf("\n *********** AVL Ʈ�� ��� *********** \n\n");
	displayinorder(root_avl);

	printf("\n\n AVL Ʈ������ 70 Ž�� : ");
	searchtree(root_avl, 70);

	printf("\n\n AVL Ʈ������ 72 Ž�� : ");
	searchtree(root_avl, 72);

	printf("\n\n AVL Ʈ������ 76 Ž�� : ");
	searchtree(root_avl, 76);

	/////////////////////////////////////////////////
	root_bst = insert_bst_node(root_bst, 50);
	insert_bst_node(root_bst, 60);
	insert_bst_node(root_bst, 70);
	insert_bst_node(root_bst, 90);
	insert_bst_node(root_bst, 80);
	insert_bst_node(root_bst, 75);
	insert_bst_node(root_bst, 73);
	insert_bst_node(root_bst, 72);
	insert_bst_node(root_bst, 78);

	printf("\n *********** BST ��� *********** \n\n");
	displayinorder(root_bst);

	printf("\n\n BST���� 70 Ž�� : ");
	searchtree(root_bst, 70);

	printf("\n\n BST���� 72 Ž�� : ");
	searchtree(root_bst, 72);

	printf("\n\n BST���� 76 Ž�� : ");
	searchtree(root_bst, 76);
}