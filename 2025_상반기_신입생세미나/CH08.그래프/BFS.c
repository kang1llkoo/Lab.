#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define max_vertex 10
#define false 0
#define true 1

// �׷����� ���� ���� ����Ʈ ��� ���� ����
typedef struct graphnode {
	int vertex;
	struct graphnode* link;
}graphnode;

typedef struct graphtype {
	int n; // ���� ����
	graphnode* adjlist_h[max_vertex]; // ������ ���� ���� ����Ʈ�� ��� ��� �迭
	int visited[max_vertex]; // ������ ���� �湮 ǥ�ø� ���� �迭
}graphtype;

typedef int element;

// BFS�� �����ϱ� ���� ť ����
typedef struct qnode {
	int data; // data �ʵ��� �ڷ����� int ����
	struct qnode* link;
}qnode;

typedef struct {
	qnode* front, * rear;
}lqueuetype;

lqueuetype* createlinkedqueue() {
	lqueuetype* lq;
	lq = (lqueuetype*)malloc(sizeof(lqueuetype));
	lq->front = NULL;
	lq->rear = NULL;
	return lq;
}

int isempty(lqueuetype* lq) {
	if (lq->front == NULL) {
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else return 0;
}

void enqueue(lqueuetype* lq, int item) {
	qnode* newnode = (qnode*)malloc(sizeof(qnode));
	newnode->data = item;
	newnode->link = NULL;
	if (lq->front == NULL) {
		lq->front = newnode;
		lq->rear = newnode;
	}
	else {
		lq->rear->link = newnode;
		lq->rear = newnode;
	}
}

int dequeue(lqueuetype* lq) {
	qnode* old = lq->front;
	int item;
	if (isempty(lq)) return 0;
	else {
		item = old->data;
		lq->front = lq->front->link;
		if (lq->front == NULL)
			lq->rear = NULL;
		free(old);
		return item;
	}
}

// BFS Ž���� ���� �ʱ� ���� �׷��� ����
void creategraph(graphtype* g) {
	int v;
	g->n = 0; // �׷��� ���� ���� 0���� �ʱ�ȭ
	for (v = 0; v < max_vertex; v++) {
		g->visited[v] = false; // �׷��� ������ ���� �迭 visited�� false�� �ʱ�ȭ
		g->adjlist_h[v] = NULL; // ���� ����Ʈ�� ���� ��� ��� �迭�� NULL�� �ʱ�ȭ
	}
}

// �׷��� g�� ���� v�� �����ϴ� ����
void insertvertex(graphtype* g, int v) {
	if (((g->n) + 1) > max_vertex) {
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
		return;
	}
	g->n++;
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

// �׷��� g�� ���� ���� ����Ʈ ���
void print_adjlist(graphtype* g) {
	int i;
	graphnode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t���� %c�� ���� ����Ʈ", i + 65);
		p = g->adjlist_h[i];
		while (p) {
			printf(" -> %c", p->vertex + 65);
			p = p->link;
		}
	}
}

// �׷��� g���� ���� v�� ���� BFS Ž��
void BFS_adjlist(graphtype* g, int v) {
	graphnode* w;
	lqueuetype* q; // ť ����
	q = createlinkedqueue(); // ť ����
	g->visited[v] = true; // ���� ���� v�� ���� �迭���� true�� ����
	printf(" %c", v + 65);
	enqueue(q, v); // ���� ���� v�� ť�� enqueue

	// ť�� ������ �ƴ� ���� BFS Ž�� ����
	while (!isempty(q)) {
		v = dequeue(q);
		// ���� ���� w�� �湮���� ���� ���
		for (w=g->adjlist_h[v]; w; w=w->link)
			if (!g->visited[w->vertex]) {
				g->visited[w->vertex] = true;
				printf(" %c", w->vertex + 65);
				enqueue(q, w->vertex);
			}
	} // ť�� �����̸� BFS Ž�� ����
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
	printf("\n g9�� ���� ����Ʈ : ");
	print_adjlist(g9);

	printf("\n\n///////////////////////\n\n BFS >> ");
	BFS_adjlist(g9, 0);
}