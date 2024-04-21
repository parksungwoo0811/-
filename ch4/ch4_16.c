```c
#include <stdlib.h> // 표준 라이브러리 함수를 정의하는 헤더 파일을 포함합니다.
#include <stdio.h> // 표준 입출력 함수를 정의하는 헤더 파일을 포함합니다.

int main() {
    FILE *rfp, *wfp; // 읽기용 파일 포인터와 쓰기용 파일 포인터를 선언합니다.
    int id, s1, s2, s3, s4, n; // 학번과 점수들을 저장할 변수들을 선언합니다.

    // 읽기용 파일을 엽니다.
    if ((rfp = fopen("linux.dat", "r")) == NULL) {
        // 파일 열기에 실패한 경우 perror 함수로 에러 메시지를 출력하고 프로그램을 종료합니다.
        perror("fopen: linux.dat");
        exit(1);
    }

    // 쓰기용 파일을 엽니다.
    if ((wfp = fopen("linux.scr", "w")) == NULL) {
        // 파일 열기에 실패한 경우 perror 함수로 에러 메시지를 출력하고 프로그램을 종료합니다.
        perror("fopen: linux.scr");
        exit(1);
    }

    // 쓰기용 파일에 헤더를 출력합니다.
    fprintf(wfp, "학번 평균\n");

    // 파일로부터 학생 정보를 읽어와서 평균을 계산하고 쓰기용 파일에 출력합니다.
    while ((n = fscanf(rfp, "%d %d %d %d %d", &id, &s1, &s2, &s3, &s4)) != EOF) {
        fprintf(wfp, "%d : %d\n", id, (s1 + s2 + s3 + s4) / 4);
    }

    // 파일을 닫습니다.
    fclose(rfp);
    fclose(wfp);
}
```

이 코드는 "linux.dat" 파일로부터 학번과 네 과목의 점수를 읽어와 평균을 계산하여 "linux.scr" 파일에 학번과 평균을 출력하는 프로그램입니다. 입력 파일과 출력 파일이 열리는 과정에서 파일 열기에 실패한 경우 perror 함수로 에러 메시지를 출력하고 프로그램을 종료합니다. 이후 fscanf 함수로 파일로부터 학생 정보를 읽어옵니다. 읽어온 정보로 평균을 계산하고 쓰기용 파일에 학번과 평균을 출력합니다. 마지막으로 파일을 닫습니다.