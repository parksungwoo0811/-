#include <stdio.h>

int main(int argc, char *argv[]) {
    int n; // 반복문에서 사용할 변수 선언

    // 전달된 명령행 인수의 개수를 출력
    printf("argc = %d\n", argc);

    // 각 명령행 인수의 값을 출력하는 반복문
    for (n = 0; n < argc; n++)
        printf("argv[%d] = %s\n", n, argv[n]);

    return 0; // 프로그램 정상 종료
}
이 코드는 전달된 명령행 인수의 개수와 각각의 값을 출력합니다.





