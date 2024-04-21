```c
#include <unistd.h>
#include <stdio.h>

int main() {
    // 현재 프로세스의 PID를 출력합니다.
    printf("PID : %d\n", (int)getpid());
    // 현재 프로세스의 부모 프로세스의 PID를 출력합니다.
    printf("PPID : %d\n", (int)getppid());
}
```