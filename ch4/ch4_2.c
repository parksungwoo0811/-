```c
#include <sys/types.h> // 시스템 호출에 사용되는 데이터 타입을 정의하는 헤더 파일을 포함합니다.
#include <sys/stat.h> // 파일 상태 정보를 조사하는 함수를 정의하는 헤더 파일을 포함합니다.
#include <fcntl.h> // 파일 제어에 사용되는 매크로를 정의하는 헤더 파일을 포함합니다.
#include <unistd.h> // POSIX 운영 체제 API를 정의하는 헤더 파일을 포함합니다.
#include <stdlib.h> // 표준 라이브러리 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    int fd; // 파일 디스크립터를 저장할 변수를 선언합니다.

    // "test.txt" 파일을 생성하고 O_EXCL 플래그를 사용하여 이미 존재하는 파일인 경우 실패합니다.
    fd = open("test.txt", O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        // 파일 열기에 실패한 경우 perror 함수로 에러 메시지를 출력하고 프로그램을 종료합니다.
        perror("Excl");
        exit(1);
    }

    // 파일 디스크립터를 출력합니다.
    printf("test.txt: fd = %d\n", fd);

    // 파일 디스크립터를 닫습니다.
    close(fd);
}
```

이 코드는 "test.txt" 파일을 생성하고 O_EXCL 플래그를 사용하여 이미 존재하는 파일인 경우에는 열지 않고 실패하는 예제입니다. 파일을 열거나 실패하는 과정에서 오류가 발생하면 perror 함수로 에러 메시지를 출력하고 프로그램을 종료합니다.