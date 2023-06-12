#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

// 파일 정보를 저장하기 위한 구조체
struct FileInfo {
    char name[512];        // 파일 이름
    time_t modified_time;  // 수정된 시간
};

// 비교 함수: 수정된 시간을 기준으로 내림차순으로 정렬
int compare(const void *a, const void *b) {
    struct FileInfo *fileA = (struct FileInfo *)a;
    struct FileInfo *fileB = (struct FileInfo *)b;
    return difftime(fileB->modified_time, fileA->modified_time);
}

/*
   ls_t 함수는 현재 디렉토리의 파일과 디렉토리 목록을 수정된 시간에 따라 정렬하여 출력합니다.
*/
void ls_t() {
    struct dirent *entry;
    DIR *dir = opendir("."); // 현재 디렉토리 열기

    if (dir == NULL) {
        perror("opendir() 에러"); // 디렉토리를 열 수 없는 경우 오류 메시지 출력
        return;
    }

    struct FileInfo files[MAX_ENTRIES]; // 파일 정보를 저장하기 위한 배열
    int count = 0;                      // 파일 수

    // 디렉토리 내의 각 항목에 대해 반복
    while ((entry = readdir(dir)) != NULL && count < MAX_ENTRIES) {
        // 파일의 상세 정보 가져오기
        char filename[512]; // 충분한 크기의 버퍼를 설정
        snprintf(filename, sizeof(filename), "./%s", entry->d_name);

        struct stat file_stat;
        if (stat(filename, &file_stat) < 0) {
            perror("stat() 에러"); // 파일의 속성 정보를 가져오지 못한 경우 오류 메시지 출력
            continue;
        }

        // 파일 정보 저장
        strcpy(files[count].name, entry->d_name);
        files[count].modified_time = file_stat.st_mtime;

        count++;
    }

    closedir(dir); // 디렉토리 닫기

    // 수정된 시간에 따라 파일 목록 정렬
    qsort(files, count, sizeof(struct FileInfo), compare);

    // 정렬된 파일 목록 출력
    for (int i = 0; i < count; i++) {
        printf("%s\n", files[i].name);
    }
}

int main() {
    ls_t();
    return 0;
}

