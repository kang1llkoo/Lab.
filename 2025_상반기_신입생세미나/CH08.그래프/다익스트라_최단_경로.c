#include <stdio.h>
#include <limits.h>

#define true 1
#define false 0
#define max_vertices 5 // 그래프 정점 개수
#define inf 10000

int weight[max_vertices][max_vertices] = { // 그래프 g11의 가중치 인접 행렬
	{0, 10, 5, inf, inf},
	{inf, 0, 2, 1, inf},
	{inf, 3, 0, 9, 2},
	{inf, inf, inf, 0, 4},
	{7, inf, inf, 6, 0},
};
int distance[max_vertices]; // 시작 정점에서 시작하는 최단 경로 길이 지정
int s[max_vertices]; // 정점 집합 s

// 최단 경로를 갖는 다음 정점 찾는 연산
int nextvertex(int n) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i<n;i++)
		if ((distance[i] < min) && !s[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

int printstep(int step) {
	int i;
	printf("\n %3d 단계 : s = {", step);
	for (i = 0; i < max_vertices; i++)
		if (s[i] == true)
			printf("%3c", i + 65);

	if (step < 1) printf(" } \t\t\t");
	else if (step < 4) printf(" } \t\t");
	else printf(" } \t");

	printf(" distance : [");
	for (i = 0; i < max_vertices; i++) {
		if (distance[i] == inf)
			printf("%4c", '*');
		else
			printf("%4d", distance[i]);
	}
	printf(" ]");
	return ++step;
}

void dijkstra_shortestpath(int start, int n) {
	int i, u, w, step = 0;

	for (i = 0; i < n; i++) { // 초기화
		distance[i] = weight[start][i];
		s[i] = false;
	}

	s[start] = true; // 시작 정점을 집합 s에 추가
	distance[start] = 0; // 시작 정점의 최단 경로를 0으로 설정

	step = printstep(0); // 0단계 상태 출력

	for (i = 0; i < n - 1; i++) {
		u = nextvertex(n); // 최단 경로를 만드는 다음 정점 u 찾기
		s[u] = true; // 정점 u를 집합 s에 추가
		for (w = 0; w < n; w++)
			if (!s[w]) // 집합 s에 포함되지 않은 정점 중
				if (distance[u] + weight[u][w] < distance[w])
					distance[w] = distance[u] + weight[u][w]; // 경로 길이 수정

		step = printstep(step); // 현재 단계 출력
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

	printf("\n ********** 다익스트라 최단 경로 구하기 **********\n\n");
	dijkstra_shortestpath(0, max_vertices);
}