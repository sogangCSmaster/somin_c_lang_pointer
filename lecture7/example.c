#include <stdio.h>
#include <stdlib.h>

// Point 구조체 정의
struct Point {
    int x;
    int y;
};

// 구조체를 동적으로 할당하고 초기화하는 함수
struct Point* createPoint(int x, int y) {
    struct Point* p = (struct Point*)malloc(sizeof(struct Point));  // 메모리 할당
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    p->x = x;  // 멤버 초기화
    p->y = y;
    return p;  // 구조체 포인터 반환
}

int main() {
    struct Point* p1 = createPoint(10, 20);  // 구조체 포인터 초기화
    if (p1 == NULL) {
        return 1;  // 메모리 할당 실패 시 종료
    }

    printf("Point coordinates: (%d, %d)\n", p1->x, p1->y);  // 구조체 멤버 접근 및 출력

    free(p1);  // 동적 할당된 메모리 해제
    return 0;
}
