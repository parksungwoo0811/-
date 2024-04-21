```c
#include <sys/types.h> // 시스템 관련 자료형을 다루는 헤더 파일인 sys/types.h를 포함합니다.
#include <sys/stat.h> // 파일의 상태 정보를 다루는 헤더 파일인 sys/stat.h를 포함합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. printf 함수를 사용하기 위해 필요합니다.

int main() {
    struct stat statbuf; // 파일의 상태 정보를 저장할 stat 구조체 변수를 선언합니다.

    // "linux.txt" 파일의 상태 정보를 얻어옵니다.
    stat("linux.txt", &statbuf);
    // 파일의 모드를 출력합니다.
    printf("Mode = %o\n", (unsigned int)statbuf.st_mode);

    // 파일의 소유자에 대한 읽기 권한을 확인하고, 있다면 메시지를 출력합니다.
    if ((statbuf.st_mode & S_IREAD) != 0)
        printf("linux.txt: User has a read permission\n");

    // 파일의 그룹에 대한 읽기 권한을 확인하고, 있다면 메시지를 출력합니다.
    if ((statbuf.st_mode & (S_IREAD >> 3)) != 0)
        printf("linux.txt: Group has a read permission\n");

    // 파일의 기타 사용자에 대한 읽기 권한을 확인하고, 있다면 메시지를 출력합니다.
    if ((statbuf.st_mode & S_IROTH) != 0)
        printf("linux.txt: Other have a read permission\n");
}
```

이 코드는 "linux.txt" 파일의 모드를 확인하여 소유자, 그룹, 기타 사용자의 읽기 권한 여부를 출력합니다. 파일의 상태 정보를 얻어온 후에는 비트 연산을 사용하여 각 사용자에 대한 읽기 권한을 확인합니다. S_IREAD는 사용자에 대한 읽기 권한을 나타내며, S_IREAD >> 3은 그룹에 대한 읽기 권한을 나타냅니다. S_IROTH는 기타 사용자에 대한 읽기 권한을 나타냅니다.