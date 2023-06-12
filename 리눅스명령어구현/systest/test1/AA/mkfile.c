#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char file_path[256];
    int fd;

    printf("파일 경로를 입력하세요: ");
    scanf("%s", file_path);

    // 파일을 생성하고 쓰기 전용으로 엽니다
    fd = open(file_path, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        perror("파일 생성 실패");
        return 1;
    }

    // 파일을 닫습니다
    close(fd);

    printf("파일이 생성되었습니다.\n");
    return 0;
}

