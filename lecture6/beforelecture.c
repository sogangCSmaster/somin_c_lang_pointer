#include <stdio.h>
#include <stdlib.h>

// 정수 배열을 생성하고 포인터를 반환하는 함수
int* createIntArray(int size) {
    int* arr = (int*)malloc(sizeof(int) * size);  // 정수형 배열을 동적으로 할당
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // 배열 초기화
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;  // 예: 0, 10, 20, 30, ...
    }

    return arr;  // 배열 포인터 반환
}

int main() {
    int size = 5;
    
    // 함수 호출 (명시적 캐스팅)
    int* array1 = (int*)createIntArray(size);  
    if (array1 == NULL) {
        return 1;  // 메모리 할당 실패 시 종료
    }

    // 배열 값 출력
    printf("Array1 values: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");

    free(array1);  // 동적 할당된 메모리 해제

    

    // 함수 호출 (명시적 캐스팅 없이)
    int* array2 = createIntArray(size);
    if (array2 == NULL) {
        return 1;  // 메모리 할당 실패 시 종료
    }

    // 배열 값 출력
    printf("Array2 values: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");

    free(array2);  // 동적 할당된 메모리 해제


    /*
    명시적 캐스팅이란 프로그래머가 변수의 타입을 명확하게 변환하는 것을 말합니다. 캐스팅(casting)은 데이터를 한 타입에서 다른 타입으로 변환하는 과정입니다. 명시적 캐스팅은 프로그래머가 타입 변환을 명확하게 지정할 때 사용됩니다.
    명확성: 코드에서 타입 변환이 발생하는 부분을 명확히 표시하여 다른 사람들이 코드를 읽을 때 이해하기 쉽게 합니다.
    C++ 호환성: C++에서는 void* 타입의 포인터를 자동으로 다른 포인터 타입으로 변환하지 않습니다. 따라서 C++ 코드에서는 명시적 캐스팅이 필요합니다.
    */

    return 0;
}
