#include <stdio.h>
#include <time.h>

void printCurrentDateTime() {
    time_t currentTime;
    struct tm *localTime;
    char dateTime[64];

    // 현재 시간 가져오기
    currentTime = time(NULL);
    // 현재 시간을 로컬 시간으로 변환
    localTime = localtime(&currentTime);
    // 날짜와 시간 포맷 지정
    strftime(dateTime, sizeof(dateTime), "%Y-%m-%d %H:%M:%S", localTime);

    // 현재 날짜와 시간 출력
    printf("Current Date and Time: %s\n", dateTime);
}

int main() {
    printCurrentDateTime(); // printCurrentDateTime 함수 호출하여 현재 날짜와 시간 출력

    return 0;
}

