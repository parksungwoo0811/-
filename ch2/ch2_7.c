```c
#include <fcntl.h> // 파일 제어 관련 헤더 파일인 fcntl.h를 포함합니다.
#include <unistd.h> // UNIX 표준 헤더 파일인 unistd.h를 포함합니다. getcwd, fchdir, close 함수를 사용하기 위해 필요합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. printf 함수를 사용하기 위해 필요합니다.
#include <stdlib.h> // 표준 라이브러리 헤더 파일인 stdlib.h를 포함합니다. free 함수를 사용하기 위해 필요합니다.

int main() {
    char *cwd; // 현재 작업 디렉토리를 저장할 포인터 변수를 선언합니다.
    int fd; // 파일 디스크립터를 저장할 변수를 선언합니다.

    // 현재 작업 디렉토리를 얻어와 cwd 포인터에 저장합니다.
    cwd = getcwd(NULL, BUFSIZ);
    // 얻어온 현재 작업 디렉토리를 출력합니다.
    printf("1.Current Directory : %s\n", cwd);

    // "bit" 파일을 읽기 전용으로 열고, 해당 파일 디스크립터를 fd 변수에 저장합니다.
    fd = open("bit", O_RDONLY);
    // 파일 디스크립터를 이용하여 디렉토리를 변경합니다.
    fchdir(fd);

    // 변경된 현재 작업 디렉토리를 얻어와 cwd 포인터에 저장합니다.
    cwd = getcwd(NULL, BUFSIZ);
    // 얻어온 변경된 현재 작업 디렉토리를 출력합니다.
    printf("2.Current Directory : %s\n", cwd);

    // 파일 디스크립터를 닫습니다.
    close(fd);
    // 동적으로 할당된 메모리를 해제합니다.
    free(cwd);
}
```

이 코드는 현재 작업 디렉토리를 얻어와 출력한 후, "bit" 파일을 열어서 해당 파일의 디렉토리로 변경하고 변경된 디렉토리를 다시 출력합니다. 파일을 열 때 사용한 파일 디스크립터를 닫고, 동적으로 할당된 메모리를 해제합니다.