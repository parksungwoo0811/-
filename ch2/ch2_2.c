#include <unistd.h> // UNIX 표준 헤더 파일인 unistd.h를 포함합니다. rmdir 함수를 사용하기 위해 필요합니다.
#include <stdlib.h> // 표준 라이브러리 헤더 파일인 stdlib.h를 포함합니다. exit 함수를 사용하기 위해 필요합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. perror 함수를 사용하기 위해 필요합니다.

int main() {
    if (rmdir("han") == -1) { // "han" 디렉토리를 삭제합니다.
        perror("han"); // 오류가 발생한 경우, 오류 메시지를 출력합니다.
        exit(1); // 비정상적으로 종료합니다.
    }
}
