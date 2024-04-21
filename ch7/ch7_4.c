```c
#include <unistd.h> // execlp 함수를 사용하기 위한 헤더 파일
#include <stdlib.h> // exit 함수를 사용하기 위한 헤더 파일
#include <stdio.h> // 표준 입출력 함수를 사용하기 위한 헤더 파일

int main() {
    printf("--> Before exec function\n"); // "--> Before exec function"을 출력

    if (execlp("ls", "ls", "-a", (char *)NULL) == -1) { // execlp 함수를 사용하여 "ls -a" 명령어를 실행하고, 에러 발생 시 처리
        perror("execlp"); // 에러 메시지 출력
        exit(1); // 프로그램 종료
    }

    printf("--> After exec function\n"); // "After exec function"을 출력 (실행되지 않음)
}
```
위의 코드는 execlp 함수를 사용하여 "ls -a" 명령어를 실행하는 예제입니다. 프로그램이 execlp를 호출하면 현재 프로세스의 메모리 이미지가 새 프로그램으로 대체되므로 "--> Before exec function" 다음에 오는 코드는 실행되지 않습니다. 

\