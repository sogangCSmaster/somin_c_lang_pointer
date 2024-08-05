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
