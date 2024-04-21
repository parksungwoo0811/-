```c
#include <sys/time.h> // 시간과 관련된 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    struct timeval tv; // timeval 구조체를 선언합니다.

    gettimeofday(&tv, NULL); // 현재 시간을 가져옵니다.
    printf("Time(sec) : %ld\n", tv.tv_sec); // 초 단위의 시간을 출력합니다.
    printf("Time(micro-sec) : %ld\n", tv.tv_usec); // 마이크로초 단위의 시간을 출력합니다.

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 `gettimeofday()` 함수를 사용하여 현재 시간을 가져와서 초와 마이크로초 단위로 출력하는 예제입니다. `tv_sec` 필드에는 초가, `tv_usec` 필드에는 마이크로초가 저장되어 있습니다.