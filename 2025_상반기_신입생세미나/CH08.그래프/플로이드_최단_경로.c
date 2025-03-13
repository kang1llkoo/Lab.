#include <stdio.h>
#include <limits.h>

#define max_vertices 5 // 그래프 정점 수
#define inf 10000

int weight[max_vertices][max_vertices] = { // 그래프 g11의 가중치 인접 행렬
	{0, 10, 5, inf, inf},
	{inf, 0, 2, 1, inf},
	{inf, 3, 0, 9, 2},
	{inf, inf, inf, 0, 4},
	{7, inf, inf, 6, 0},
};

int a[max_vertices][max_vertices]; // k-최단 경로 배열

// 최단 경로를 구하는 과정 출력
void printstep(int step) {
	int i, j;
	printf("\n a%d : ", step);
	for (i = 0; i < max_vertices; i++) {
		printf("\t");
		for (j = 0; j < max_vertices; j++) {
			if (a[i][j] == inf)
				printf("%4c", '*');
			else printf("%4d", a[i][j]);
		}
		printf("\n\n");
	}
}

void floyd_shortestpath(int n) {
	int v, w, k, step = -1;

	for (v = 0; v < n; v++)
		for (w = 0; w < n; w++)
			a[v][w] = weight[v][w];

	printstep(step);

	for (k = 0; k < n; k++) {
		for (v = 0; v < n; v++)
			for (w = 0; w < n; w++)
				if (a[v][k] + a[k][w] < a[v][w])
					a[v][w] = a[v][k] + a[v][k];
		printstep(++step);
	}
}

void main() {
	int i, j;
	printf("\n ********** 가중치 인접 행렬 **********\n\n");
	for (i = 0; i < max_vertices; i++) {
		for (j = 0; j < max_vertices; j++) {
			if (weight[i][j] == inf)
				printf("%4c", '*');
			else printf("%4d", weight[i][j]);
		}
		printf("\n\n");
	}

	printf("\n ********** 플로이드 최단 경로 구하기 **********\n\n");
	floyd_shortestpath(max_vertices);
}