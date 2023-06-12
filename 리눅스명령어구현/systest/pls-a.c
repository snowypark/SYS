#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

/*
   ls_a 함수는 현재 디렉토리의 파일과 디렉토리의 목록을 출력합니다.
   숨김 파일 및 디렉토리도 포함합니다.
*/
void ls_a() {
    struct dirent *entry;
    DIR *dir = opendir("."); // 현재 디렉토리 열기

    if (dir == NULL) {
        perror("opendir() error"); // 디렉토리를 열 수 없는 경우 오류 메시지 출력
        return;
    }

    while ((entry = readdir(dir)) != NULL) { // 디렉토리 내의 각 항목에 대해 반복
        printf("%s\n", entry->d_name); // 파일 또는 디렉토리 이름 출력
    }

    closedir(dir); // 디렉토리 닫기
}

int main() {
    ls_a();
    return 0;
}

