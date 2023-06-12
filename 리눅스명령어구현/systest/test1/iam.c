#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // getuid 함수를 사용하기 위한 헤더 파일
#include <sys/types.h>
#include <pwd.h>

int main() {
    uid_t user_id = getuid();  // 현재 사용자의 ID를 가져옵니다.
    struct passwd *pw = getpwuid(user_id);  // 사용자 ID에 해당하는 사용자 정보를 가져옵니다.

    if (pw == NULL) {
        printf("Failed to get username.\n");
        return 1;
    }

    printf("Username: %s\n", pw->pw_name);  // 사용자 이름을 출력합니다.

    return 0;
}

