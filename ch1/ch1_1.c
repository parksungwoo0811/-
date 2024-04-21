#include <stdio.h>
#include <unistd.h>
#include <errno.h>

이 코드는 "test.txt" 파일의 존재 여부를 확인하고, 파일이 존재하지 않을 때 발생하는 오류 코드를 출력합니다.




extern int errno; // errno를 외부에서 선언하여 사용

int main() {
    // "test.txt" 파일의 존재 여부를 확인하는 코드
    if(access("test.txt", F_OK) == -1) {
        printf("errno=%d\n", errno); // 파일이 존재하지 않을 때 발생하는 오류 코드 출력
    }

    return 0; // 프로그램 종료
}
