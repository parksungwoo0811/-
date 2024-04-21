#include <unistd.h>
#include <stdio.h>

int main() {
    // sysconf 함수를 사용하여 시스템의 설정값을 얻어옵니다.
    
    // _SC_ARG_MAX: 명령행 인자의 최대 길이를 확인합니다.
    printf("Arg Max : %ld\n", sysconf(_SC_ARG_MAX));
    
    // _SC_CLK_TCK: 초당 클록 틱 수를 확인합니다.
    printf("Clock Tick : %ld\n", sysconf(_SC_CLK_TCK));
    
    // _SC_OPEN_MAX: 프로세스가 동시에 열 수 있는 최대 파일 수를 확인합니다.
    printf("Max Open File : %ld\n", sysconf(_SC_OPEN_MAX));
    
    // _SC_LOGIN_NAME_MAX: 사용자 로그인 이름의 최대 길이를 확인합니다.
    printf("Max Login Name Length : %ld\n", sysconf(_SC_LOGIN_NAME_MAX));
}
