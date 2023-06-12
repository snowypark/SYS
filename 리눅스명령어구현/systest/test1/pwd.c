#include <stdio.h>
#include <unistd.h>

void pwd() {
    char path[1024]; // 디렉토리 경로를 저장할 버퍼

    // getcwd() 함수를 사용하여 현재 작업 중인 디렉토리 경로 가져오기
    if (getcwd(path, sizeof(path)) != NULL) {
        printf("%s\n", path); // 경로 출력
    } else {
        perror("getcwd() 에러"); // getcwd() 함수가 실패한 경우 오류 메시지 출력
    }
}

int main() {
    pwd(); // pwd() 함수 호출하여 현재 작업 중인 디렉토리 경로 출력
    return 0;
}

