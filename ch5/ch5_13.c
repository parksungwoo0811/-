```c
#include <sys/types.h> // 시스템 데이터 타입을 정의하는 헤더 파일을 포함합니다.
#include <utmp.h> // 유저 정보 관리 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    struct utmp *ut; // utmp 구조체 포인터를 선언합니다.

    printf("LoginName Line\n"); // 제목을 출력합니다.
    printf("---------------\n"); // 구분선을 출력합니다.

    setutent(); // 유저 정보 파일을 처음부터 읽도록 설정합니다.

    while ((ut = getutent()) != NULL) { // 유저 정보를 읽어오는 반복문을 실행합니다.
        if (ut->ut_type != USER_PROCESS) // 현재 사용자 프로세스가 아닌 경우 건너뜁니다.
            continue;
        printf("%s\t  %s\n", ut->ut_user, ut->ut_line); // 사용자 이름과 로그인 라인을 출력합니다.
    }

    endutent(); // 유저 정보 파일을 닫습니다.

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 시스템의 utmp 파일에서 로그인 중인 사용자의 정보를 읽어와서 사용자 이름과 로그인 라인을 출력하는 예제입니다. utmp 파일은 현재 시스템에서 로그인한 사용자의 정보를 포함하고 있습니다.