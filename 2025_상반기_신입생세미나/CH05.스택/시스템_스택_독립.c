#include <stdio.h>

void F_1() {
    printf("2. F_1 �Լ� ȣ��\n");
    printf("3. ȣ��� F_1 �Լ� ����\n");
    printf("4. F_1() �Լ� ���� ����, main()���� ����\n");
}

void F_2() {
    printf("5. F_2 �Լ� ȣ��\n");
    printf("6. ȣ��� F_2 �Լ� ����\n");
    printf("7. F_2() �Լ� ���� ����, main()���� ����\n");
}

int main() {
    printf("1. main �Լ� ���� ����\n");
    F_1(); 
    F_2();  
    printf("8. main() �Լ� ���� �Ϸ�(��ü ���α׷� ���� �Ϸ�)\n");
    return 0;
}