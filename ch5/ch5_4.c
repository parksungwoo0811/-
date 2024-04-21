#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    uid_t uid, euid;
    char *name;

    // 현재 사용자의 UID와 EUID를 가져와 출력
    uid = getuid();
    euid = geteuid();
    // 로그인 이름을 가져와 출력
    name = getlogin();

    printf("Login Name=%s, UID=%d, EUID=%d\n", name, (int)uid, (int)euid);
}
