```c
#include <time.h> // 시간 관련 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    struct tm tm; // tm 구조체 변수를 선언합니다.
    time_t timep; // time_t 타입 변수를 선언합니다.

    time(&timep); // 현재 시각을 time_t 형식으로 가져옵니다.
    printf("Current Time(sec) : %ld\n", (long)timep); // 현재 시간을 초 단위로 출력합니다.

    // tm 구조체에 특정 날짜와 시간을 설정합니다.
    tm.tm_year = 121; // 2021년부터의 년도 (년도 - 1900)
    tm.tm_mon = 4; // 5월 (0부터 시작하므로 5월은 4로 표시)
    tm.tm_mday = 1; // 1일
    tm.tm_hour = 23; // 23시
    tm.tm_min = 59; // 59분
    tm.tm_sec = 0; // 0초

    // tm 구조체로부터 time_t 형식으로 변환합니다.
    timep = mktime(&tm);
    printf("2021/05/01 23:59:00 Time(sec) : %ld\n", (long)timep); // 변환된 시간을 출력합니다.

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 `mktime` 함수를 사용하여 2021년 5월 1일 23시 59분을 지정한 후, 이를 초 단위로 출력하는 예제입니다.