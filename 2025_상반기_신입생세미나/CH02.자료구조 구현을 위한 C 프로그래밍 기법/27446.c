#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int pages[101] = { 0 };  // ������ ��ȣ ���� ���θ� üũ�� �迭
    int d[101];  // �Ҿ���� ������ ��ȣ�� ������ �迭
    int d_size = 0;  // d �迭�� ũ��

    // �ٴڿ� ����� ������ ��ȣ �Է� �ޱ�
    for (int i = 0; i < M; i++) {
        int page;
        scanf("%d", &page);
        if (page <= N) {
            pages[page] = 1;  // �ش� �������� �����Ѵٰ� ǥ��
        }
    }

    // �Ҿ���� ������ ��ȣ���� d �迭�� ����
    for (int i = 1; i <= N; i++) {
        if (pages[i] == 0) {
            d[d_size++] = i;
        }
    }

    int last = 0;  // ���� �ֱٿ� �� �Ҿ���� ������ ��ȣ
    int result = 0;  // ����� ��ũ��

    // �Ҿ���� ������ ��ȣ�� ó��
    for (int i = 0; i < d_size; i++) {
        if (last) {
            result += min(7, (d[i] - last) * 2);  // ���Ӱ� �μ��ϰų�, ���������� �μ��� ���� �ּ� ��ũ ���
        }
        else {
            result += 7;  // ó���� ������ ���Ӱ� �μ��ؾ� ��
        }
        last = d[i];  // ���� ������ ��ȣ�� ���������� ����
    }

    printf("%d\n", result);  // ���� ���� ��ũ�� ���

    return 0;
}
