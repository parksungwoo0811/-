#include <unistd.h> // UNIX 표준 헤더 파일인 unistd.h를 포함합니다. getcwd 함수를 사용하기 위해 필요합니다.
#include <stdlib.h> // 표준 라이브러리 헤더 파일인 stdlib.h를 포함합니다. free 함수를 사용하기 위해 필요합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. printf 함수를 사용하기 위해 필요합니다.

int main() {
    char *cwd; // 현재 작업 디렉토리를 저장할 포인터 변수를 선언합니다.
    char wd1[BUFSIZ]; // 현재 작업 디렉토리를 저장할 문자 배열을 선언합니다.
    char wd2[10]; // 현재 작업 디렉토리를 저장할 문자 배열을 선언합니다.

    // 현재 작업 디렉토리를 wd1 배열에 저장합니다.
    getcwd(wd1, BUFSIZ);
    // wd1 배열에 저장된 현재 작업 디렉토리를 출력합니다.
    printf("wd1 = %s\n", wd1);
 
    // getcwd 함수를 사용하여 현재 작업 디렉토리를 얻어옵니다.
    cwd = getcwd(NULL, BUFSIZ);
    // 얻어온 현재 작업 디렉토리를 출력합니다.
    printf("cwd1 = %s\n", cwd);
    // 동적으로 할당된 메모리를 해제합니다.
    free(cwd);

    // getcwd 함수를 사용하여 현재 작업 디렉토리를 얻어옵니다. (버퍼 크기 지정하지 않음)
    cwd = getcwd(NULL, 0);
    // 얻어온 현재 작업 디렉토리를 출력합니다.
    printf("cwd2 = %s\n", cwd);
    // 동적으로 할당된 메모리를 해제합니다.
    free(cwd);

    // 현재 작업 디렉토리를 wd2 배열에 저장하고, 저장에 실패할 경우 오류 메시지를 출력합니다.
    if(getcwd(wd2, 10) == NULL) {
        perror("getcwd");
        exit(1);
    }
}
