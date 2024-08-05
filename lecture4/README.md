# 포인터 산술

## 1. 포인터 산술이란?

포인터 산술은 포인터를 통해 메모리 주소를 이동하는 연산을 의미합니다. 포인터는 메모리 주소를 가리키므로, 포인터에 수학적 연산을 적용하면 가리키는 주소가 변경됩니다. 이러한 연산은 주로 배열과 함께 사용됩니다.

## 2. 포인터 연산의 종류

### 1. 증가 연산 (`++`)

포인터를 한 요소 앞으로 이동시킵니다.

`p++;` // 포인터 p가 다음 요소를 가리키도록 이동

### 2. 감소 연산 (`--`)

포인터를 한 요소 뒤로 이동시킵니다.

`p--;` // 포인터 p가 이전 요소를 가리키도록 이동

### 3. 덧셈 연산 (`+`)

포인터를 여러 요소 앞으로 이동시킵니다.

`p += n;` // 포인터 p가 n 요소 앞으로 이동

### 4. 뺄셈 연산 (`-`)

포인터를 여러 요소 뒤로 이동시킵니다.

`p -= n;` // 포인터 p가 n 요소 뒤로 이동

## 3. 포인터 산술의 예제

### 배열과 포인터의 관계

배열 이름은 배열의 첫 번째 요소를 가리키는 포인터로 사용될 수 있습니다.

```c
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;  // 배열 이름은 포인터로 사용 가능

    printf("Initial value: %d\n", *p);  // 10 출력

    p++;  // 포인터를 다음 요소로 이동
    printf("After p++: %d\n", *p);  // 20 출력

    p += 2;  // 포인터를 두 요소 앞으로 이동
    printf("After p += 2: %d\n", *p);  // 40 출력

    p--;  // 포인터를 이전 요소로 이동
    printf("After p--: %d\n", *p);  // 30 출력

    return 0;
}
```

### 포인터 비교

두 포인터가 같은 메모리 주소를 가리키는지 비교할 수 있습니다.

```c
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p1 = arr;
    int *p2 = &arr[2];

    if (p1 + 2 == p2) {
        printf("p1 + 2와 p2는 같은 주소를 가리킵니다.\n");
    } else {
        printf("p1 + 2와 p2는 다른 주소를 가리킵니다.\n");
    }

    return 0;
}
```

위의 예제에서 p1 + 2와 p2가 같은 주소를 가리키는지 비교하여 결과를 출력합니다.

## 4. 요약

- 포인터 산술은 포인터를 통해 메모리 주소를 이동하는 연산입니다.
- 증가 연산(`++`)과 감소 연산(`--`)은 포인터를 한 요소 앞으로 또는 뒤로 이동시킵니다.
- 덧셈 연산(`+`)과 뺄셈 연산(`-`)은 포인터를 여러 요소 앞으로 또는 뒤로 이동시킵니다.
- 배열 이름은 배열의 첫 번째 요소를 가리키는 포인터로 사용될 수 있습니다.
- 포인터 비교를 통해 두 포인터가 같은 메모리 주소를 가리키는지 확인할 수 있습니다.