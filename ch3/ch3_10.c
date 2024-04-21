```c
#include <sys/types.h> // 시스템 관련 자료형을 다루는 헤더 파일인 sys/types.h를 포함합니다.
#include <sys/stat.h> // 파일의 상태 정보를 다루는 헤더 파일인 sys/stat.h를 포함합니다.
#include <unistd.h> // UNIX 표준 헤더 파일인 unistd.h를 포함합니다. stat, lstat 함수를 사용하기 위해 필요합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. printf 함수를 사용하기 위해 필요합니다.

int main() {
    struct stat statbuf; // 파일의 상태 정보를 저장할 stat 구조체 변수를 선언합니다.

    // "linux.txt" 파일의 상태 정보를 출력합니다.
    printf("1. stat : linux.txt ---\n");
    stat("linux.txt", &statbuf);
    printf("linux.txt : Link Count = %d\n", (int)statbuf.st_nlink); // 파일의 링크 수를 출력합니다.
    printf("linux.txt : Inode = %d\n", (int)statbuf.st_ino); // 파일의 inode 번호를 출력합니다.

    // "linux.sym" 파일의 상태 정보를 출력합니다.
    printf("2. stat : linux.sym ---\n");
    stat("linux.sym", &statbuf);
    printf("linux.sym : Link Count = %d\n", (int)statbuf.st_nlink); // 파일의 링크 수를 출력합니다.
    printf("linux.sym : Inode = %d\n", (int)statbuf.st_ino); // 파일의 inode 번호를 출력합니다.

    // "linux.sym" 파일에 대한 symbolic link의 상태 정보를 출력합니다.
    printf("3. lstat : linux.sym ---\n");
    lstat("linux.sym", &statbuf);
    printf("linux.sym : Link Count = %d\n", (int)statbuf.st_nlink); // symbolic link의 링크 수를 출력합니다.
    printf("linux.sym : Inode = %d\n", (int)statbuf.st_ino); // symbolic link의 inode 번호를 출력합니다.
}
```

이 코드는 "linux.txt" 파일과 "linux.sym" 파일에 대한 상태 정보를 출력합니다. stat 함수는 파일의 실제 정보를 가져오지만, lstat 함수는 symbolic link 파일의 정보를 가져옵니다. "linux.sym" 파일은 symbolic link이므로 stat 함수와 lstat 함수의 결과가 다를 수 있습니다.