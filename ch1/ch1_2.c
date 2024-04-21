
이 코드는 "test.txt" 파일을 읽기 모드로 열고, 파일이 존재하지 않을 때 발생하는 오류 코드를 출력하는 예제입니다.
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

extern int errno; // 외부에서 정의된 errno 변수를 사용하기 위해 extern 선언

int main() {
    FILE *fp; // 파일 포인터 선언

    // "test.txt" 파일을 읽기 모드로 열고 파일 포인터를 반환하며, 열기에 실패한 경우 NULL을 반환
    if((fp=fopen("test.txt", "r")) == NULL) {
        // 파일 열기에 실패한 경우 errno 변수에 저장된 오류 코드를 출력
        printf("errno=%d\n", errno);
        // 프로그램을 비정상적으로 종료
        exit(1);
    }
    // 파일을 닫음
    fclose(fp);
}
