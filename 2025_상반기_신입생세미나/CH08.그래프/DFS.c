#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define max_vertex 10
#define false 0
#define true 1

// 그래프에 대한 인접 리스트의 노드 구조 정의
typedef struct graphnode {
	int vertex;
	struct graphnode* link;
}graphnode;

typedef struct graphtype {
	int n; // 정점 개수
	graphnode* adjlist_h[max_vertex]; // 정점에 대한 인접 리스트의 헤드 노드 배열
	int visited[max_vertex]; // 정점에 대한 방문 표시 위한 배열
}graphtype;

// 스택 - DFS에서는 스택 자료구조 사용
typedef int element;

typedef struct stacknode {
	int data;
	struct stacknode* link;
}stacknode;

stacknode* top;

// 스택이 공백인지 확인
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

// DFS를 위해 초기 공백 그래프 생성
void creategraph(graphtype* g) {
	int v;
	g->n = 0; // 그래프 node 수를 0으로 초기화
	for (v = 0; v < max_vertex; v++) {
		g->visited[v] = false; // 그래프의 정점에 대한 배열 visited를 false로 초기화
		g->adjlist_h[v] = NULL; // 인접 리스트에 대한 헤드 node 배열을 NULL로 초기화
	}
}

// 그래프 g에 정점 v를 삽입하는 연산
void insertvertex(graphtype* g, int v) {
	if (((g->n) + 1) > max_vertex) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++; // 그래프의 정점 개수 n을 하나 증가
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

// 그래프 g의 각 정점에 대한 인접 리스트를 출력하는 연산
void print_adjlist(graphtype* g) {
	int i;
	graphnode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t정점 %c의 인접 리스트", i + 65);
		p = g->adjlist_h[i];
		while (p) {
			printf("-> %c", p->vertex + 65);
			p = p->link;
		}
	}
}

// 그래프 g에서 정점 v에 대한 DFS 수행
void dfs_adjlist(graphtype* g, int v) {
	graphnode* w;
	top = NULL; // 스택의 top 설정
	push(v); // DFS를 시작하는 정점 v를 스택에 push
	g->visited[v] = true; // 정점 v를 방문했으므로 해당 배열값을 true로 설정
	printf(" %c", v + 65);

	// 스택이 공백이 아닌 동안 DFS 반복
	while (!isempty()) {
		v = pop();
		w = g->adjlist_h[v];
		// 인접 정점이 있는 동안 수행
		while (w) {
			// 현재 정점 w를 방문하지 않은 경우
			if (!g->visited[w->vertex]) {
				if (isempty()) push(v);
				push(w->vertex);
				g->visited[w->vertex] = true;
				printf(" %c", w->vertex + 65);
				v = w->vertex;
				w = g->adjlist_h[v];
			}
			// 현재 정점 w가 이미 방문된 경우
			else w = w->link;
		} // while (w)
	} // 스택이 공백이면 DFS 종료
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
	printf("\n g9의 인접 리스트 ");
	print_adjlist(g9);

	printf("\n\n////////////////\n\n깊이 우선 탐색 >> ");
	dfs_adjlist(g9, 0);
}