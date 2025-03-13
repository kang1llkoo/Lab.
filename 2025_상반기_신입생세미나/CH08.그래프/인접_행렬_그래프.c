#include <stdio.h>
#include <stdlib.h>
#define max_vertex 30

// 그래프를 인접 행렬로 표현하기 위한 구조체 정의
typedef struct graphtype{
	int n; // 그래프 node 수
	int adjmatrix[max_vertex][max_vertex]; // 30*30의 2차원 배열
} graphtype;

// 공백 그래프 생성
void creategraph(graphtype* g) {
	int i, j;
	g->n = 0; // node 개수를 0으로 초기화
	for (i = 0; i < max_vertex; i++) {
		for (j = 0; j < max_vertex; j++)
			g->adjmatrix[i][j] = 0; // 그래프 g에 대한 2차원 배열 값을 모두 0으로 초기화
	}
}

void insertvertex(graphtype* g, int v) {
	if (((g->n) + 1) > max_vertex) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++; // 그래프 정점의 개수 n을 하나 증가
}

// 그래프 g에 간선 (u, v)를 삽입하는 연산
void insertedge(graphtype* g, int u, int v) {
	// 간선 (u, v)를 삽입하기 위해 정점 u와 v가 그래프에 존재하는지 확인
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	g->adjmatrix[u][v] = 1; // 삽입한 간선에 대한 2차원 배열의 원소값을 1로 설정
}

// 그래프 g의 2차원 배열값을 순서대로 출력
void print_adjmatrix(graphtype* g) {
	int i, j;
	for (i = 0; i < (g->n); i++) {
		printf("\n\t\t");
		for (j = 0; j < (g->n); j++) {
			printf("%2d", g->adjmatrix[i][j]);
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
	insertedge(g1, 0, 1);
	insertedge(g1, 0, 3);
	insertedge(g1, 1, 0);
	insertedge(g1, 1, 2);
	insertedge(g1, 1, 3);
	insertedge(g1, 2, 1);
	insertedge(g1, 2, 3);
	insertedge(g1, 3, 0);
	insertedge(g1, 3, 1);
	insertedge(g1, 3, 2);
	printf("\n g1의 인접 행렬");
	print_adjmatrix(g1);

	// 그래프 g2
	for (i = 0; i < 3; i++)
		insertvertex(g2, i); // g2의 정점 0~2 삽입
	insertedge(g2, 0, 1);
	insertedge(g2, 0, 2);
	insertedge(g2, 1, 0);
	insertedge(g2, 1, 2);
	insertedge(g2, 2, 0);
	insertedge(g2, 2, 1);
	printf("\n\n g2의 인접 행렬");
	print_adjmatrix(g2);

	// 그래프 g3
	for (i = 0; i < 4; i++)
		insertvertex(g3, i); // g3의 정점 0~3 삽입
	insertedge(g3, 0, 1);
	insertedge(g3, 0, 3);
	insertedge(g3, 1, 2);
	insertedge(g3, 1, 3);
	insertedge(g3, 2, 3);
	printf("\n\n g3의 인접 행렬");
	print_adjmatrix(g3);

	// 그래프 g4
	for (i = 0; i < 3; i++)
		insertvertex(g4, i); // g4의 정점 0~2 삽입
	insertedge(g4, 0, 1);
	insertedge(g4, 0, 2);
	insertedge(g4, 1, 0);
	insertedge(g4, 1, 2);
	printf("\n\n g4의 인접 행렬");
	print_adjmatrix(g4);
}
