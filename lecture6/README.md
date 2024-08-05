# 동적 메모리 할당

## 1. 동적 메모리 할당이란?

동적 메모리 할당은 프로그램 실행 중에 메모리를 할당하고 필요할 때 해제하는 것을 의미합니다. 정적 메모리 할당과 달리, 동적 메모리 할당은 프로그램이 실행되는 동안 필요한 만큼 메모리를 요청하고 사용할 수 있습니다. 이를 통해 메모리를 효율적으로 사용할 수 있습니다.

## 2. 동적 메모리 할당의 필요성

- **유연성**: 컴파일 시점에 크기가 정해진 배열 대신, 실행 시점에 필요한 크기의 메모리를 할당할 수 있습니다.
- **메모리 절약**: 필요한 만큼만 메모리를 할당하여 사용하지 않는 메모리를 절약할 수 있습니다.
- **복잡한 데이터 구조**: 링크드 리스트, 트리, 그래프와 같은 동적 데이터 구조를 구현할 때 필수적입니다.

## 3. 동적 메모리 할당 함수

C 언어에서는 동적 메모리 할당을 위해 `malloc`, `calloc`, `realloc`, `free` 함수를 사용합니다.

### malloc 함수

`malloc` 함수는 지정한 바이트 수만큼의 메모리를 할당하고, 성공하면 그 메모리의 시작 주소를 반환합니다. 할당된 메모리의 내용은 초기화되지 않습니다.

#### 정수형 예제

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;

    p = (int*)malloc(sizeof(int) * 5);  // 정수형 5개를 저장할 수 있는 메모리 할당
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        p[i] = i * 10;  // 할당된 메모리 초기화
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", p[i]);  // 할당된 메모리 값 출력
    }
    printf("\n");

    free(p);  // 할당된 메모리 해제
    return 0;
}
```

#### 문자형 예제

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *p;

    p = (char*)malloc(sizeof(char) * 10);  // 문자형 10개를 저장할 수 있는 메모리 할당
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 9; i++) {
        p[i] = 'A' + i;  // 할당된 메모리 초기화
    }
    p[9] = '\0';  // 문자열 종료 문자 추가

    printf("Allocated string: %s\n", p);  // 할당된 메모리 값 출력

    free(p);  // 할당된 메모리 해제
    return 0;
}
```

#### 문자열 예제

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[] = "Hello";
    char *p;

    p = (char*)malloc(strlen(text) + 1);  // 문자열 길이 + 1 (종료 문자) 만큼 메모리 할당
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(p, text);  // 할당된 메모리에 문자열 복사
    printf("Allocated string: %s\n", p);  // 할당된 메모리 값 출력

    free(p);  // 할당된 메모리 해제
    return 0;
}
```

### calloc 함수

`calloc` 함수는 `malloc`과 유사하지만, 할당된 메모리를 0으로 초기화합니다.

#### 정수형 예제

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;

    p = (int*)calloc(5, sizeof(int));  // 정수형 5개를 저장할 수 있는 메모리 할당 및 초기화
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", p[i]);  // 초기화된 메모리 값 출력 (모두 0)
    }
    printf("\n");

    free(p);  // 할당된 메모리 해제
    return 0;
}
```

#### 문자형 예제

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *p;

    p = (char*)calloc(10, sizeof(char));  // 문자형 10개를 저장할 수 있는 메모리 할당 및 초기화
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // 메모리가 0으로 초기화되어 있으므로 바로 출력 가능
    printf("Allocated string: %s\n", p);  // 초기화된 메모리 값 출력 (빈 문자열)

    free(p);  // 할당된 메모리 해제
    return 0;
}
```

#### 문자열 예제

```c
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

    strcpy(p, "Hello");  // 할당된 메모리에 문자열 복사
    printf("Allocated string: %s\n", p);  // 초기화된 메모리 값 출력

    free(p);  // 할당된 메모리 해제
    return 0;
}
```

### realloc 함수

`realloc` 함수는 이미 할당된 메모리의 크기를 변경합니다.

#### 정수형 예제

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;

    p = (int*)malloc(sizeof(int) * 5);  // 정수형 5개를 저장할 수 있는 메모리 할당
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        p[i] = i * 10;  // 할당된 메모리 초기화
    }

    p = (int*)realloc(p, sizeof(int) * 10);  // 메모리 크기를 정수형 10개로 확장
    if (p == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    for (int i = 5; i < 10; i++) {
        p[i] = i * 10;  // 확장된 메모리 초기화
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", p[i]);  // 할당된 메모리 값 출력
    }
    printf("\n");

    free(p);  // 할당된 메모리 해제
    return 0;
}
```

#### 문자형 예제

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *p;

    p = (char*)malloc(sizeof(char) * 10);  // 문자형 10개를 저장할 수 있는 메모리 할당
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(p, "Hello");  // 할당된 메모리 초기화
    printf("Initial string: %s\n", p);

    p = (char*)realloc(p, sizeof(char) * 20);  // 메모리 크기를 문자형 20개로 확장
    if (p == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    strcat(p, " World!");  // 확장된 메모리 사용
    printf("Expanded string: %s\n", p);

    free(p);  // 할당된 메모리 해제
    return 0;
}
```

#### 문자열 예제

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[] = "Hello";
    char *p;

    p = (char*)malloc(strlen(text) + 1);  // 문자열 길이 + 1 (종료 문자) 만큼 메모리 할당
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(p, text);  // 할당된 메모리에 문자열 복사
    printf("Initial string: %s\n", p);

    p = (char*)realloc(p, sizeof(char) * 20);  // 메모리 크기를 문자열 길이 + 20 (종료 문자) 만큼 확장
    if (p == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    strcat(p, " World!");  // 확장된 메모리 사용
    printf("Expanded string: %s\n", p);

    free(p);  // 할당된 메모리 해제
    return 0;
}
```

### free 함수

`free` 함수는 동적 할당된 메모리를 해제합니다. 메모리를 해제하지 않으면 메모리 누수가 발생할 수 있습니다.

## 4. 요약

- 동적 메모리 할당은 프로그램 실행 중에 메모리를 할당하고 해제하는 것을 의미합니다.
- malloc 함수는 초기화되지 않은 메모리를 할당하고, calloc 함수는 0으로 초기화된 메모리를 할당합니다.
- realloc 함수는 이미 할당된 메모리의 크기를 변경합니다.
- free 함수는 동적 할당된 메모리를 해제합니다.
- 동적 메모리 할당은 유연한 메모리 사용과 복잡한 데이터 구조 구현에 필수적입니다.
