#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
} term;

void smTranspose(term a[], term b[]) {
	int m, n, v, i, j, p;
	m = a[0].row;
	n = a[0].col;
	v = a[0].value;
	b[0].row = n;
	b[0].col = m;
	b[0].value = v;
	if (v > 0) {
		p = 1;
		for (i = 0; i<n;i++)
			for(j = 1; j<=v;j++)
				if (a[j].col == i) {
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
	}
}

int main() {
	term a[5] = { {3, 3, 4}, {0, 0, 5}, {0, 2, 8}, {1, 1, 3}, {2, 2, 6} };
	term b[5];

	smTranspose(a, b);

	printf("��ġ ���:\n");
	for (int i = 0; i <= b[0].value; i++) {
		printf("(%d, %d, %d)\n", b[i].row, b[i].col, b[i].value);
	}

	return 0;
}