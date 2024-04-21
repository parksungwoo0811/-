```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    char *val;

    // 1. 환경 변수 TERM이 설정되어 있는지 확인하고 값을 출력합니다.
    val = getenv("TERM");
    if (val == NULL)
        printf("TERM not defined\n");
    else
        printf("1. TERM = %s\n", val);

    // 2. 환경 변수 TERM을 vt100으로 설정하고 값을 출력합니다.
    setenv("TERM","vt100", 0);
    val = getenv("TERM");
    printf("2. TERM = %s\n", val);

    // 3. 환경 변수 TERM을 vt100으로 설정하고 값을 출력합니다. (이미 존재하는 경우 덮어씁니다.)
    setenv("TERM","vt100", 1);
    val = getenv("TERM");
    printf("3. TERM = %s\n", val);
}
```

한줄요약: 환경 변수 TERM의 설정 여부를 확인하고 변경하는 예제입니다.