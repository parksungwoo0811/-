```c
#include <stdlib.h> // exit, atexit, on_exit 함수를 사용하기 위한 헤더 파일
#include <stdio.h> // 표준 입출력 함수를 사용하기 위한 헤더 파일

void cleanup1() {
    printf("Cleanup 1 is called.\n"); // "Cleanup 1 is called."을 출력
}

void cleanup2(int status, void *arg) {
    printf("Cleanup 2 is called: %ld.\n", (long) arg); // "Cleanup 2 is called: %ld."를 출력하고 arg 값을 출력
}

int main() {
    atexit(cleanup1); // 프로그램 종료 시 cleanup1 함수를 호출하도록 등록
    on_exit(cleanup2, (void *) 20); // 프로그램 종료 시 cleanup2 함수를 호출하도록 등록

    exit(0); // 프로그램을 종료
}
```
위의 코드는 atexit 함수와 on_exit 함수를 사용하여 프로그램이 종료될 때 각각 cleanup1과 cleanup2 함수를 호출하도록 하는 예제입니다.  

