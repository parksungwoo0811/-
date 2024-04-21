include <sys/stat.h> // 시스템 헤더 파일인 sys/stat.h를 포함합니다. rename 함수를 사용하기 위해 필요합니다.
#include <stdlib.h> // 표준 라이브러리 헤더 파일인 stdlib.h를 포함합니다. exit 함수를 사용하기 위해 필요합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. perror 함수를 사용하기 위해 필요합니다.

int main() {
    if (rename("han", "bit") == -1) { // "han" 디렉토리를 "bit"으로 이름을 변경합니다.
        perror("rename"); // 오류가 발생한 경우, 오류 메시지를 출력합니다.
        exit(1); // 비정상적으로 종료합니다.
    }
}
이 코드는 "han"이라는 디렉토리를 "bit"으로 이름을 변경하고, 변경에 실패할 경우 오류 메시지를 출력하여 프로그램을 종료합니다.