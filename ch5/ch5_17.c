```c
#include <time.h> // 시간 관련 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    struct tm *tm; // tm 구조체 포인터를 선언합니다.
    time_t timep; // time_t 타입 변수를 선언합니다.

    time(&timep); // 현재 시각을 time_t 형식으로 가져옵니다.
    printf("Time(sec) : %ld\n", (long)timep); // 현재 시간을 초 단위로 출력합니다.

    tm = gmtime(&timep); // UTC 기준 시간을 tm 구조체로 변환합니다.
    printf("GMTIME=Y:%d M:%d D:%d H:%d M:%d S:%d\n", 
           tm->tm_year, tm->tm_mon, tm->tm_mday, 
           tm->tm_hour, tm->tm_min, tm->tm_sec); // UTC 기준 시간을 출력합니다.

    tm = localtime(&timep); // 지역 시간대 기준 시간을 tm 구조체로 변환합니다.
    printf("LOCALTIME=Y:%d M:%d D:%d H:%d M:%d S:%d\n", 
           tm->tm_year, tm->tm_mon, tm->tm_mday, 
           tm->tm_hour, tm->tm_min, tm->tm_sec); // 지역 시간대 기준 시간을 출력합니다.

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 현재 시각을 초 단위로 가져온 후, 이를 UTC 기준 시간과 지역 시간대 기준 시간으로 변환하여 출력하는 예제입니다.