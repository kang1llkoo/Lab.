#include <stdio.h>
typedef int element;

void sequentialsearch2(element a[], int n, element key){
    int i = 0;
    printf("\n %d를 검색하라! ->> ", key);
    while (a[i] < key) i++;
    if (a[i] == key) printf("%d번째에 검색 성공!\n\n", i+1);
    else printf("%d번째에 검색 실패! \n\n", i+1);
}

void main(){
    element a[] = {1, 2, 8, 9, 11, 19, 29};
    int n = 7;

    sequentialsearch2(a, n, 9);
    sequentialsearch2(a, n, 6);
}