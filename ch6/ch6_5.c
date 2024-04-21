```c
#include <sys/types.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int i; // 반복문을 위한 카운터 변수
    time_t t; // 시간을 저장하는 변수
    struct tms buf; // CPU 시간 정보를 저장하는 구조체
    clock_t ct, t1, t2; // 클럭 틱, 시간 측정을 위한 변수

    // 클럭 틱 값을 확인하여 출력합니다.
    ct = sysconf(_SC_CLK_TCK);
    printf("Clock tick : %ld\n", ct);

    // 프로세스의 CPU 시간을 측정하기 위해 시간을 기록합니다.
    if ((t1 = times(&buf)) == -1) { // 첫 번째 times 호출
        perror("times 1"); // 오류 발생 시 메시지 출력
        exit(1); // 프로그램 종료
    }

    // CPU를 사용하도록 하는 작업을 수행합니다.
    for (i = 0; i < 99999999; i++)
        time(&t); // 시간을 반복적으로 읽어와서 무의미한 작업을 수행합니다.

    sleep(1); // 1초 동안 대기합니다.

    // CPU 시간을 다시 측정합니다.
    if ((t2 = times(&buf)) == -1) { // 두 번째 times 호출
        perror("times 2"); // 오류 발생 시 메시지 출력
        exit(1); // 프로그램 종료
    }

    // 시간 정보를 출력합니다.
    printf("t1: %ld\n", t1); // 첫 번째 시간
    printf("t2: %ld\n", t2); // 두 번째 시간
    printf("utime : %ld\n", buf.tms_utime); // 사용자 CPU 시간
    printf("stime : %ld\n", buf.tms_stime); // 시스템 CPU 시간
    printf("Real time : %.1f sec\n", (double)(t2 - t1) / ct); // 실제 시간
    printf("User time : %.1f sec\n", (double)buf.tms_utime / ct); // 사용자 CPU 시간
    printf("System time : %.1f sec\n", (double)buf.tms_stime / ct); // 시스템 CPU 시간
}
```