#include <unistd.h> // UNIX 표준 헤더 파일인 unistd.h를 포함합니다. getcwd, chdir 함수를 사용하기 위해 필요합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. printf 함수를 사용하기 위해 필요합니다.
#include <stdlib.h> // 표준 라이브러리 헤더 파일인 stdlib.h를 포함합니다. free 함수를 사용하기 위해 필요합니다.

int main() {
    char *cwd; // 현재 작업 디렉토리를 저장할 포인터 변수를 선언합니다.

    // getcwd 함수를 사용하여 현재 작업 디렉토리를 얻어와 cwd 포인터에 저장합니다.
    cwd = getcwd(NULL, BUFSIZ);
    // 얻어온 현재 작업 디렉토리를 출력합니다.
    printf("1.Current Directory : %s\n", cwd);

    // chdir 함수를 사용하여 현재 작업 디렉토리를 "bit" 디렉토리로 변경합니다.
    chdir("bit");

    // 변경된 현재 작업 디렉토리를 다시 얻어와 cwd 포인터에 저장합니다.
    cwd = getcwd(NULL, BUFSIZ);
    // 얻어온 현재 작업 디렉토리를 출력합니다.
    printf("2.Current Directory : %s\n", cwd);

    // 동적으로 할당된 메모리를 해제합니다.
    free(cwd);
}
