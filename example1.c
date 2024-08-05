#include <stdio.h>


int main()  {
  // 소민이 나이를 저장하는 변수 somin_age를 선언하고 21로 초기화
  // 변수를 선언하면 컴퓨터는 변수를 저장할 메모리 공간을 할당하고 그 메모리 공간의 주소를 반환
  int somin_age = 21;

  printf("Somin is %d years old\n", somin_age); // 소민 나이 값
  
  
  // 밑에서부터는 값이 아닌 소민이 나이를 저장하고 있는 메모리 주소를 출력
  printf("Address of somin_age: %p\n", &somin_age); // %p는 포인터를 출력할 때 사용하는 서식 지정자; 16진수 주소 출력

  // %p가 아닌 다른 서식 지정자를 사용하여 출력도 가능
  printf("Address of somin_age in decimal: %d\n", &somin_age); // 주소를 10진수로 출력
  printf("Address of somin_age in octal: %o\n", &somin_age); // 주소를 8진수로 출력
  printf("Address of somin_age in hexadecimal: %x\n", &somin_age); // 주소를 16진수로 출력
  return 0;
}

// MacOS나 Linux에서 실행하는 방법
// gcc -o example1 example1.c
// ./example1