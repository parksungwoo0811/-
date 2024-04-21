```c
#include <time.h> // 시간 관련 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    struct tm *tm; // tm 구조체 포인터를 선언합니다.
    time_t timep; // time_t 타입 변수를 선언합니다.

    time(&timep); // 현재 시각을 time_t 형식으로 가져옵니다.
    tm = localtime(&timep); // 로컬 시간으로 변환하여 tm 구조체에 저장합니다.

    printf("Time(sec) : %ld\n", (long)timep); // 초 단위로 된 현재 시간을 출력합니다.
    printf("Time(date) : %s", asctime(tm)); // 현재 시간을 문자열로 변환하여 출력합니다.

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 현재 시간을 초 단위로 및 날짜와 시간으로 출력하는 예제입니다. `time` 함수로 현재 시간을 얻고 `localtime` 함수로 해당 시간을 구조체 형식으로 변환하여 사용합니다. `asctime` 함수를 사용하여 시간 구조체를 문자열로 변환하여 출력합니다.