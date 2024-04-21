```c
#include <sys/types.h> // 데이터 타입 정의를 포함하는 헤더 파일을 포함합니다.
#include <fcntl.h> // 파일 제어에 사용되는 매크로와 함수를 정의하는 헤더 파일을 포함합니다.
#include <unistd.h> // POSIX 운영 체제 API를 정의하는 헤더 파일을 포함합니다.
#include <stdlib.h> // 표준 라이브러리 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    int fd, flags; // 파일 디스크립터와 플래그를 저장할 변수를 선언합니다.

    // "linux.txt" 파일을 읽고 쓰기 모드로 엽니다.
    fd = open("linux.txt", O_RDWR);
    if (fd == -1) {
        // 파일 열기에 실패한 경우 perror 함수로 에러 메시지를 출력하고 프로그램을 종료합니다.
        perror("open");
        exit(1);
    }

    // 파일의 플래그를 가져와서 현재 상태를 확인합니다.
    if ((flags = fcntl(fd, F_GETFL)) == -1) {
        // fcntl 함수를 사용하여 파일의 플래그를 가져오는데 실패한 경우 에러 메시지를 출력하고 프로그램을 종료합니다.
        perror("fcntl");
        exit(1);
    }

    // O_APPEND 플래그를 추가하여 파일에 데이터를 추가할 때마다 파일의 끝에 이어쓰기를 수행합니다.
    flags |= O_APPEND;

    // 파일의 플래그를 변경합니다.
    if (fcntl(fd, F_SETFL, flags) == -1) {
        // fcntl 함수를 사용하여 파일의 플래그를 변경하는데 실패한 경우 에러 메시지를 출력하고 프로그램을 종료합니다.
        perror("fcntl");
        exit(1);
    }

    // 파일에 데이터를 씁니다.
    if (write(fd, "Hanbit Academy\n", 15) != 15) perror("write");

    // 파일을 닫습니다.
    close(fd);
}
```

이 코드는 "linux.txt" 파일을 읽고 쓰기 모드로 열어서 O_APPEND 플래그를 추가하여 파일의 끝에 이어쓰기를 수행합니다. 파일을 열거나 플래그를 변경하는 과정에서 오류가 발생하면 perror 함수로 에러 메시지를 출력하고 프로그램을 종료합니다.