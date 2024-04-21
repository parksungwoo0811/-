```c
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int status;       // 자식 프로세스의 종료 상태를 저장하는 변수
    pid_t pid;        // fork 함수의 반환값인 자식 프로세스의 PID를 저장하는 변수

    // fork 함수를 사용하여 자식 프로세스를 생성합니다.
    switch (pid = fork()) {
        case -1 : // fork 함수가 실패한 경우
            perror("fork"); // 오류 메시지를 출력합니다.
            exit(1);        // 프로그램을 종료합니다.
            break;
        case 0 : // 자식 프로세스인 경우
            printf("--> Child Process\n"); // 자식 프로세스임을 출력합니다.
            exit(2);                        // 자식 프로세스를 종료합니다.
            break;
        default : // 부모 프로세스인 경우
            // wait 함수를 사용하여 자식 프로세스의 종료를 기다립니다.
            while (wait(&status) != pid)
                continue;
            printf("--> Parent process\n"); // 부모 프로세스임을 출력합니다.
            // 자식 프로세스의 종료 상태를 출력합니다.
            printf("Status: %d, %x\n", status, status);
            printf("Child process Exit Status:%d\n", status >> 8);
            break; 
    }
}
```
```shell
Output:
--> Child Process
--> Parent process
Status: 512, 200
Child process Exit Status:2
```
```plaintext
부모 프로세스가 자식 프로세스를 생성하고, 자식 프로세스가 "Child Process"를 출력한 후 종료합니다.
부모 프로세스가 자식 프로세스의 종료를 기다리며, 종료 상태를 출력합니다.
```