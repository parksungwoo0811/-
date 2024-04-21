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
    if ((pid = fork()) < 0) { // fork 함수가 실패한 경우
        perror("fork");        // 오류 메시지를 출력합니다.
        exit(1);               // 프로그램을 종료합니다.
    }

    if (pid == 0) { // 자식 프로세스인 경우
        printf("--> Child process\n"); // 자식 프로세스임을 출력합니다.
        sleep(3);                       // 3초간 대기합니다.
        exit(3);                        // 자식 프로세스를 종료합니다.
    }

    printf("--> Parent process\n"); // 부모 프로세스임을 출력합니다.

    // waitpid 함수를 사용하여 자식 프로세스의 종료를 기다립니다.
    while (waitpid(pid, &status, WNOHANG) == 0) {
        printf("Parent still wait...\n"); // 부모 프로세스가 여전히 대기 중임을 출력합니다.
        sleep(1);                         // 1초간 대기합니다.
    }

    // 자식 프로세스의 종료 상태를 출력합니다.
    printf("Child Exit Status : %d\n", status>>8); // 자식 프로세스의 종료 상태를 출력합니다.
}
```
```shell
Output:
--> Parent process
--> Child process
Parent still wait...
Parent still wait...
Parent still wait...
Child Exit Status : 3
```
```plaintext
Parent process부터 시작해서 자식 프로세스를 생성하고 대기합니다.
자식 프로세스는 "Child process"를 출력한 후 3초간 대기한 뒤 종료됩니다.
부모 프로세스는 waitpid 함수를 사용하여 자식 프로세스의 종료를 기다립니다.
WNOHANG 옵션을 사용하여 블로킹되지 않고 대기합니다.
자식 프로세스가 종료되면 그에 대한 종료 상태를 출력합니다.
```