#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void ls_F() {
    struct dirent *entry;
    DIR *dir = opendir("."); // 현재 디렉토리 열기

    if (dir == NULL) {
        perror("opendir() 에러"); // 디렉토리를 열 수 없는 경우 오류 메시지 출력
        return;
    }

    // 파일과 디렉토리를 구분하여 출력하는 루프
    while ((entry = readdir(dir)) != NULL) {
        struct stat file_stat;
        char *filename = entry->d_name;

        // 파일 정보 가져오기
        if (stat(filename, &file_stat) < 0) {
            perror("stat() 에러");
            continue;
        }

        // 파일 유형에 따라 표시 문자 추가
        if (S_ISDIR(file_stat.st_mode)) {
            printf("%s/\n", filename);
        } else if (file_stat.st_mode & S_IXUSR) {
            printf("%s*\n", filename);
        } else {
            printf("%s\n", filename);
        }
    }

    closedir(dir); // 디렉토리 닫기
}

int main() {
    ls_F();
    return 0;
}

