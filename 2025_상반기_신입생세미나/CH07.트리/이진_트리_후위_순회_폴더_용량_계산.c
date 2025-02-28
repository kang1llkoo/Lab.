#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treenode {
	int size;
	struct treenode* left;
	struct treenode* right;
} treenode;

int foldersize = 0;

// size를 루트 노드의 데이터 필드로 하여 왼쪽, 오른쪽 서브 트리 연결
treenode* makerootnode(int size, treenode* leftnode, treenode* rightnode) {
	treenode* root = (treenode*)malloc(sizeof(treenode));
	root->size = size;
	root->left = leftnode;
	root->right = rightnode;
	return root;
}

// 각 폴더 크기를 계산하기 위해 후위 순위 계산
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

	printf("\n\n C:\\의 용랑: %d M \n", postorder_foldersize(f2));

	foldersize = 0;
	printf("\n D:\\의 용량: %d M \n", postorder_foldersize(f3));

	foldersize = 0;
	printf("\n 내 컴퓨터의 전체 용량: %d M \n", postorder_foldersize(f1));
}