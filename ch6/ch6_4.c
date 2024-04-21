```c
#include <unistd.h>
#include <stdio.h>

int main() {
    // 현재 프로세스의 PID를 출력합니다.
    printf("PID : %d\n", (int)getpid());
    // 현재 프로세스 그룹의 PGID를 출력합니다.
    printf("PGID : %d\n", (int)getpgrp());
    // 현재 프로세스의 세션 ID를 출력합니다.
    printf("SID : %d\n", (int)getsid(0));
}
```