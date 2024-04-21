#include <stdio.h> // 표준 입출력 헤더 파일인 stdio.h를 포함합니다.
#include <stdlib.h> // 표준 라이브러리 헤더 파일인 stdlib.h를 포함합니다.
#include <dirent.h> // 디렉토리 조작 관련 헤더 파일인 dirent.h를 포함합니다.

int main() {
    DIR *dp; // 디렉토리 포인터 변수를 선언합니다.
    struct dirent *dent; // dirent 구조체 포인터 변수를 선언합니다.
    long loc; // 위치 정보를 저장할 변수를 선언합니다.

    // 현재 디렉토리를 열고, 디렉토리 포인터 변수에 할당합니다.
    dp = opendir(".");

    // 디렉토리의 시작 위치를 출력합니다.
    printf("Start Position : %ld\n", telldir(dp));

    // 디렉토리 내의 모든 파일을 순회하면서 읽고, 현재 위치를 출력합니다.
    while ((dent = readdir(dp))) {
        printf("Read : %s -> ", dent->d_name); // 읽은 파일의 이름을 출력합니다.
        printf("Cur Position : %ld\n", telldir(dp)); // 현재 디렉토리의 위치를 출력합니다.
    }

    // 디렉토리 포인터를 처음으로 되감아서 위치를 출력합니다.
    printf("** Directory Position Rewind **\n");
    rewinddir(dp);
    printf("Cur Position : %ld\n", telldir(dp));

    // 디렉토리 포인터를 이동하고, 위치를 저장하고, 해당 위치로 이동한 후 위치를 출력합니다.
    printf("** Move Directory Pointer **\n");
    readdir(dp); // 다음 파일을 읽어 디렉토리 포인터를 이동합니다.
    loc = telldir(dp); // 현재 위치를 저장합니다.
    seekdir(dp, loc); // 저장한 위치로 이동합니다.
    printf("Cur Position : %ld\n", telldir(dp)); // 이동한 위치를 출력합니다.

    // 디렉토리 포인터에서 파일을 읽고, 읽은 파일의 이름을 출력합니다.
    dent = readdir(dp);
    printf("Read : %s \n", dent->d_name);

    // 디렉토리를 닫습니다.
    closedir(dp);
}
이 코드는 현재 디렉토리에서 파일을 읽고, 디렉토리 포인터를 제어하는 방법을 보여줍니다. 처음에는 디렉토리의 시작 위치를 출력하고, 파일을 하나씩 읽어가며 현재 위치를 출력합니다. 그 후 rewinddir 함수로 디렉토리 포인터를 되감고, seekdir 함수로 이동한 위치로 디렉토리 포인터를 이동하여 현재 위치를 출력합니다. 마지막으로 readdir 함수로 파일을 읽고 해당 파일의 이름을 출력합니다.