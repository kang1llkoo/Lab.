#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    scanf("%s", str);

    int arr[26];
    int n;

    for (int i = 0; i < 26; i++) {
        arr[i] = -1;
    }

    for (int i = 0; i < strlen(str); i++) {
        n = str[i] - 'a';
        if (arr[n] == -1) arr[n] = i;
    }

    for (int i = 0; i < 26; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}