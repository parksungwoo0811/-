```c
#include <sys/utsname.h> // 시스템 정보를 저장하는 구조체와 관련된 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdlib.h> // 표준 라이브러리 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    struct utsname uts; // struct utsname 구조체 변수를 선언합니다.

    // uname 함수를 사용하여 시스템 정보를 가져옵니다.
    if (uname(&uts) == -1) {
        // uname 함수 호출이 실패한 경우 perror 함수로 에러 메시지를 출력하고 프로그램을 종료합니다.
        perror("uname");
        exit(1);
    }

    // 시스템 정보를 출력합니다.
    printf("OSname : %s\n", uts.sysname); // 운영 체제 이름을 출력합니다.
    printf("Nodename : %s\n", uts.nodename); // 호스트의 네트워크 이름을 출력합니다.
    printf("Release : %s\n", uts.release); // 운영 체제의 릴리스 레벨을 출력합니다.
    printf("Version : %s\n", uts.version); // 운영 체제의 버전을 출력합니다.
    printf("Machine : %s\n", uts.machine); // 시스템의 하드웨어 플랫폼을 출력합니다.

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 uname 함수를 사용하여 시스템 정보를 가져와서 출력하는 예제입니다. uname 함수는 struct utsname 타입의 구조체를 인자로 받아 시스템 정보를 구조체에 저장합니다. 저장된 정보를 printf 함수를 사용하여 출력합니다.