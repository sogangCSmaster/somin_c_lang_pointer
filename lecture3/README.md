# C언어 기초 강의자료: 포인터의 개념

## 1. 포인터란 무엇인가?

포인터는 메모리 주소를 저장하는 변수입니다. 즉, 포인터는 다른 변수의 메모리 주소를 가리키는 변수입니다. 포인터를 사용하면 간접적으로 변수에 접근하고 수정할 수 있습니다.

### 포인터의 필요성

포인터는 다음과 같은 이유로 중요합니다:

- 동적 메모리 할당: 프로그램 실행 중에 메모리를 동적으로 할당하고 해제할 수 있습니다.
- 효율적인 배열 및 문자열 처리: 포인터를 사용하여 배열과 문자열을 효과적으로 처리할 수 있습니다.
- 함수 인자 전달: 함수 호출 시 인자로 포인터를 전달하여 함수 내에서 원래 변수의 값을 변경할 수 있습니다.

## 2. 포인터 변수 선언

포인터 변수를 선언하려면 변수의 데이터 타입 뒤에 `*` 기호를 붙입니다.

```c
int *p;  // 정수형 포인터 변수 선언
```

위의 예제에서는 정수형 포인터 변수 `p`를 선언합니다. 이는 `p`가 정수형 변수의 주소를 저장할 수 있음을 의미합니다.

## 3. 포인터 변수 초기화

포인터 변수를 초기화하려면 다른 변수의 주소를 할당해야 합니다. 주소 연산자 &를 사용하여 변수의 주소를 가져올 수 있습니다.

```c
#include <stdio.h>

int main() {
    int age = 25;  // 정수형 변수 선언 및 초기화
    int *p;       // 정수형 포인터 변수 선언
    p = &age;     // 포인터 변수에 age 변수의 주소를 할당

    printf("Value of age: %d\n", age);         // 변수 값 출력
    printf("Address of age: %p\n", (void*)&age); // 변수의 메모리 주소 출력
    printf("Pointer p holds address: %p\n", (void*)p); // 포인터가 저장한 주소 출력
    printf("Value pointed to by p: %d\n", *p);  // 포인터가 가리키는 주소의 값 출력

    return 0;
}
```

위의 예제에서는 `age` 변수의 주소를 `p` 포인터 변수에 할당합니다. 그런 다음 포인터를 사용하여 `age` 변수의 값을 출력합니다.

## 4. 간접 참조 연산자(\*)

간접 참조 연산자 `*`를 사용하면 포인터가 가리키는 주소에 저장된 값을 가져올 수 있습니다. 이를 통해 포인터를 사용하여 변수의 값을 읽거나 수정할 수 있습니다.

```c
#include <stdio.h>

int main() {
    int age = 25;
    int *p = &age;  // 포인터 변수 선언 및 초기화

    printf("Value of age: %d\n", age);  // 변수 값 출력
    *p = 30;  // 포인터를 사용하여 변수 값 수정
    printf("New value of age: %d\n", age);  // 수정된 변수 값 출력

    return 0;
}

```

위의 예제에서는 포인터 `p`를 사용하여 `age` 변수의 값을 30으로 수정합니다. 이를 통해 포인터를 사용하여 변수의 값을 간접적으로 변경할 수 있음을 보여줍니다.

## 5. 포인터와 배열

배열 이름은 포인터로 사용될 수 있습니다. 배열의 각 요소는 메모리의 연속된 위치에 저장되므로, 포인터를 사용하여 배열 요소에 접근할 수 있습니다.

```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;  // 배열 이름은 포인터로 사용 가능

    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, *(p + %d) = %d\n", i, arr[i], i, *(p + i));
    }

    return 0;
}
```

위의 예제에서는 포인터 `p`를 사용하여 배열 `arr`의 각 요소에 접근합니다. `*(p + i)`는 `arr[i]`와 동일한 값을 출력합니다.

## 6. 요약

- 포인터는 다른 변수의 메모리 주소를 저장하는 변수입니다.
- 포인터 변수를 선언하려면 데이터 타입 뒤에 \* 기호를 붙입니다.
- 포인터 변수를 초기화하려면 변수의 주소를 할당해야 합니다.
- 간접 참조 연산자 \*를 사용하여 포인터가 가리키는 주소에 저장된 값을 가져오거나 수정할 수 있습니다.
- 배열 이름은 포인터로 사용될 수 있으며, 포인터를 사용하여 배열 요소에 접근할 수 있습니다.