```c
#include <sys/types.h> // 시스템 관련 자료형을 다루는 헤더 파일인 sys/types.h를 포함합니다.
#include <sys/stat.h> // 파일의 상태 정보를 다루는 헤더 파일인 sys/stat.h를 포함합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. printf 함수를 사용하기 위해 필요합니다.

int main() {
    struct stat statbuf; // 파일의 상태 정보를 저장할 stat 구조체 변수를 선언합니다.
    int kind; // 파일의 종류를 나타내는 변수를 선언합니다.

    // "linux.txt" 파일의 상태 정보를 얻어옵니다.
    stat("linux.txt", &statbuf);

    // 파일의 모드를 출력합니다.
    printf("Mode = %o\n", (unsigned int)statbuf.st_mode);

    // 파일의 종류를 나타내는 비트를 추출합니다.
    kind = statbuf.st_mode & S_IFMT;
    printf("Kind = %o\n", kind);

    // 파일의 종류에 따라 메시지를 출력합니다.
    switch (kind) {
        case S_IFLNK:
            printf("linux.txt: Symbolic Link\n"); // 심볼릭 링크인 경우 메시지 출력
            break;
        case S_IFDIR:
            printf("linux.txt: Directory\n"); // 디렉터리인 경우 메시지 출력
            break;
        case S_IFREG:
            printf("linux.txt: Regular File\n"); // 일반 파일인 경우 메시지 출력
            break;
    }
}
```

이 코드는 "linux.txt" 파일의 종류를 확인하여 심볼릭 링크, 디렉터리, 일반 파일 여부를 출력합니다. 먼저 파일의 상태 정보를 얻어온 후에는 파일의 종류를 나타내는 비트를 추출합니다. 이후 switch 문을 사용하여 파일의 종류에 따라 적절한 메시지를 출력합니다.