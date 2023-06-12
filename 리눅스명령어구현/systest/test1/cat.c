#include <stdio.h>
#include <stdlib.h>

void cat(const char *filename) {
    FILE *file = fopen(filename, "r"); // 파일 열기

    if (file == NULL) {
        perror("파일 열기 오류"); // 파일을 열 수 없는 경우 오류 메시지 출력
        return;
    }

    char ch;

    // 파일의 끝까지 문자를 읽어서 출력
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file); // 파일 닫기
}

int main() {
    char filename[256]; // 파일 경로를 저장할 변수

    printf("파일 경로를 입력하세요: ");
    scanf("%s", filename); // 사용자로부터 파일 경로 입력받기

    cat(filename); // cat 함수 호출하여 파일의 내용 출력

    return 0;
}

