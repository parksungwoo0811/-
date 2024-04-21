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

    // 파일의 종류를 확인하고, 해당하는 종류에 따라 메시지를 출력합니다.
    if(S_ISLNK(statbuf.st_mode)) 
        printf("linux.txt : Symbolic Link\n"); // 심볼릭 링크인 경우 메시지 출력
    if(S_ISDIR(statbuf.st_mode)) 
        printf("linux.txt : Directory\n"); // 디렉터리인 경우 메시지 출력
    if(S_ISREG(statbuf.st_mode)) 
        printf("linux.txt : Regular File\n"); // 일반 파일인 경우 메시지 출력
}
```

이 코드는 "linux.txt" 파일의 종류를 확인하여 심볼릭 링크, 디렉터리, 일반 파일 여부를 출력합니다. S_ISLNK, S_ISDIR, S_ISREG 매크로를 사용하여 파일의 종류를 확인합니다. 파일의 상태 정보를 얻어온 후에는 해당 매크로를 사용하여 파일의 종류를 판별합니다.