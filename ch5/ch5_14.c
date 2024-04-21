```c
#include <sys/types.h> // 시스템 데이터 타입을 정의하는 헤더 파일을 포함합니다.
#include <time.h> // 시간 관련 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    time_t tloc; // 시간 정보를 저장할 변수를 선언합니다.

    time(&tloc); // 현재 시간을 tloc에 저장합니다.
    printf("Time(sec) : %ld\n", (long)tloc); // 초 단위의 현재 시간을 출력합니다.

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 `time()` 함수를 사용하여 현재 시간을 초 단위로 가져와서 출력하는 예제입니다. 