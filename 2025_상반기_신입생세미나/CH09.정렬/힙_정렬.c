#include <stdio.h>
#define SIZE 8

// �� �籸�� �Լ� (�ִ� ��)
void makeheap(int a[], int h, int m) {
    int temp = a[h]; // �θ� ��� �� ����
    int j;

    for (j = 2 * h; j <= m; j *= 2) {
        if (j < m && a[j] < a[j + 1]) { // �� �ڽ� �� �� ū �� ����
            j++;
        }

        if (temp >= a[j]) { // �θ� �ڽĺ��� ũ�ٸ� �� ���� ������
            break;
        }

        a[j / 2] = a[j]; // �θ� ��带 �ڽ� ������ ��ü
    }
    a[j / 2] = temp; // ���� �θ� ��带 �ùٸ� ��ġ�� ����
}

// �� ����
void heapsort(int a[], int n) {
    int i, temp;

    // �ִ� �� ����
    for (i = n / 2; i >= 1; i--) {
        makeheap(a, i, n);
    }

    // ���� ����
    for (i = n - 1; i >= 1; i--) {
        temp = a[1];     // ��Ʈ(�ִ�)�� ������ ��Ҹ� ��ȯ
        a[1] = a[i + 1];
        a[i + 1] = temp;

        makeheap(a, 1, i);
    }
}

int main() {
    int list[SIZE + 1] = { 0, 69, 10, 30, 2, 16, 8, 31, 22 }; // 1�� �ε������� ���
    int size = SIZE;

    printf("���� �� �迭 : ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", list[i]);
    }

    heapsort(list, size);

    printf("\n���� �� �迭 : ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", list[i]);
    }

    return 0;
}