#include <stdio.h>
#include <stdlib.h>

void head(const char *filename, int num_lines) {
    FILE *file = fopen(filename, "r"); // 파일 열기

    if (file == NULL) {
        perror("파일 열기 오류"); // 파일을 열 수 없는 경우 오류 메시지 출력
        return;
    }

    char line[256];
    int count = 0;

    // 파일에서 한 줄씩 읽어서 출력
    while (fgets(line, sizeof(line), file) && count < num_lines) {
        printf("%s", line);
        count++;
    }

    fclose(file); // 파일 닫기
}

int main() {
    char filename[256]; // 파일 경로를 저장할 변수
    int num_lines; // 출력할 줄의 개수를 저장할 변수

    printf("파일 경로를 입력하세요: ");
    scanf("%s", filename);

    printf("출력할 줄의 개수를 입력하세요: ");
    scanf("%d", &num_lines);

    head(filename, num_lines); // head 함수 호출

    return 0;
}

