```c
#include <grp.h> // 그룹 관련 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    struct group *grp; // 그룹 정보를 담는 구조체 포인터를 선언합니다.
    int n; // 반복문을 위한 변수를 선언합니다.

    for (n = 0; n < 3; n++) { // 그룹 정보를 최대 3번 읽어옵니다.
        grp = getgrent(); // 그룹 정보를 읽어옵니다.
        if (grp == NULL) // 그룹 정보가 없는 경우 반복문을 종료합니다.
            break;
        printf("GroupName: %s, GID: %d ", grp->gr_name, (int)grp->gr_gid); // 그룹 이름과 그룹 ID를 출력합니다.

        int m = 0; // 그룹 멤버 인덱스를 나타내는 변수를 선언하고 초기화합니다.
        printf("Members : "); // 멤버 목록을 출력하기 위해 준비합니다.
        while (grp->gr_mem[m] != NULL) // 그룹 멤버가 NULL이 아닌 동안 반복합니다.
            printf("%s ", grp->gr_mem[m++]); // 그룹 멤버를 출력하고 인덱스를 증가시킵니다.
        printf("\n"); // 그룹 멤버 출력이 끝나면 줄을 바꿉니다.
    }

    endgrent(); // 그룹 정보 파일을 닫습니다.

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 시스템의 그룹 정보 파일에서 그룹 정보를 읽어와서 그룹 이름, 그룹 ID, 그룹 멤버를 출력하는 예제입니다. utmp 파일은 현재 시스템에서 로그인한 사용자의 정보를 포함하고 있습니다.