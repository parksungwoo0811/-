```c
#include <unistd.h>
#include <stdio.h>

int main() {
    // 현재 프로세스의 PID를 출력합니다.
    printf("PID : %d\n", (int)getpid());
    // 현재 프로세스의 프로세스 그룹 ID(PGRP)를 출력합니다.
    printf("PGRP : %d\n", (int)getpgrp());
    // PID가 0인 프로세스의 프로세스 그룹 ID(PGID)를 출력합니다.
    printf("PGID(0) : %d\n", (int)getpgid(0));
    // PID가 18020인 프로세스의 프로세스 그룹 ID(PGID)를 출력합니다.
    printf("PGID(18020) : %d\n", (int)getpgid(18020));
}
```