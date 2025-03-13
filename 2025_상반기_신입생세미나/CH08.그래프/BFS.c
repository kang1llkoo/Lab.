#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define max_vertex 10
#define false 0
#define true 1

// 그래프에 대한 인접 리스트 노드 구조 정의
typedef struct graphnode {
	int vertex;
	struct graphnode* link;
}graphnode;

typedef struct graphtype {
	int n; // 정점 개수
	graphnode* adjlist_h[max_vertex]; // 정점에 대한 인접 리스트의 헤드 노드 배열
	int visited[max_vertex]; // 정점에 대한 방문 표시를 위한 배열
}graphtype;

typedef int element;

// BFS를 수행하기 위해 큐 생성
typedef struct qnode {
	int data; // data 필드의 자료형을 int 수정
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

// BFS 탐색을 위한 초기 공백 그래프 생성
void creategraph(graphtype* g) {
	int v;
	g->n = 0; // 그래프 정점 개수 0으로 초기화
	for (v = 0; v < max_vertex; v++) {
		g->visited[v] = false; // 그래프 정점에 대한 배열 visited를 false로 초기화
		g->adjlist_h[v] = NULL; // 인접 리스트에 대한 헤드 노드 배열을 NULL로 초기화
	}
}

// 그래프 g에 정점 v를 삽입하는 연산
void insertvertex(graphtype* g, int v) {
	if (((g->n) + 1) > max_vertex) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;
}

// 그래프 g에 간선 (u,v)를 삽입
void insertedge(graphtype* g, int u, int v) {
	graphnode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (graphnode*)malloc(sizeof(graphnode));
	node->vertex = v;
	node->link = g->adjlist_h[u];
	g->adjlist_h[u] = node;
}

// 그래프 g에 대한 인접 리스트 출력
void print_adjlist(graphtype* g) {
	int i;
	graphnode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t정점 %c의 인접 리스트", i + 65);
		p = g->adjlist_h[i];
		while (p) {
			printf(" -> %c", p->vertex + 65);
			p = p->link;
		}
	}
}

// 그래프 g에서 정점 v에 대한 BFS 탐색
void BFS_adjlist(graphtype* g, int v) {
	graphnode* w;
	lqueuetype* q; // 큐 정의
	q = createlinkedqueue(); // 큐 생성
	g->visited[v] = true; // 시작 정점 v에 대한 배열값을 true로 설정
	printf(" %c", v + 65);
	enqueue(q, v); // 현재 정점 v를 큐에 enqueue

	// 큐에 공백이 아닌 동안 BFS 탐색 수행
	while (!isempty(q)) {
		v = dequeue(q);
		// 현재 정점 w를 방문하지 않은 경우
		for (w=g->adjlist_h[v]; w; w=w->link)
			if (!g->visited[w->vertex]) {
				g->visited[w->vertex] = true;
				printf(" %c", w->vertex + 65);
				enqueue(q, w->vertex);
			}
	} // 큐가 공백이면 BFS 탐색 종료
}

void main() {
	int i;
	graphtype* g9;
	g9 = (graphtype*)malloc(sizeof(graphtype));
	creategraph(g9);

	// 그래프 g9 구성
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
	printf("\n g9의 인접 리스트 : ");
	print_adjlist(g9);

	printf("\n\n///////////////////////\n\n BFS >> ");
	BFS_adjlist(g9, 0);
}