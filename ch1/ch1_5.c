#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

extern int errno; // 외부에서 정의된 errno 변수를 사용하기 위해 extern 선언

int main() {
    char *err; // 문자열을 저장할 포인터 변수 err 선언

    // "test.txt" 파일의 읽기 권한을 확인하는 코드
    if(access("test.txt", R_OK) == -1) {
        // access 함수가 -1을 반환하면 파일의 읽기 권한이 없음을 의미하므로 오류 메시지 출력
        err = strerror(errno); // errno에 해당하는 오류 메시지를 문자열로 가져옴
        printf("오류: %s(test.txt)\n", err); // 오류 메시지 출력
        exit(1); // 프로그램을 비정상적으로 종료
    }

    return 0; // 정상적으로 종료
}
이 코드는 "test.txt" 파일의 읽기 권한을 확인하고, 권한이 없을 경우 해당 오류 메시지를 출력합니다.






