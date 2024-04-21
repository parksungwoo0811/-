#include <sys/sysinfo.h>
#include <stdio.h>

int main() {
    // sysinfo 구조체를 사용하여 시스템 정보를 얻어옵니다.
    struct sysinfo info;
    sysinfo(&info);

    // 총 램 용량 출력: 시스템에 설치된 전체 램 용량
    printf("Total Ram: %ld\n", info.totalram);

    // 사용 가능한 램 용량 출력: 현재 시스템에서 사용 가능한 램 용량
    printf("Free Ram: %ld\n", info.freeram);

    // 현재 실행 중인 프로세스 수 출력
    printf("Num of Processes: %d\n", info.procs);
}
