#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// 스택 정의
typedef struct {
	char items[MAX];
	int top;
} stack;

// 스택 초기화
void initstack(stack* s) {
	s->top = -1;
}

// 스택이 비었는지 검사
int isempty(stack* s) {
	return s->top == -1;
}

// 스택이 차있는지 검사
int isfull(stack* s) {
	return s->top == MAX - 1;
}

// 스택에 push
void push(stack* s, char c) {
	if (isfull(s)) {
		printf("Stack Overflow");
		return;
	}
	s->items[++(s->top)] = c;
}

// 스택에 pop
char pop(stack* s) {
	if (isempty(s)) {
		printf("Stack Underflow!");
		return '\0';
	}
	return s->items[(s->top)--];
}

// 스택의 top 원소를 확인
char peek(stack* s) {
	if (isempty(s)) return '\0';
	return s->items[s->top];
}

// 연산자의 우선순위 파악
int precedence(char op) {
	switch (op) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	default: return 0;
	}
}

// 중위 표기법을 후위 표기법으로 변환
void infixToPost(const char* infix, char* postfix) {
    stack s; // 스택 구조체 정의
    initstack(&s); // 스택 초기화
    int j = 0;
    int i = 0;
    char symbol; // 중위 표기법의 각 문자 처리

    while ((symbol = infix[i++]) != '\0') {
        if (isalnum(symbol)) {
            // 1. 피연산자는 그대로 출력
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            // 2. 왼쪽 괄호는 무시 (스택에 저장하지 않음)
            continue;
        }
        else if (symbol == ')') {
            // 3. 오른쪽 괄호를 만나면 스택을 pop하여 출력
            while (!isempty(&s)) {
                char top = pop(&s);
                if (top == '(') break; // '('를 만나면 멈춤
                postfix[j++] = top;
            }
        }
        else {
            // 4. 연산자 처리 (우선순위에 따라 스택에서 pop 후 push)
            while (!isempty(&s) && precedence(peek(&s)) >= precedence(symbol)) {
                postfix[j++] = pop(&s);
            }
            push(&s, symbol);
        }
    }

    // 5. 수식이 끝나면 스택이 공백이 될 때까지 pop하여 출력
    while (!isempty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
	char infix[MAX]; // 중위 표기법 수식 선언
	char postfix[MAX]; // 출력될 후위 표기법

	printf("중위 표기법 입력: ");
	scanf("%s", infix);

	infixToPost(infix, postfix);
	printf("변환된 후위 표기법: %s\n", postfix);

	return 0;
}