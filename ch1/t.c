#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr, *new;
    ptr = malloc(sizeof(char) * 100); // 메모리 할당

    // calloc 함수를 사용하려면 아래 주석을 해제하세요.
    /*
    ptr = calloc(10, 20); // 10개의 요소를 가진 배열을 20바이트씩 할당
    */

    new = realloc(ptr, 100); // 메모리 다시 할당

    printf("addr: %p\n", ptr); // 할당된 메모리의 주소 출력
}
