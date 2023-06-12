#include <stdio.h>
#include <utime.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [file1] [file2] ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        const char *filename = argv[i];

        struct stat st;
        if (stat(filename, &st) != 0) {
            // 파일이 존재하지 않으면 빈 파일 생성
            FILE *file = fopen(filename, "w");
            if (file == NULL) {
                perror("Failed to create file");
                continue;
            }
            fclose(file);
        }

        struct utimbuf new_times;
        new_times.actime = st.st_atime;  // 접근 시간은 변경하지 않음
        new_times.modtime = time(NULL);  // 현재 시간으로 수정 시간 변경

        if (utime(filename, &new_times) != 0) {
            perror("Failed to modify file timestamp");
            continue;
        }

        printf("Modified timestamp of '%s'.\n", filename);
    }

    return 0;
}

