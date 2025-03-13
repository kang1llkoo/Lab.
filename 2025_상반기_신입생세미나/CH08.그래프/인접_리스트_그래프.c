#include <stdio.h>
#include <stdlib.h>
#define max_vertex 30

// 인접 리스트의 노드 구조를 구조체로 정의
typedef struct graphnode {
	int vertex;
	struct graphnode* link;
} graphnode;

// 그래프를 인접 리스트로 표현하기 위한 구조체 정의
typedef struct graphtype {
	int n;
	graphnode* adjlist_h[max_vertex];
} graphtype;

// 공백 그래프를 생성
void creategraph(graphtype* g) {
	int v;
	g->n = 0; // 그래프의 정점 개수를 0으로 초기화
	for (v = 0; v < max_vertex; v++)
		g->adjlist_h[v] = NULL; // 그래프의 정점에 대한 헤드 포인터 배열을 NULL로 초기화
}

// 그래프 g에 정점 v를 삽입하는 연산
void insertvertex(graphtype* g, int v) {
	if (((g->n) + 1) > max_vertex) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++; // 그래프의 정점 개수 n을 하나 증가
}

// 그래프 g에 간선 (u, v)를 삽입
void insertedge(graphtype* g, int u, int v) {
	graphnode* node;

	// 간선 (u, v)를 삽입하기 위해 정점 u와 정점 v가 현재 그래프에 있는지 확인
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (graphnode*)malloc(sizeof(graphnode));
	node->vertex = v;
	node->link = g->adjlist_h[u]; // 삽입 간선에 대한 노드를 리스트의 첫 번째 노드로 연결
	g->adjlist_h[u] = node;
}

// 그래프 g의 각 정점에 대한 인접 리스트 출력
void print_adjlist(graphtype* g) {
	int i;
	graphnode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t정점 %c의 인접 리스트", i + 65);
		p = g->adjlist_h[i];
		while (p) {
			printf("-> %c", p->vertex + 65); // 정점 0~3을 A~D로 출력
			p = p->link;
		}
	}
}

void main() {
	int i;
	graphtype* g1, * g2, * g3, * g4;
	g1 = (graphtype*)malloc(sizeof(graphtype));
	g2 = (graphtype*)malloc(sizeof(graphtype));
	g3 = (graphtype*)malloc(sizeof(graphtype));
	g4 = (graphtype*)malloc(sizeof(graphtype));
	creategraph(g1); creategraph(g2); creategraph(g3); creategraph(g4);

	// 그래프 g1
	for (i = 0; i < 4; i++)
		insertvertex(g1, i); // g1의 정점 0~3 삽입
	insertedge(g1, 0, 3);
	insertedge(g1, 0, 1);
	insertedge(g1, 1, 3);
	insertedge(g1, 1, 2);
	insertedge(g1, 1, 0);
	insertedge(g1, 2, 3);
	insertedge(g1, 2, 1);
	insertedge(g1, 3, 2);
	insertedge(g1, 3, 1);
	insertedge(g1, 3, 0);
	printf("\n g1의 인접 리스트");
	print_adjlist(g1);

	// 그래프 g2
	for (i = 0; i < 3; i++)
		insertvertex(g2, i); // g2의 정점 0~2 삽입
	insertedge(g2, 0, 2);
	insertedge(g2, 0, 1);
	insertedge(g2, 1, 2);
	insertedge(g2, 1, 0);
	insertedge(g2, 2, 1);
	insertedge(g2, 2, 0);
	printf("\n\n g2의 인접 리스트");
	print_adjlist(g2);

	// 그래프 g3
	for (i = 0; i < 4; i++)
		insertvertex(g3, i); // g3의 정점 0~3 삽입
	insertedge(g3, 0, 3);
	insertedge(g3, 0, 1);
	insertedge(g3, 1, 3);
	insertedge(g3, 1, 2);
	insertedge(g3, 2, 3);
	printf("\n\n g3의 인접 리스트");
	print_adjlist(g3);

	// 그래프 g4
	for (i = 0; i < 3; i++)
		insertvertex(g4, i); // g4의 정점 0~2 삽입
	insertedge(g4, 0, 2);
	insertedge(g4, 0, 1);
	insertedge(g4, 1, 2);
	insertedge(g4, 1, 0);
	printf("\n\n g4의 인접 리스트");
	print_adjlist(g4);
}