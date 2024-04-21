```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    char *val;

    // 1. 환경 변수 SHELL이 설정되어 있는지 확인하고 값을 출력합니다.
    val = getenv("SHELL");
    if (val == NULL)
        printf("SHELL not defined\n"); // SHELL이 정의되어 있지 않으면 해당 메시지를 출력합니다.
    else
        printf("SHELL = %s\n", val); // SHELL의 값을 출력합니다.
}
```

한줄요약: 환경 변수 SHELL을 확인하고 해당 값이 존재하면 출력하는 예제입니다.