```c
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다.
#include <stdlib.h> // 표준 라이브러리 헤더 파일인 stdlib.h를 포함합니다.
#include <dirent.h> // 디렉토리 조작 관련 헤더 파일인 dirent.h를 포함합니다.

int main() {
    DIR *dp; // 디렉토리 포인터 변수를 선언합니다.
    struct dirent *dent; // dirent 구조체 포인터 변수를 선언합니다.

    // 현재 디렉토리를 열고, 디렉토리 포인터 변수에 할당합니다.
    dp = opendir(".");

    // 디렉토리 내의 모든 파일을 순회하면서 파일의 이름과 inode 번호를 출력합니다.
    while ((dent = readdir(dp))) {
        printf("Name : %s ", dent->d_name); // 파일의 이름을 출력합니다.
        printf("Inode : %d\n", (int)dent->d_ino); // 파일의 inode 번호를 출력합니다.
    }

    // 디렉토리를 닫습니다.
    closedir(dp);
}
```

이 코드는 현재 디렉토리의 모든 파일의 이름과 inode 번호를 출력합니다. readdir 함수를 사용하여 디렉토리 내의 파일을 하나씩 읽고, 해당 파일의 이름과 inode 번호를 출력합니다. 마지막으로 디렉토리를 닫습니다.