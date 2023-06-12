#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void ls_l() {
    struct dirent *entry;
    DIR *dir = opendir("."); // 현재 디렉토리 열기

    if (dir == NULL) {
        perror("opendir() 에러"); // 디렉토리를 열 수 없는 경우 오류 메시지 출력
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        struct stat file_stat;
        if (stat(entry->d_name, &file_stat) == -1) {
            perror("stat() 에러"); // 파일 상태를 가져올 수 없는 경우 오류 메시지 출력
            continue;
        }

        // 파일 타입 및 퍼미션 플래그 계산
        mode_t mode = file_stat.st_mode;
        char type = '-';
        if (S_ISDIR(mode)) type = 'd';
        else if (S_ISLNK(mode)) type = 'l';
        else if (S_ISFIFO(mode)) type = 'p';
        else if (S_ISSOCK(mode)) type = 's';
        else if (S_ISCHR(mode)) type = 'c';
        else if (S_ISBLK(mode)) type = 'b';

        // 퍼미션 플래그 문자열 계산
        char perms[10];
        perms[0] = (mode & S_IRUSR) ? 'r' : '-';
        perms[1] = (mode & S_IWUSR) ? 'w' : '-';
        perms[2] = (mode & S_IXUSR) ? 'x' : '-';
        perms[3] = (mode & S_IRGRP) ? 'r' : '-';
        perms[4] = (mode & S_IWGRP) ? 'w' : '-';
        perms[5] = (mode & S_IXGRP) ? 'x' : '-';
        perms[6] = (mode & S_IROTH) ? 'r' : '-';
        perms[7] = (mode & S_IWOTH) ? 'w' : '-';
        perms[8] = (mode & S_IXOTH) ? 'x' : '-';
        perms[9] = '\0';

        // 소유자, 그룹 및 파일 크기 계산
        struct passwd *owner = getpwuid(file_stat.st_uid);
        struct group *group = getgrgid(file_stat.st_gid);
        off_t size = file_stat.st_size;

        // 수정된 시간 포맷팅
        char modified_time[20];
        strftime(modified_time, sizeof(modified_time), "%Y-%m-%d %H:%M:%S", localtime(&(file_stat.st_mtime)));

        // 결과 출력
        printf("%c%s %2lu %-8s %-8s %8ld %s %s\n",
               type, perms, file_stat.st_nlink, owner->pw_name, group->gr_name, size, modified_time, entry->d_name);
    }

    closedir(dir); // 디렉토리 닫기
}

int main() {
    ls_l();
    return 0;
}

