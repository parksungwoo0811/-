#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void help();
void version();

int main(int argc, char **argv)
{ 
    int opt;
    int port_num;
    int fp;
    int opt_ok;
    char file_name[16];
    char buf[256];

    // 명령줄 옵션을 처리합니다.
    while((opt = getopt(argc, argv, "hvf:")) != -1) 
    {
        switch(opt) 
        { 
            case 'h':
                help(); // 도움말 출력 함수를 호출합니다.
                break; 
            case 'v':
                version(); // 버전 출력 함수를 호출합니다.
                break;
            case 'f':
                // -f 옵션을 통해 전달된 파일 이름을 복사합니다.
                memcpy(file_name, optarg, 16);
                opt_ok = 1;
                break;
        }
    } 

    // -f 옵션이 제대로 전달되지 않았을 경우 도움말을 출력하고 프로그램을 종료합니다.
    if (opt_ok != 1)
    { 
        help();
        exit(0);
    } 

    // 파일이 존재하지 않을 경우 오류를 출력하고 프로그램을 종료합니다.
    if (access(file_name, R_OK) != 0)
    {
        printf("파일이 존재하지 않습니다\n");
        exit(0);
    }

    // 파일을 읽기 모드로 엽니다.
    if((fp = open(file_name, O_RDONLY)) == -1)
    {
        printf("file open error\n");
        exit(0);
    }

    // 파일 내용을 읽어서 출력합니다.
    memset(buf, '\0', 256);
    while(read(fp, buf, 256) > 0)
    {
        printf("%s", buf);
        memset(buf, '\0', 256);
    }
}

// 도움말을 출력하는 함수입니다.
void help()
{
    printf("Usage: ./testopt [OPTION] [FILE]\n"
           "  -h                도움말\n"
           "  -f [FILE]         파일출력\n"
           "  -v                버전출력\n");
    exit(0);
}

// 버전 정보를 출력하는 함수입니다.
void version()
{
    printf("Version : 1.01\n");
    exit(0);
}
