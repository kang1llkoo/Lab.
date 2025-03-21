#include <stdio.h>
typedef int element;
int i; // 이진 검색의 연산 횟수

void binarysearch(element a[], int begin, int end, element key){
    int middle;
    i++; // 이진 검색 연산 횟수 1 증가
    if (begin == end){ // 검색 범위가 한 개인 경우
        if (key == a[begin]) printf("%d번째에 검색 성공!\n\n", i);
        else printf("%d번째에 검색 실패! \n\n", i);
        return;
    }

    middle = (begin + end) / 2;
    if(key == a[middle]) printf("%d번째에 검색 성공!\n\n", i);
    else if (key < a[middle] && (middle-1 >= begin)){
        binarysearch(a, begin, middle-1, key);
    }
    else if (key > a[middle] && (middle+1 <= end)){
        binarysearch(a, middle + 1, end, key);
    }
    else printf("%d번째에 검색 실패!\n\n", i);
}

void main(){
    element a[] = {1, 2, 8, 9, 11, 19, 29}, key;
    int n = 7;

    i = 0; printf("\n %d를 검색하라! ->> ", key = 11);
    binarysearch(a, 0, n-1, key); // 탐색키가 11인 원소 검색

    i = 0; printf("\n %d를 검색하라! ->> ", key = 6);
    binarysearch(a, 0, n-1, key); // 탐색키가 6인 원소 검색

    printf("\n %d를 검색하라! ->> ", key = 2); i=0;
    binarysearch(a, 0, n-1, key); // 탐색키가 2인 원소 검색
}
