#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// ���� ����
typedef struct {
	char items[MAX];
	int top;
} stack;

// ���� �ʱ�ȭ
void initstack(stack* s) {
	s->top = -1;
}

// ������ ������� �˻�
int isempty(stack* s) {
	return s->top == -1;
}

// ������ ���ִ��� �˻�
int isfull(stack* s) {
	return s->top == MAX - 1;
}

// ���ÿ� push
void push(stack* s, char c) {
	if (isfull(s)) {
		printf("Stack Overflow");
		return;
	}
	s->items[++(s->top)] = c;
}

// ���ÿ� pop
char pop(stack* s) {
	if (isempty(s)) {
		printf("Stack Underflow!");
		return '\0';
	}
	return s->items[(s->top)--];
}

// ������ top ���Ҹ� Ȯ��
char peek(stack* s) {
	if (isempty(s)) return '\0';
	return s->items[s->top];
}

// �������� �켱���� �ľ�
int precedence(char op) {
	switch (op) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	default: return 0;
	}
}

// ���� ǥ����� ���� ǥ������� ��ȯ
void infixToPost(const char* infix, char* postfix) {
    stack s; // ���� ����ü ����
    initstack(&s); // ���� �ʱ�ȭ
    int j = 0;
    int i = 0;
    char symbol; // ���� ǥ����� �� ���� ó��

    while ((symbol = infix[i++]) != '\0') {
        if (isalnum(symbol)) {
            // 1. �ǿ����ڴ� �״�� ���
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            // 2. ���� ��ȣ�� ���� (���ÿ� �������� ����)
            continue;
        }
        else if (symbol == ')') {
            // 3. ������ ��ȣ�� ������ ������ pop�Ͽ� ���
            while (!isempty(&s)) {
                char top = pop(&s);
                if (top == '(') break; // '('�� ������ ����
                postfix[j++] = top;
            }
        }
        else {
            // 4. ������ ó�� (�켱������ ���� ���ÿ��� pop �� push)
            while (!isempty(&s) && precedence(peek(&s)) >= precedence(symbol)) {
                postfix[j++] = pop(&s);
            }
            push(&s, symbol);
        }
    }

    // 5. ������ ������ ������ ������ �� ������ pop�Ͽ� ���
    while (!isempty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
	char infix[MAX]; // ���� ǥ��� ���� ����
	char postfix[MAX]; // ��µ� ���� ǥ���

	printf("���� ǥ��� �Է�: ");
	scanf("%s", infix);

	infixToPost(infix, postfix);
	printf("��ȯ�� ���� ǥ���: %s\n", postfix);

	return 0;
}