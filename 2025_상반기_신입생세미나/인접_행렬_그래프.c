#include <stdio.h>
#include <stdlib.h>
#define max_vertex 30

// �׷����� ���� ��ķ� ǥ���ϱ� ���� ����ü ����
typedef struct graphtype{
	int n; // �׷��� node ��
	int adjmatrix[max_vertex][max_vertex]; // 30*30�� 2���� �迭
} graphtype;

// ���� �׷��� ����
void creategraph(graphtype* g) {
	int i, j;
	g->n = 0; // node ������ 0���� �ʱ�ȭ
	for (i = 0; i < max_vertex; i++) {
		for (j = 0; j < max_vertex; j++)
			g->adjmatrix[i][j] = 0; // �׷��� g�� ���� 2���� �迭 ���� ��� 0���� �ʱ�ȭ
	}
}

void insertvertex(graphtype* g, int v) {
	if (((g->n) + 1) > max_vertex) {
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
		return;
	}
	g->n++; // �׷��� ������ ���� n�� �ϳ� ����
}

// �׷��� g�� ���� (u, v)�� �����ϴ� ����
void insertedge(graphtype* g, int u, int v) {
	// ���� (u, v)�� �����ϱ� ���� ���� u�� v�� �׷����� �����ϴ��� Ȯ��
	if (u >= g->n || v >= g->n) {
		printf("\n �׷����� ���� �����Դϴ�!");
		return;
	}
	g->adjmatrix[u][v] = 1; // ������ ������ ���� 2���� �迭�� ���Ұ��� 1�� ����
}

// �׷��� g�� 2���� �迭���� ������� ���
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

	// �׷��� g1
	for (i = 0; i < 4; i++)
		insertvertex(g1, i); // g1�� ���� 0~3 ����
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
	printf("\n g1�� ���� ���");
	print_adjmatrix(g1);

	// �׷��� g2
	for (i = 0; i < 3; i++)
		insertvertex(g2, i); // g2�� ���� 0~2 ����
	insertedge(g2, 0, 1);
	insertedge(g2, 0, 2);
	insertedge(g2, 1, 0);
	insertedge(g2, 1, 2);
	insertedge(g2, 2, 0);
	insertedge(g2, 2, 1);
	printf("\n\n g2�� ���� ���");
	print_adjmatrix(g2);

	// �׷��� g3
	for (i = 0; i < 4; i++)
		insertvertex(g3, i); // g3�� ���� 0~3 ����
	insertedge(g3, 0, 1);
	insertedge(g3, 0, 3);
	insertedge(g3, 1, 2);
	insertedge(g3, 1, 3);
	insertedge(g3, 2, 3);
	printf("\n\n g3�� ���� ���");
	print_adjmatrix(g3);

	// �׷��� g4
	for (i = 0; i < 3; i++)
		insertvertex(g4, i); // g4�� ���� 0~2 ����
	insertedge(g4, 0, 1);
	insertedge(g4, 0, 2);
	insertedge(g4, 1, 0);
	insertedge(g4, 1, 2);
	printf("\n\n g4�� ���� ���");
	print_adjmatrix(g4);
}