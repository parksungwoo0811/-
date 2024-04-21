```c
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    pid_t pid; // fork 함수의 반환값인 자식 프로세스의 PID를 저장하는 변수

    // fork 함수를 사용하여 자식 프로세스를 생성합니다.
    switch (pid = fork()) {
        case -1 : // fork 함수가 실패한 경우
            perror("fork"); // 오류 메시지를 출력합니다.
            exit(1);        // 프로그램을 종료합니다.
            break;
        case 0 : // 자식 프로세스인 경우
            printf("--> Child Process\n"); // 자식 프로세스임을 출력합니다.
            // execlp 함수를 사용하여 ls 명령어를 실행합니다.
            if (execlp("ls", "ls", "-a", (char *)NULL) == -1) {
                perror("execlp"); // 오류 메시지를 출력합니다.
                exit(1);           // 프로그램을 종료합니다.
            }
            exit(0); // 자식 프로세스를 종료합니다.
            break;
        default : // 부모 프로세스인 경우
            printf("--> Parent process - My PID:%d\n", (int)getpid()); // 부모 프로세스임을 출력합니다.
            break;
    }
}
```
```shell
Output:
--> Child Process
.  ..  executable_file  test.c  test_executable_file
--> Parent process - My PID:1959
```
```plaintext
부모 프로세스가 자식 프로세스를 생성하고, 자식 프로세스가 "Child Process"를 출력한 후 ls 명령어를 실행합니다.
부모 프로세스는 "Parent process - My PID:1959"를 출력한 후 종료합니다.
```