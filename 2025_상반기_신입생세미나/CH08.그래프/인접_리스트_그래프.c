#include <stdio.h>
#include <stdlib.h>
#define max_vertex 30

// ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct graphnode {
	int vertex;
	struct graphnode* link;
} graphnode;

// �׷����� ���� ����Ʈ�� ǥ���ϱ� ���� ����ü ����
typedef struct graphtype {
	int n;
	graphnode* adjlist_h[max_vertex];
} graphtype;

// ���� �׷����� ����
void creategraph(graphtype* g) {
	int v;
	g->n = 0; // �׷����� ���� ������ 0���� �ʱ�ȭ
	for (v = 0; v < max_vertex; v++)
		g->adjlist_h[v] = NULL; // �׷����� ������ ���� ��� ������ �迭�� NULL�� �ʱ�ȭ
}

// �׷��� g�� ���� v�� �����ϴ� ����
void insertvertex(graphtype* g, int v) {
	if (((g->n) + 1) > max_vertex) {
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
		return;
	}
	g->n++; // �׷����� ���� ���� n�� �ϳ� ����
}

// �׷��� g�� ���� (u, v)�� ����
void insertedge(graphtype* g, int u, int v) {
	graphnode* node;

	// ���� (u, v)�� �����ϱ� ���� ���� u�� ���� v�� ���� �׷����� �ִ��� Ȯ��
	if (u >= g->n || v >= g->n) {
		printf("\n �׷����� ���� �����Դϴ�!");
		return;
	}
	node = (graphnode*)malloc(sizeof(graphnode));
	node->vertex = v;
	node->link = g->adjlist_h[u]; // ���� ������ ���� ��带 ����Ʈ�� ù ��° ���� ����
	g->adjlist_h[u] = node;
}

// �׷��� g�� �� ������ ���� ���� ����Ʈ ���
void print_adjlist(graphtype* g) {
	int i;
	graphnode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t���� %c�� ���� ����Ʈ", i + 65);
		p = g->adjlist_h[i];
		while (p) {
			printf("-> %c", p->vertex + 65); // ���� 0~3�� A~D�� ���
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

	// �׷��� g1
	for (i = 0; i < 4; i++)
		insertvertex(g1, i); // g1�� ���� 0~3 ����
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
	printf("\n g1�� ���� ����Ʈ");
	print_adjlist(g1);

	// �׷��� g2
	for (i = 0; i < 3; i++)
		insertvertex(g2, i); // g2�� ���� 0~2 ����
	insertedge(g2, 0, 2);
	insertedge(g2, 0, 1);
	insertedge(g2, 1, 2);
	insertedge(g2, 1, 0);
	insertedge(g2, 2, 1);
	insertedge(g2, 2, 0);
	printf("\n\n g2�� ���� ����Ʈ");
	print_adjlist(g2);

	// �׷��� g3
	for (i = 0; i < 4; i++)
		insertvertex(g3, i); // g3�� ���� 0~3 ����
	insertedge(g3, 0, 3);
	insertedge(g3, 0, 1);
	insertedge(g3, 1, 3);
	insertedge(g3, 1, 2);
	insertedge(g3, 2, 3);
	printf("\n\n g3�� ���� ����Ʈ");
	print_adjlist(g3);

	// �׷��� g4
	for (i = 0; i < 3; i++)
		insertvertex(g4, i); // g4�� ���� 0~2 ����
	insertedge(g4, 0, 2);
	insertedge(g4, 0, 1);
	insertedge(g4, 1, 2);
	insertedge(g4, 1, 0);
	printf("\n\n g4�� ���� ����Ʈ");
	print_adjlist(g4);
}