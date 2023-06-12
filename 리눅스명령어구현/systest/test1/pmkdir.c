#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    char dir_name[256];

    printf("디렉토리 이름을 입력하세요: ");
    scanf("%s", dir_name);

    int result = mkdir(dir_name, 0755);

    if (result == 0) {
        printf("디렉토리 생성 성공\n");
    } else {
        perror("mkdir() 에러");
    }

    return 0;
}

