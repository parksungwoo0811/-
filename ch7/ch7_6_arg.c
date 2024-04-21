```c
#include <stdio.h>

int main(int argc, char **argv, char **envp) {
    int n;        // 반복문에서 사용할 변수
    char **env;   // 환경 변수 배열을 가리키는 포인터

    // 프로그램이 시작할 때 실행되는 메인 함수의 시작 부분을 출력합니다.
    printf("\n--> In ch7_6_arg.c Main\n");

    // 전달된 명령행 매개변수의 개수를 출력합니다.
    printf("argc = %d\n", argc);

    // 명령행 매개변수를 출력합니다.
    for (n = 0; n < argc; n++)
        printf("argv[%d] = %s\n", n, argv[n]);

    // 환경 변수를 출력합니다.
    env = envp;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}
```
```plaintext
출력:
--> In ch7_6_arg.c Main
argc = 1
argv[0] = ./ch7_6_arg
TERM=xterm-256color
SHELL=/usr/bin/bash
...
```
```plaintext
이 프로그램은 명령행 매개변수와 환경 변수를 출력하는 예제입니다.
```