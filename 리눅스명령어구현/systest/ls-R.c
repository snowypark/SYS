#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void ls_R(const char *dir_path, int depth) {
    DIR *dir = opendir(dir_path); // 디렉토리 열기

    if (dir == NULL) {
        perror("opendir() 에러"); // 디렉토리를 열 수 없는 경우 오류 메시지 출력
        return;
    }

    struct dirent *entry;
    struct stat file_stat;

    // 디렉토리 내의 각 항목에 대해 반복
    while ((entry = readdir(dir)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        // 현재 항목의 상태 가져오기
        if (stat(path, &file_stat) == -1) {
            perror("stat() 에러"); // 파일 상태를 가져올 수 없는 경우 오류 메시지 출력
            continue;
        }

        // 디렉토리인 경우 재귀적으로 호출하여 하위 디렉토리 탐색
        if (S_ISDIR(file_stat.st_mode)) {
            // .과 .. 디렉토리는 제외
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                printf("%*s%s/\n", depth * 2, "", entry->d_name);
                ls_R(path, depth + 1);
            }
        }
        // 파일인 경우 해당 파일 이름 출력
        else {
            printf("%*s%s\n", depth * 2, "", entry->d_name);
        }
    }

    closedir(dir); // 디렉토리 닫기
}

int main() {
    ls_R(".", 0); // 현재 디렉토리부터 시작하여 재귀적으로 디렉토리 탐색
    return 0;
}

