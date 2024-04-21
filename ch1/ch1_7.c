#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int n;
    extern char *optarg; // getopt 함수에서 옵션 인수의 값을 저장하는 변수
    extern int optind; // getopt 함수가 처리한 다음 인수의 위치

    printf("Current Optind : %d\n", optind); // 현재 optind 값 출력
    // getopt 함수를 사용하여 명령줄 옵션을 처리합니다.
    while ((n = getopt(argc, argv, "abc:")) != -1) {
        switch (n) {
            case 'a':
                printf("Option : a\n"); // -a 옵션이 입력되면 출력
                break;
            case 'b':
                printf("Option : b\n"); // -b 옵션이 입력되면 출력
                break;
            case 'c':
                printf("Option : c, Argument=%s\n", optarg); // -c 옵션의 값과 함께 출력
                break;
        }
        printf("Next Optind : %d\n", optind); // 다음 optind 값 출력
    }
}
