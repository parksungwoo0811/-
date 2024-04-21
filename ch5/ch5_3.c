#include <unistd.h>
#include <stdio.h>

int main() {
    // 현재 작업 디렉토리에 대한 경로 구성 변수들의 최대값을 출력하는 프로그램입니다.

    // _PC_LINK_MAX: 하나의 파일에 대한 하드 링크의 최대 수를 나타냅니다.
    printf("Link Max : %ld\n", pathconf(".", _PC_LINK_MAX));

    // _PC_NAME_MAX: 파일 이름의 최대 길이를 나타냅니다.
    printf("Name Max : %ld\n", pathconf(".", _PC_NAME_MAX));

    // _PC_PATH_MAX: 경로의 최대 길이를 나타냅니다.
    printf("Path Max : %ld\n", pathconf(".", _PC_PATH_MAX));
}
