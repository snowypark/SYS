#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void ls_i() {
    struct dirent *entry;
    DIR *dir = opendir("."); // 현재 디렉토리 열기

    if (dir == NULL) {
        perror("opendir() error");
        return;
    }

    while ((entry = readdir(dir)) != NULL) { // 디렉토리 내의 각 항목에 대해 반복
        char filename[512]; // 충분한 크기의 버퍼를 설정

        snprintf(filename, sizeof(filename), "./%s", entry->d_name);

        struct stat file_stat;
        if (stat(filename, &file_stat) < 0) {
            perror("stat() error");
            continue;
        }

        printf("%llu %s\n", (unsigned long long)file_stat.st_ino, entry->d_name);
    }

    closedir(dir); // 디렉토리 닫기
}

int main() {
    ls_i();
    return 0;
}

