```c
#include <sys/stat.h> // 파일의 상태 정보를 다루는 헤더 파일인 sys/stat.h를 포함합니다.
#include <unistd.h> // UNIX 표준 헤더 파일인 unistd.h를 포함합니다. stat, unlink 함수를 사용하기 위해 필요합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. printf 함수를 사용하기 위해 필요합니다.

int main() {
    struct stat statbuf; // 파일의 상태 정보를 저장할 stat 구조체 변수를 선언합니다.

    // "linux.ln" 파일의 상태 정보를 얻어와 statbuf 구조체에 저장합니다.
    stat("linux.ln", &statbuf);
    // "linux.ln" 파일의 링크 수를 출력합니다.
    printf("1.linux.ln: Link Count = %d\n", (int)statbuf.st_nlink);

    // "linux.ln" 파일을 삭제합니다.
    unlink("linux.ln");

    // "linux.txt" 파일의 상태 정보를 얻어와 statbuf 구조체에 저장합니다.
    stat("linux.txt", &statbuf);
    // "linux.txt" 파일의 링크 수를 출력합니다.
    printf("2.linux.txt: Link Count = %d\n", (int)statbuf.st_nlink);

    // "linux.sym" 파일을 삭제합니다.
    unlink("linux.sym");
}
```

이 코드는 "linux.ln" 파일과 "linux.sym" 파일을 삭제하고, 각 파일의 삭제 전후 링크 수를 출력합니다. unlink 함수를 사용하여 파일을 삭제할 수 있습니다.