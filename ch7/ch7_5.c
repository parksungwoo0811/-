```c
#include <unistd.h> // execv 함수를 사용하기 위한 헤더 파일
#include <stdlib.h> // exit 함수를 사용하기 위한 헤더 파일
#include <stdio.h> // 표준 입출력 함수를 사용하기 위한 헤더 파일

int main() {
    char *argv[3]; // 문자열 포인터 배열 argv를 선언

    printf("Before exec function\n"); // "Before exec function"을 출력

    argv[0] = "ls"; // argv[0]에 "ls"를 할당
    argv[1] = "-a"; // argv[1]에 "-a"를 할당
    argv[2] = NULL; // argv[2]에 NULL을 할당
    if (execv("/usr/bin/ls", argv) == -1) { // execv 함수를 사용하여 "/usr/bin/ls" 명령어를 실행하고, 에러 발생 시 처리
        perror("execv"); // 에러 메시지 출력
        exit(1); // 프로그램 종료
    }

    printf("After exec function\n"); // "After exec function"을 출력 (실행되지 않음)
}
```
