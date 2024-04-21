```c
#include <stdio.h>

int main(int argc, char **argv, char **envp) {
    char **env;

    // 1. 모든 환경 변수를 출력합니다.
    env = envp;
    while (*env) {
        printf("%s\n", *env); // 환경 변수를 출력합니다.
        env++;
    }
}
```

한줄요약: 프로그램이 실행될 때 전달된 환경 변수를 모두 출력하는 예제입니다.