```c
#include <sys/types.h> // 시스템 관련 자료형을 다루는 헤더 파일인 sys/types.h를 포함합니다.
#include <sys/stat.h> // 파일의 상태 정보를 다루는 헤더 파일인 sys/stat.h를 포함합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. printf 함수를 사용하기 위해 필요합니다.

int main() {
    struct stat statbuf; // 파일의 상태 정보를 저장할 stat 구조체 변수를 선언합니다.

    // "linux.txt" 파일의 모드를 변경하여 사용자에게 읽기, 쓰기, 실행 권한을 주고,
    // 그룹에게 읽기, 실행 권한을 주고, 기타 사용자에게 읽기 권한을 주는 코드입니다.
    chmod("linux.txt", S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH);

    // 변경된 모드를 확인하기 위해 다시 "linux.txt" 파일의 상태 정보를 얻어옵니다.
    stat("linux.txt", &statbuf);
    // 변경된 모드를 출력합니다.
    printf("1.Mode = %o\n", (unsigned int)statbuf.st_mode);

    // "linux.txt" 파일의 상태 정보에서 그룹에 대한 쓰기 권한을 추가하고,
    // 기타 사용자에 대한 읽기 권한을 제거하는 코드입니다.
    statbuf.st_mode |= S_IWGRP; // 그룹에 대한 쓰기 권한 추가
    statbuf.st_mode &= ~(S_IROTH); // 기타 사용자에 대한 읽기 권한 제거

    // 변경된 모드를 적용하기 위해 chmod 함수를 호출합니다.
    chmod("linux.txt", statbuf.st_mode);

    // 변경된 모드를 확인하기 위해 다시 "linux.txt" 파일의 상태 정보를 얻어옵니다.
    stat("linux.txt", &statbuf);
    // 변경된 모드를 출력합니다.
    printf("2.Mode = %o\n", (unsigned int)statbuf.st_mode);
}
```

이 코드는 "linux.txt" 파일의 모드를 변경하고 변경된 모드를 출력합니다. chmod 함수를 사용하여 파일의 모드를 변경할 수 있습니다. statbuf.st_mode 변수를 수정하여 새로운 모드를 지정한 후에는 변경된 모드를 chmod 함수로 적용합니다.