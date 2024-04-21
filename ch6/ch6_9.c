```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    char *val;

    // 1. 환경 변수 TERM이 설정되어 있는지 확인하고 값을 출력합니다.
    val = getenv("TERM");
    if (val == NULL)
        printf("TERM not defined\n"); // TERM이 정의되어 있지 않으면 해당 메시지를 출력합니다.
    else
        printf("1. TERM = %s\n", val); // TERM의 값을 출력합니다.

    // 2. 환경 변수 TERM을 vt100으로 설정합니다.
    putenv("TERM=vt100");

    // 변경된 환경 변수 값을 다시 확인하고 출력합니다.
    val = getenv("TERM");
    printf("2. TERM = %s\n", val); // 변경된 TERM의 값을 출력합니다.
}
```

한줄요약: 환경 변수 TERM을 확인하고 vt100으로 설정하여 변경하는 예제입니다.