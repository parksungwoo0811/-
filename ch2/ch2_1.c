#include <sys/stat.h> // 시스템 헤더 파일인 sys/stat.h를 포함합니다. mkdir 함수를 사용하기 위해 필요합니다.
#include <stdlib.h> // 표준 라이브러리 헤더 파일인 stdlib.h를 포함합니다. exit 함수를 사용하기 위해 필요합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. perror 함수를 사용하기 위해 필요합니다.

int main() {
    if (mkdir("han", 0755) == -1) { // "han" 디렉토리를 생성합니다. 0755는 소유자에게는 모든 권한을, 그룹과 기타 사용자에게는 읽고 실행할 수 있는 권한만을 부여합니다.
        perror("han"); // 오류가 발생한 경우, 오류 메시지를 출력합니다.
        exit(1); // 비정상적으로 종료합니다.
    }
}
