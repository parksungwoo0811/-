#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main() {
    // "test.txt" 파일의 읽기 권한을 확인하는 코드
    if(access("test.txt", R_OK) == -1) {
        // access 함수가 -1을 반환하면 파일의 읽기 권한이 없음을 의미하므로 오류 메시지 출력
        perror("test.txt");
        // 프로그램을 비정상적으로 종료
        exit(1);
    }

    return 0; // 정상적으로 종료
}
