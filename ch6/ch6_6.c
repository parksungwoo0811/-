```c
#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main() {
    char **env;

    // 1. 현재 프로세스의 환경 변수를 출력합니다.
    env = environ;
    while (*env) {
        printf("%s\n", *env); // 환경 변수를 출력합니다.
        env++;
    }
}
```

한줄요약: 현재 프로세스의 환경 변수를 출력하는 예제입니다.