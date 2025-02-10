#include <stdio.h>

void F_2() {
	printf("4. F_2 함수 호출\n");
	printf("5. 호출된 F_2 함수 실행\n");
	printf("6. F_2() 함수 실행 종료, F_1() 함수로 복귀\n");
}

void F_1() {
    printf("2. F_1 함수 호출\n");
    printf("3. 호출된 F_1 함수 실행\n");

    F_2();  // F_1 내부에서 F_2 호출

    printf("7. F_1() 함수로 복귀하여 F_1() 함수의 나머지 실행\n");
    printf("8. F_1() 함수로 복귀하여 F_1() 함수의 나머지 부분 실행\n");
}

int main() {
    printf("1. main 함수 실행 시작\n");
    F_1();  // F_1 실행 (내부에서 F_2 호출됨)
    printf("9. main() 함수 실행 완료(전체 프로그램 실행 완료)\n");
    return 0;
}