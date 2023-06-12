#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent *entry;
    DIR *dir = opendir("."); // 현재 디렉토리 열기

    if (dir == NULL) {
        perror("opendir() error");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) { // 디렉토리 내의 각 항목에 대해 반복
        printf("%s\n", entry->d_name); // 파일 또는 디렉토리 이름 출력
    }

    closedir(dir); // 디렉토리 닫기
    return 0;
}

