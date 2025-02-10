#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int pages[101] = { 0 };
    int d[101];
    int d_size = 0;

    for (int i = 0; i < M; i++) {
        int page;
        scanf("%d", &page);
        if (page <= N) {
            pages[page] = 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (pages[i] == 0) {
            d[d_size++] = i;
        }
    }

    int last = 0;  
    int result = 0; 

    for (int i = 0; i < d_size; i++) {
        if (last) {
        }
        else {
            result += 7;  
        }
        last = d[i];  
    }

    printf("%d\n", result);

    return 0;
}
