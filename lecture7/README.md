# 구조체와 포인터

## 1. 구조체란 무엇인가?

구조체(struct)는 서로 관련된 여러 데이터를 하나의 단위로 묶는 방법입니다. 구조체를 사용하면 다양한 데이터 타입을 하나의 변수로 관리할 수 있습니다.

### 구조체 선언

구조체를 선언하려면 `struct` 키워드를 사용합니다.

```c
struct Point {
    int x;
    int y;
};
```

위 예제에서 `Point` 구조체는 두 개의 정수형 변수 `x`와 `y`를 포함합니다.

### 구조체 변수 선언

구조체 변수를 선언하려면 구조체 이름을 사용합니다.

```c
struct Point p1;
```

## 2. 구조체와 포인터

구조체 포인터를 사용하면 구조체 변수의 주소를 저장하고, 이를 통해 구조체 멤버에 접근할 수 있습니다.

### 구조체 포인터 선언

구조체 포인터를 선언하려면 구조체 이름 뒤에 \* 기호를 사용합니다.

```c
struct Point *p;
```

### 구조체 포인터 초기화

구조체 포인터를 초기화하려면 malloc 함수를 사용하여 메모리를 할당하고, 구조체 포인터에 할당된 메모리의 주소를 저장합니다.

```c
p = (struct Point*)malloc(sizeof(struct Point));
```

### 구조체 멤버 접근

구조체 포인터를 사용하여 구조체 멤버에 접근하려면 `->` 연산자를 사용합니다.

```c
p->x = 10;
p->y = 20;
```

### 예제: 구조체와 포인터 사용하기

다음은 구조체와 포인터를 사용하는 간단한 예제입니다.

```c
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
```
