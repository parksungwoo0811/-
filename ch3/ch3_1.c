```c
#include <sys/types.h> // 시스템 관련 자료형을 다루는 헤더 파일인 sys/types.h를 포함합니다.
#include <sys/stat.h> // 파일의 상태 정보를 다루는 헤더 파일인 sys/stat.h를 포함합니다.
#include <unistd.h> // UNIX 표준 헤더 파일인 unistd.h를 포함합니다. stat 함수를 사용하기 위해 필요합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. printf 함수를 사용하기 위해 필요합니다.

int main() {
    struct stat statbuf; // 파일의 상태 정보를 저장할 stat 구조체 변수를 선언합니다.

    // "linux.txt" 파일의 상태 정보를 얻어와 statbuf 구조체에 저장합니다.
    stat("linux.txt", &statbuf);

    // 파일의 상태 정보를 출력합니다.
    printf("Inode = %d\n", (int)statbuf.st_ino); // 파일의 inode 번호를 출력합니다.
    printf("Mode = %o\n", (unsigned int)statbuf.st_mode); // 파일의 모드를 출력합니다.
    printf("Nlink = %o\n",(unsigned int) statbuf.st_nlink); // 파일의 링크 수를 출력합니다.
    printf("UID = %d\n", (int)statbuf.st_uid); // 파일의 소유자 UID를 출력합니다.
    printf("GID = %d\n", (int)statbuf.st_gid); // 파일의 그룹 GID를 출력합니다.
    printf("SIZE = %d\n", (int)statbuf.st_size); // 파일의 크기를 출력합니다.
    printf("Blksize = %d\n", (int)statbuf.st_blksize); // 파일의 블록 크기를 출력합니다.
    printf("Blocks = %d\n", (int)statbuf.st_blocks); // 파일이 사용하는 블록 수를 출력합니다.

    // 파일의 최근 접근 시간, 최근 수정 시간, 최근 변경 시간을 출력합니다.
    printf("** timespec Style\n");
    printf("Atime = %d\n", (int)statbuf.st_atim.tv_sec); // 최근 접근 시간을 출력합니다.
    printf("Mtime = %d\n", (int)statbuf.st_mtim.tv_sec); // 최근 수정 시간을 출력합니다.
    printf("Ctime = %d\n", (int)statbuf.st_ctim.tv_sec); // 최근 변경 시간을 출력합니다.
    printf("** old Style\n");
    printf("Atime = %d\n", (int)statbuf.st_atime); // 최근 접근 시간을 출력합니다.
    printf("Mtime = %d\n", (int)statbuf.st_mtime); // 최근 수정 시간을 출력합니다.
    printf("Ctime = %d\n", (int)statbuf.st_ctime); // 최근 변경 시간을 출력합니다.
}
```

이 코드는 "linux.txt" 파일의 상태 정보를 얻어와서 각각의 정보를 출력합니다. 파일의 상태 정보에는 inode 번호, 파일 모드, 링크 수, 소유자 UID, 그룹 GID, 파일 크기, 블록 크기, 사용하는 블록 수, 최근 접근 시간, 최근 수정 시간, 최근 변경 시간 등이 있습니다. 여기서 최근 접근 시간, 최근 수정 시간, 최근 변경 시간은 timespec 구조체를 이용하는 스타일과 기존의 스타일로 출력합니다.