#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    char file_path[256];
    mode_t new_permissions;

    printf("파일 경로를 입력하세요: ");
    scanf("%s", file_path);

    printf("새로운 권한을 8진수로 입력하세요: ");
    scanf("%o", &new_permissions);

    if (chmod(file_path, new_permissions) == 0) {
        printf("권한 변경에 성공했습니다.\n");
        return 0;
    } else {
        perror("권한 변경 실패");
        return 1;
    }
}

