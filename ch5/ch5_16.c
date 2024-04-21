```c
#include <time.h> // 시간 관련 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    tzset(); // 시간대 정보를 설정합니다.

    printf("Timezone : %ld\n", timezone); // 현재 시간대의 초 이동 값을 출력합니다.
    printf("Daylight : %d\n", daylight); // 현재 시간대가 일광 절약 시간인지 여부를 출력합니다.
    printf("TZname[0] : %s\n", tzname[0]); // 표준 시간대의 이름을 출력합니다.
    printf("TZname[1] : %s\n", tzname[1]); // 일광 절약 시간대의 이름을 출력합니다.

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 `timezone`, `daylight`, `tzname[0]`, `tzname[1]` 변수를 사용하여 현재 시간대 및 일광 절약 시간에 대한 정보를 출력하는 예제입니다. `tzset()` 함수를 호출하여 시간대 정보를 설정한 후, 해당 정보들을 출력합니다.