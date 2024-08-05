#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;  // 배열 이름은 포인터로 사용 가능

    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, *(p + %d) = %d\n", i, arr[i], i, *(p + i));
    }

    return 0;
}