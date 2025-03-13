#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define max_vertex 10
#define false 0
#define true 1

// �׷����� ���� ���� ����Ʈ�� ��� ���� ����
typedef struct graphnode {
	int vertex;
	struct graphnode* link;
}graphnode;

typedef struct graphtype {
	int n; // ���� ����
	graphnode* adjlist_h[max_vertex]; // ������ ���� ���� ����Ʈ�� ��� ��� �迭
	int visited[max_vertex]; // ������ ���� �湮 ǥ�� ���� �迭
}graphtype;

// ���� - DFS������ ���� �ڷᱸ�� ���
typedef int element;

typedef struct stacknode {
	int data;
	struct stacknode* link;
}stacknode;

stacknode* top;

// ������ �������� Ȯ��
int isempty() {
	if (top == NULL) return 1;
	else return 0;
}

void push(int item) {
	stacknode* temp = (stacknode*)malloc(sizeof(stacknode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

int pop() {
	int item;
	stacknode* temp = top;

	if (isempty()) {
		printf("\n\n Stack is empty!\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

// DFS�� ���� �ʱ� ���� �׷��� ����
void creategraph(graphtype* g) {
	int v;
	g->n = 0; // �׷��� node ���� 0���� �ʱ�ȭ
	for (v = 0; v < max_vertex; v++) {
		g->visited[v] = false; // �׷����� ������ ���� �迭 visited�� false�� �ʱ�ȭ
		g->adjlist_h[v] = NULL; // ���� ����Ʈ�� ���� ��� node �迭�� NULL�� �ʱ�ȭ
	}
}

// �׷��� g�� ���� v�� �����ϴ� ����
void insertvertex(graphtype* g, int v) {
	if (((g->n) + 1) > max_vertex) {
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
		return;
	}
	g->n++; // �׷����� ���� ���� n�� �ϳ� ����
}

// �׷��� g�� ���� (u,v)�� ����
void insertedge(graphtype* g, int u, int v) {
	graphnode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n �׷����� ���� �����Դϴ�!");
		return;
	}
	node = (graphnode*)malloc(sizeof(graphnode));
	node->vertex = v;
	node->link = g->adjlist_h[u];
	g->adjlist_h[u] = node;
}

// �׷��� g�� �� ������ ���� ���� ����Ʈ�� ����ϴ� ����
void print_adjlist(graphtype* g) {
	int i;
	graphnode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t���� %c�� ���� ����Ʈ", i + 65);
		p = g->adjlist_h[i];
		while (p) {
			printf("-> %c", p->vertex + 65);
			p = p->link;
		}
	}
}

// �׷��� g���� ���� v�� ���� DFS ����
void dfs_adjlist(graphtype* g, int v) {
	graphnode* w;
	top = NULL; // ������ top ����
	push(v); // DFS�� �����ϴ� ���� v�� ���ÿ� push
	g->visited[v] = true; // ���� v�� �湮�����Ƿ� �ش� �迭���� true�� ����
	printf(" %c", v + 65);

	// ������ ������ �ƴ� ���� DFS �ݺ�
	while (!isempty()) {
		v = pop();
		w = g->adjlist_h[v];
		// ���� ������ �ִ� ���� ����
		while (w) {
			// ���� ���� w�� �湮���� ���� ���
			if (!g->visited[w->vertex]) {
				if (isempty()) push(v);
				push(w->vertex);
				g->visited[w->vertex] = true;
				printf(" %c", w->vertex + 65);
				v = w->vertex;
				w = g->adjlist_h[v];
			}
			// ���� ���� w�� �̹� �湮�� ���
			else w = w->link;
		} // while (w)
	} // ������ �����̸� DFS ����
}

void main() {
	int i;
	graphtype* g9;
	g9 = (graphtype*)malloc(sizeof(graphtype));
	creategraph(g9);

	// �׷��� g9 ����
	for (i = 0; i < 7; i++)
		insertvertex(g9, i);
	insertedge(g9, 0, 2);
	insertedge(g9, 0, 1);
	insertedge(g9, 1, 4);
	insertedge(g9, 1, 3);
	insertedge(g9, 1, 0);
	insertedge(g9, 2, 4);
	insertedge(g9, 2, 0);
	insertedge(g9, 3, 6);
	insertedge(g9, 3, 1);
	insertedge(g9, 4, 6);
	insertedge(g9, 4, 2);
	insertedge(g9, 4, 1);
	insertedge(g9, 5, 6);
	insertedge(g9, 6, 5);
	insertedge(g9, 6, 4);
	insertedge(g9, 6, 3);
	printf("\n g9�� ���� ����Ʈ ");
	print_adjlist(g9);

	printf("\n\n////////////////\n\n���� �켱 Ž�� >> ");
	dfs_adjlist(g9, 0);
}