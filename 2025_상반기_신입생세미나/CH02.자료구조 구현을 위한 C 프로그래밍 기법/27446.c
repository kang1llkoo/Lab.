#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int pages[101] = { 0 };  // 페이지 번호 존재 여부를 체크할 배열
    int d[101];  // 잃어버린 페이지 번호를 저장할 배열
    int d_size = 0;  // d 배열의 크기

    // 바닥에 흩어진 페이지 번호 입력 받기
    for (int i = 0; i < M; i++) {
        int page;
        scanf("%d", &page);
        if (page <= N) {
            pages[page] = 1;  // 해당 페이지는 존재한다고 표시
        }
    }

    // 잃어버린 페이지 번호들을 d 배열에 저장
    for (int i = 1; i <= N; i++) {
        if (pages[i] == 0) {
            d[d_size++] = i;
        }
    }

    int last = 0;  // 가장 최근에 본 잃어버린 페이지 번호
    int result = 0;  // 사용한 잉크량

    // 잃어버린 페이지 번호들 처리
    for (int i = 0; i < d_size; i++) {
        if (last) {
            result += min(7, (d[i] - last) * 2);  // 새롭게 인쇄하거나, 연속적으로 인쇄할 때의 최소 잉크 사용
        }
        else {
            result += 7;  // 처음에 완전히 새롭게 인쇄해야 함
        }
        last = d[i];  // 현재 페이지 번호를 마지막으로 갱신
    }

    printf("%d\n", result);  // 최종 사용된 잉크량 출력

    return 0;
}
