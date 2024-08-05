#include <stdio.h>

int main() {
    int age = 25;
    int *p;      // 포인터 변수 선언
    p = &age;    // 포인터 변수에 age의 주소 저장

    printf("Value of age: %d\n", age);       // 변수 값 출력
    printf("Address of age: %p\n", &age);  // 변수의 메모리 주소 출력
    printf("Pointer p holds address: %p\n", p); // 포인터가 저장한 주소 출력
    printf("Value pointed to by p: %d\n", *p);   // 포인터가 가리키는 주소의 값 출력
    return 0;
}