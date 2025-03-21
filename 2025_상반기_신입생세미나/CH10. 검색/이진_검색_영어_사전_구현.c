#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_word_length 20
#define max_mean_length 200

typedef struct {
    char word[max_word_length];
    char mean[max_mean_length];
} element;

typedef struct treenode {
    element key;
    struct treenode* left;
    struct treenode* right;
} treenode;

treenode* insertkey(treenode* p, element key) {
    if (p == NULL) {
        treenode* newnode = (treenode*)malloc(sizeof(treenode));
        newnode->key = key;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    int compare = strcmp(key.word, p->key.word);
    if (compare < 0) p->left = insertkey(p->left, key);
    else if (compare > 0) p->right = insertkey(p->right, key);
    else printf("\n이미 같은 단어가 있습니다!\n");

    return p;
}

void insert(treenode** root, element key) {
    *root = insertkey(*root, key);
}

void deletenode(treenode** root, element key) {
    treenode* parent = NULL, *p = *root, *succ, *succ_parent;
    treenode* child;

    while (p != NULL && strcmp(p->key.word, key.word) != 0) {
        parent = p;
        if (strcmp(key.word, p->key.word) < 0) p = p->left;
        else p = p->right;
    }

    if (p == NULL) {
        printf("\n삭제할 단어가 사전에 없습니다!!\n");
        return;
    }

    if (p->left == NULL && p->right == NULL) {  // 단말 노드 삭제
        if (parent != NULL) {
            if (parent->left == p) parent->left = NULL;
            else parent->right = NULL;
        } else *root = NULL;  // 루트 노드 삭제 시
    } else if (p->left == NULL || p->right == NULL) {  // 자식 하나만 있을 때
        child = (p->left != NULL) ? p->left : p->right;
        if (parent != NULL) {
            if (parent->left == p) parent->left = child;
            else parent->right = child;
        } else *root = child;  // 루트 노드 삭제 시 갱신
    } else {  // 자식이 둘일 때
        succ_parent = p;
        succ = p->right;
        while (succ->left != NULL) { 
            succ_parent = succ;
            succ = succ->left;
        }
        p->key = succ->key;
        if (succ_parent->left == succ) succ_parent->left = succ->right;
        else succ_parent->right = succ->right;
        p = succ;
    }
    free(p);
}

treenode* searchbst(treenode* root, element key) {
    treenode* p = root;
    while (p != NULL) {
        int compare = strcmp(key.word, p->key.word);
        if (compare < 0) p = p->left;
        else if (compare > 0) p = p->right;
        else {
            printf("\n찾은 단어: %s\n", p->key.word);
            return p;
        }
    }
    return NULL;
}

void displayinorder(treenode* root) {
    if (root) {
        displayinorder(root->left);
        printf("\n%s : %s", root->key.word, root->key.mean);
        displayinorder(root->right);
    }
}

void menu() {
    printf("\n*--------------------*");
    printf("\n\t1 : 출력");
    printf("\n\t2 : 입력");
    printf("\n\t3 : 삭제");
    printf("\n\t4 : 검색");
    printf("\n\t5 : 종료");
    printf("\n*--------------------*");
}

int main() {
    char choice[10];
    element e;
    treenode* root = NULL, *temp = NULL;

    do {
        menu();
        printf("\n선택: ");
        fgets(choice, sizeof(choice), stdin);

        switch (choice[0]) {
            case '1':
                printf("\t[사전 출력]");
                displayinorder(root);
                printf("\n\t[사전 끝]\n");
                break;
            case '2':
                printf("\n[단어 입력] 단어를 입력하시오: ");
                fgets(e.word, max_word_length, stdin);
                e.word[strcspn(e.word, "\n")] = 0;

                printf("\n[단어 입력] 단어의 뜻을 입력하시오: ");
                fgets(e.mean, max_mean_length, stdin);
                e.mean[strcspn(e.mean, "\n")] = 0;

                insert(&root, e);
                break;
            case '3':
                printf("\n[단어 삭제] 삭제할 단어: ");
                fgets(e.word, max_word_length, stdin);
                e.word[strcspn(e.word, "\n")] = 0;
                deletenode(&root, e);
                break;
            case '4':
                printf("\n[단어 검색] 검색할 단어: ");
                fgets(e.word, max_word_length, stdin);
                e.word[strcspn(e.word, "\n")] = 0;

                temp = searchbst(root, e);
                if (temp != NULL)
                    printf("\n단어 뜻: %s", temp->key.mean);
                else printf("\n사전에 없는 단어입니다.");
                break;
        }
    } while (choice[0] != '5');

    return 0;
}