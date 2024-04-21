```c
#include <time.h> // 시간 관련 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    time_t timep; // time_t 타입 변수를 선언합니다.

    time(&timep); // 현재 시각을 time_t 형식으로 가져옵니다.

    printf("Time(sec) : %ld\n", (long)timep); // 초 단위로 된 현재 시간을 출력합니다.
    printf("Time(date) : %s", ctime(&timep)); // 현재 시간을 문자열로 변환하여 출력합니다.

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 현재 시간을 초 단위로 및 날짜와 시간으로 출력하는 예제입니다. `time` 함수로 현재 시간을 얻고 `ctime` 함수로 해당 시간을 문자열로 변환하여 사용합니다.