#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *p;

    p = (char*)calloc(20, sizeof(char));  // 문자열을 저장할 수 있는 메모리 할당 및 초기화
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Allocated string: %s\n", p);  // 문자열은 초기화되면 NULL로 출력됨
    strcpy(p, "Hello");  // 할당된 메모리에 문자열 복사
    printf("Allocated string: %s\n", p);  // 초기화된 메모리 값 출력

    free(p);  // 할당된 메모리 해제
    return 0;
}