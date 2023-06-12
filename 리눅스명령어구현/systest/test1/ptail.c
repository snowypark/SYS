#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tail(const char *filename, int num_lines) {
    FILE *file = fopen(filename, "r"); // 파일 열기

    if (file == NULL) {
        perror("파일 열기 오류"); // 파일을 열 수 없는 경우 오류 메시지 출력
        return;
    }

    char **lines = (char **)malloc(num_lines * sizeof(char *)); // 출력할 줄을 저장할 문자열 배열
    if (lines == NULL) {
        perror("메모리 할당 오류"); // 메모리 할당에 실패한 경우 오류 메시지 출력
        fclose(file);
        return;
    }

    char line[256]; // 한 줄을 저장할 문자열 변수
    int count = 0; // 읽은 줄의 개수

    // 초기화
    for (int i = 0; i < num_lines; i++) {
        lines[i] = NULL;
    }

    // 파일의 모든 줄을 읽어서 lines 배열에 저장
    while (fgets(line, sizeof(line), file)) {
        if (lines[count % num_lines] != NULL) {
            free(lines[count % num_lines]); // 이전에 저장된 줄 메모리 해제
        }

        lines[count % num_lines] = malloc((strlen(line) + 1) * sizeof(char)); // 현재 줄 저장을 위해 메모리 할당
        strcpy(lines[count % num_lines], line); // 현재 줄 복사

        count++;
    }

    // 파일의 끝에서부터 num_lines 개수만큼의 줄을 출력
    for (int i = 0; i < num_lines; i++) {
        int index = (count - num_lines + i) % num_lines;
        if (lines[index] != NULL) {
            printf("%s", lines[index]);
        }
    }

    // 동적으로 할당한 메모리 해제
    for (int i = 0; i < num_lines; i++) {
        if (lines[i] != NULL) {
            free(lines[i]);
        }
    }
    free(lines);

    fclose(file); // 파일 닫기
}

int main() {
    char filename[256]; // 파일 경로를 저장할 변수
    int num_lines; // 출력할 줄의 개수를 저장할 변수

    printf("파일 경로를 입력하세요: ");
    scanf("%s", filename); // 사용자로부터 파일 경로 입력받기

    printf("출력할 줄의 개수를 입력하세요: ");
    scanf("%d", &num_lines); // 사용자로부터 출력할 줄의 개수 입력받기

    tail(filename, num_lines); // tail 함수 호출하여 파일의 뒷부분 출력

    return 0;
}

