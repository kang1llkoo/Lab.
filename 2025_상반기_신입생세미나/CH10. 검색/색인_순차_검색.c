#include <stdio.h>
#define index_size 3
typedef int element;

//인덱스 테이블 구조(index, key) 정의
typedef struct{
    int index;
    element key;
} itable;

itable indextable[index_size]; // 인덱스 테이블 indextable 생성

// 배열 a의 begin 원소와 end 원소 사이에서 key를 순차 검색
void sequentialsearch2(element a[], int begin, int end, element key){
    int i = begin;

    printf("\n %d를 검색하라! ->> ", key);
    while(i<end && a[i]<key) i++;

    if(a[i] == key) printf("%d번째에 검색 성공!\n\n", (i-begin)+1);
    else printf("%d번째에 검색 실패! \n\n", (i-begin)+1);
}

// 배열 a에 대한 인덱스 테이블 만들기
void makeindextable(element a[], int size){
    int i, n;
    n = size / index_size; // 인덱스 테이블에 들어가는 배열 원소의 간격 계산
    if (size % index_size > 0) n = n + 1;
    for (i=0; i<index_size; i++){ // 인덱스 테이블 채우기
        indextable[i].index = i*n;
        indextable[i].key = a[i*n];
    }
}

// 색인 순차 검색
void indexsearch(element a[], int n, element key){
    int i, begin, end;
    if (key < a[0] || key > a[n-1]){
        printf("\n찾는 키가 없습니다. 검색 실패! \n");
    }

    // 인덱스 테이블을 검색하여 검색 범위 설정
    for (i=0; i<index_size; i++){
        if((indextable[i].key <= key) && (indextable[i+1].key > key)){
            begin = indextable[i].index;
            end = indextable[i+1].index;
            break;
        }
    }
    if (i == index_size){
        begin = indextable[i-1].index;
        end = n;
    }
    sequentialsearch2(a, begin, end, key); // 검색 범위에 대한 순차 검색 수행
}

void main(){
    element a[] = {1, 2, 8, 9, 11, 19, 29};
    int n = 7;
    printf("\n\t<< 색인 순차 검색 >>\n");
    makeindextable(a, n);
    indexsearch(a, n, 9); // 배열 a의 n개 원소 중에서 탐색키가 9인 원소 검색
    indexsearch(a, n, 6); // 배열 a의 n개 원소 중에서 탐색키가 6인 원소 검색
}