```c
#include <sys/types.h> // 시스템 관련 자료형을 다루는 헤더 파일인 sys/types.h를 포함합니다.
#include <sys/stat.h> // 파일의 상태 정보를 다루는 헤더 파일인 sys/stat.h를 포함합니다.
#include <unistd.h> // UNIX 표준 헤더 파일인 unistd.h를 포함합니다. stat, link 함수를 사용하기 위해 필요합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. printf 함수를 사용하기 위해 필요합니다.

int main() {
    struct stat statbuf; // 파일의 상태 정보를 저장할 stat 구조체 변수를 선언합니다.

    // "linux.txt" 파일의 상태 정보를 얻어옵니다.
    stat("linux.txt", &statbuf);
    // 링크 생성 전의 "linux.txt" 파일의 링크 수를 출력합니다.
    printf("Before Link Count = %d\n", (int)statbuf.st_nlink);

    // "linux.txt" 파일에 대한 하드 링크인 "linux.ln"을 생성합니다.
    link("linux.txt", "linux.ln");

    // 링크 생성 후의 "linux.txt" 파일의 상태 정보를 다시 얻어옵니다.
    stat("linux.txt", &statbuf);
    // 링크 생성 후의 "linux.txt" 파일의 링크 수를 출력합니다.
    printf("After Link Count = %d\n", (int)statbuf.st_nlink);
}
```

이 코드는 "linux.txt" 파일에 대한 하드 링크를 생성하고, 링크 생성 전과 후의 "linux.txt" 파일의 링크 수를 출력합니다. link 함수를 사용하여 하드 링크를 생성할 수 있습니다.