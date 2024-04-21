```c
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdlib.h> // 표준 라이브러리 함수를 정의하는 헤더 파일을 포함합니다.
#include <string.h> // 문자열 관련 함수를 사용하기 위한 헤더 파일을 포함합니다.

int main() {
    char *fname; // 파일 이름을 저장할 포인터를 선언합니다.
    char fntmp[BUFSIZ]; // 임시 파일 이름을 저장할 문자열 배열을 선언합니다.
    char template[32]; // 임시 파일 템플릿을 저장할 문자열 배열을 선언합니다.

    // tmpnam 함수를 사용하여 임시 파일 이름을 생성하고, 생성된 이름을 fname에 저장합니다.
    fname = tmpnam(NULL);
    printf("1. TMP File Name(tmpnam) : %s\n", fname);

    // tmpnam 함수를 사용하여 임시 파일 이름을 생성하고, 생성된 이름을 fntmp에 저장합니다.
    tmpnam(fntmp);
    printf("2. TMP File Name(tmpnam) : %s\n", fntmp);

    // 임시 파일 템플릿을 설정합니다.
    strcpy(template, "/tmp/hanbitXXXXXX");
    // mktemp 함수를 사용하여 임시 파일 이름을 생성하고, 생성된 이름을 fname에 저장합니다.
    fname = mktemp(template);
    printf("3. TMP File Name(mktemp) : %s\n", fname);
}
```

이 코드는 다양한 방법으로 임시 파일 이름을 생성하고 출력하는 예제입니다. 먼저 tmpnam 함수를 사용하여 임시 파일 이름을 생성하고 출력합니다. tmpnam 함수는 생성된 임시 파일 이름을 문자열로 반환하며, 반환된 이름을 바로 출력합니다. 또한 tmpnam 함수를 사용하여 생성된 임시 파일 이름을 fntmp 배열에 저장하고 출력합니다. 마지막으로 mktemp 함수를 사용하여 임시 파일 템플릿을 이용하여 임시 파일 이름을 생성하고 출력합니다. 생성된 임시 파일 이름은 template 배열에 저장됩니다.