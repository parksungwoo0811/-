#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char *argv[3]; // 실행할 프로그램에 전달할 인수들을 담는 배열입니다.
    char *envp[2]; // 실행할 프로그램에 전달할 환경 변수들을 담는 배열입니다.

    printf("Before exec function\n"); // exec 함수 호출 전에 실행됩니다.

    argv[0] = "arg.out"; // 실행할 프로그램의 이름입니다.
    argv[1] = "100";     // 첫 번째 인수입니다.
    argv[2] = NULL;      // exec 함수에 전달될 인수 배열은 NULL로 종료되어야 합니다.

    envp[0] = "MYENV=hanbit"; // 전달할 환경 변수입니다.
    envp[1] = NULL;           // exec 함수에 전달될 환경 변수 배열은 NULL로 종료되어야 합니다.

    // 새로운 프로세스를 실행하고, arg.out 프로그램을 실행합니다.
    if (execve("./arg.out", argv, envp) == -1) {
        perror("execve"); // execve 함수가 실패하면 오류 메시지를 출력합니다.
        exit(1);          // 프로그램을 종료합니다.
    }

    // exec 함수 호출 후에는 이 코드가 실행되지 않습니다.
    printf("After exec function\n");
}
