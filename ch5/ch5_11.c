```c
#include <grp.h> // 그룹 관련 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    struct group *grp; // 그룹 정보를 담는 구조체 포인터를 선언합니다.
    int n; // 반복문을 위한 변수를 선언합니다.

    grp = getgrnam("adm"); // "adm" 그룹의 정보를 가져옵니다.
    if (grp == NULL) { // 그룹 정보가 없는 경우 에러 메시지를 출력하고 종료합니다.
        perror("getgrnam");
        return 1;
    }

    printf("Group Name : %s\n", grp->gr_name); // 그룹 이름을 출력합니다.
    printf("GID : %d\n", (int)grp->gr_gid); // 그룹 ID를 출력합니다.

    n = 0; // 그룹 멤버 인덱스를 나타내는 변수를 초기화합니다.
    printf("Members : ");
    while (grp->gr_mem[n] != NULL) // 그룹 멤버가 NULL이 아닌 동안 반복합니다.
        printf("%s ", grp->gr_mem[n++]); // 그룹 멤버를 출력하고 인덱스를 증가시킵니다.
    printf("\n"); // 그룹 멤버 출력이 끝나면 줄을 바꿉니다.

    return 0; // 프로그램을 종료합니다.
}
```

이 프로그램은 "adm" 그룹의 정보를 가져와서 그룹 이름, 그룹 ID 및 그룹 멤버를 출력하는 예제입니다. 만약 "adm" 그룹이 존재하지 않는다면 `getgrnam` 함수는 NULL을 반환합니다.