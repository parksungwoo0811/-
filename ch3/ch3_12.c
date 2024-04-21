```c
#include <sys/stat.h> // 파일의 상태 정보를 다루는 헤더 파일인 sys/stat.h를 포함합니다.
#include <stdlib.h> // 표준 라이브러리 헤더 파일인 stdlib.h를 포함합니다. realpath 함수를 사용하기 위해 필요합니다.
#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다. printf 함수를 사용하기 위해 필요합니다.

int main() {
    char buf[BUFSIZ]; // 경로를 저장할 버퍼를 선언합니다.

    // "linux.sym" 파일의 절대 경로를 얻어와서 buf 배열에 저장합니다.
    realpath("linux.sym", buf);
    // "linux.sym" 파일의 절대 경로를 출력합니다.
    printf("linux.sym : REALPATH = %s\n", buf);
}
```

이 코드는 "linux.sym" 파일의 절대 경로를 얻어와서 출력합니다. realpath 함수를 사용하여 상대 경로를 절대 경로로 변환할 수 있습니다.