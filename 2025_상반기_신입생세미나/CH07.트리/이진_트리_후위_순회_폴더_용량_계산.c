#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treenode {
	int size;
	struct treenode* left;
	struct treenode* right;
} treenode;

int foldersize = 0;

// size�� ��Ʈ ����� ������ �ʵ�� �Ͽ� ����, ������ ���� Ʈ�� ����
treenode* makerootnode(int size, treenode* leftnode, treenode* rightnode) {
	treenode* root = (treenode*)malloc(sizeof(treenode));
	root->size = size;
	root->left = leftnode;
	root->right = rightnode;
	return root;
}

// �� ���� ũ�⸦ ����ϱ� ���� ���� ���� ���
int postorder_foldersize(treenode* root) {
	if (root) {
		postorder_foldersize(root->left);
		postorder_foldersize(root->right);
		foldersize += root->size;
	}
	return foldersize;
}

void main() {
	treenode* f11 = makerootnode(120, NULL, NULL);
	treenode* f10 = makerootnode(55, NULL, NULL);
	treenode* f9 = makerootnode(100, NULL, NULL);
	treenode* f8 = makerootnode(200, NULL, NULL);
	treenode* f7 = makerootnode(68, f10, f11);
	treenode* f6 = makerootnode(40, NULL, NULL);
	treenode* f5 = makerootnode(15, NULL, NULL);
	treenode* f4 = makerootnode(2, f8, f9);
	treenode* f3 = makerootnode(10, f6, f7);
	treenode* f2 = makerootnode(0, f4, f5);
	treenode* f1 = makerootnode(0, f2, f3);

	printf("\n\n C:\\�� ���: %d M \n", postorder_foldersize(f2));

	foldersize = 0;
	printf("\n D:\\�� �뷮: %d M \n", postorder_foldersize(f3));

	foldersize = 0;
	printf("\n �� ��ǻ���� ��ü �뷮: %d M \n", postorder_foldersize(f1));
}