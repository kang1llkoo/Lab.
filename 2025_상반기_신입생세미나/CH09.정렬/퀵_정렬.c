#include <stdio.h>
typedef int element;
int size, i = 0;

// �־��� �κ����� �� �ǹ� ��ġ Ȯ���Ͽ� ���� ��ġ�� ���ϴ� ����
int partition(element a[], int begin, int end) {
	int pivot, L, R, t;
	element temp;
	L = begin;
	R = end;
	pivot = (int)((begin + end) / 2.0); // �߰� ��ġ ���Ҹ� �ǹ����� ����

	printf("\n [ %d�ܰ� : pivot = %d ] \n", ++i, a[pivot]);
	while (L < R) {
		while ((a[L] < a[pivot]) && (L < R)) L++;
		while ((a[R] >= a[pivot]) && (L < R)) R--;
		if (L < R) { // L�� R�� ���Ҹ� �ڸ� ��ȯ
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;

			if (L == pivot) // L�� �ǹ��� ���
				pivot = R; // ����� �ǹ� ��ġ ����
		} // if (L < R)
	} // while(L < R)

	// (L=R)�� �� ���,
	// �� �̻� ������ �� �����Ƿ� R ���ҿ� �ǹ� ������ �ڸ��� ��ȯ�Ͽ� ������
	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;
	for (t = 0; t < size; t++) printf(" %d", a[t]); // ������ ���� ���� ���
	printf("\n");
	return R; // ���ĵǾ� Ȯ���� �ǹ��� ��ġ ��ȯ
}

void quicksort(element a[], int begin, int end) {
	int p;
	if (begin < end) {
		p = partition(a, begin, end); // �ǹ� ��ġ�� ���� ���� ��ġ ����
		quicksort(a, begin, p - 1); // �ǹ� ���� �κ����տ� ���� �� ���� ���ȣ��
		quicksort(a, p + 1, end); // �ǹ� ������ �κ����տ� ���� �� ���� ���ȣ��
	}
}

void main() {
	element list[8] = { 69, 10, 30 ,2, 16, 8, 31, 22 };
	size = 8;
	printf("\n [�ʱ� ����] \n");
	for (int i = 0; i < size; i++) printf(" %d", list[i]);
	printf("\n");

	quicksort(list, 0, size - 1);
}