#include <stdio.h>

void F_1() {
    printf("2. F_1 함수 호출\n");
    printf("3. 호출된 F_1 함수 실행\n");
    printf("4. F_1() 함수 실행 종료, main()으로 복귀\n");
}

void F_2() {
    printf("5. F_2 함수 호출\n");
    printf("6. 호출된 F_2 함수 실행\n");
    printf("7. F_2() 함수 실행 종료, main()으로 복귀\n");
}

int main() {
    printf("1. main 함수 실행 시작\n");
    F_1(); 
    F_2();  
    printf("8. main() 함수 실행 완료(전체 프로그램 실행 완료)\n");
    return 0;
}