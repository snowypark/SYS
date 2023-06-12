#include <stdio.h>
#include <unistd.h>

int rm(const char *path) {
    if (unlink(path) == 0) { // unlink 함수를 사용하여 파일 삭제
        return 0; // 성공적으로 파일을 삭제한 경우 0을 반환
    } else {
        perror("rm() 에러"); // unlink 함수가 실패한 경우 오류 메시지 출력
        return -1; // 파일 삭제 실패 시 -1을 반환
    }
}

int main() {
    const char *filename = "aa.txt"; // 삭제할 파일의 경로 및 이름

    if (rm(filename) == 0) {
        printf("파일이 성공적으로 삭제되었습니다.\n");
    } else {
        printf("파일 삭제에 실패하였습니다.\n");
    }

    return 0;
}

