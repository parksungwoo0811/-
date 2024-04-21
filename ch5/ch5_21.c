```c
#include <time.h> // 시간 관련 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

char *output[] = {"%x %X", "%G년 %m월 %d일 %U주 %H:%M", "%r"}; // 출력 형식을 배열로 정의합니다.

int main() {
    struct tm *tm; // tm 구조체 포인터를 선언합니다.
    int n;
    time_t timep; // time_t 타입 변수를 선언합니다.
    char buf[257]; // 출력 문자열을 저장할 배열을 선언합니다.

    time(&timep); // 현재 시각을 time_t 형식으로 가져옵니다.
    tm = localtime(&timep); // 로컬 시간으로 변환하여 tm 구조체에 저장합니다.

    // 각 출력 형식에 대해 strftime 함수를 사용하여 문자열을 생성하고 출력합니다.
    for (n = 0; n < 3; n++) {
        strftime(buf, sizeof(buf), output[n], tm); // strftime 함수를 사용하여 형식화된 시간 문자열을 생성합니다.
        printf("%s = %s\n", output[n], buf); // 생성된 문자열을 출력합니다.
    }

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 현재 시간을 세 가지 다른 형식으로 출력하는 예제입니다. strftime 함수를 사용하여 시간을 형식화하고 출력 형식에 따라 출력합니다.