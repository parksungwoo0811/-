#include <sys/types.h> // pid_t 타입을 사용하기 위한 헤더 파일
#include <unistd.h> // fork 함수를 사용하기 위한 헤더 파일
#include <stdlib.h> // exit 함수를 사용하기 위한 헤더 파일
#include <stdio.h> // 표준 입출력 함수를 사용하기 위한 헤더 파일

int main() {
    pid_t pid; // 프로세스 ID를 저장할 변수

    switch (pid = fork()) { // fork 함수를 사용하여 자식 프로세스를 생성
        case -1 : // fork 실패 시
            perror("fork"); // 에러 메시지 출력
            exit(1); // 프로그램 종료
            break;
        case 0 : // 자식 프로세스인 경우
            printf("Child Process - My PID:%d, My Parent's PID:%d\n", 
               (int)getpid(), (int)getppid()); // 자식 프로세스의 PID와 부모 프로세스의 PID 출력
            break; 
        default : // 부모 프로세스인 경우
            printf("Parent process - My PID:%d, My Parent's PID:%d, My Child's PID:%d\n", (int)getpid(), (int)getppid(), (int)pid); // 부모 프로세스의 PID, 부모 프로세스의 부모의 PID, 자식 프로세스의 PID 출력
            break;
    }

    printf("End of fork\n"); // "End of fork" 출력
}
위의 코드는 fork 함수를 사용하여 부모 프로세스와 자식 프로세스를 생성하는 예제입니다. 부모 프로세스는 자식 프로세스의 PID를 얻을 수 있고, 자식 프로세스는 부모 프로세스의 PID와 부모 프로세스의 부모의 PID를 얻을 수 있습니다