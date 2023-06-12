#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void searchFiles(const char *dirPath, const char *fileName) {
    DIR *dir = opendir(dirPath);
    if (!dir) {
        printf("Failed to open directory: %s\n", dirPath);
        return;
    }
    
    struct dirent *entry;
    struct stat fileStat;
    char path[1024];
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        snprintf(path, sizeof(path), "%s/%s", dirPath, entry->d_name);
        stat(path, &fileStat);
        
        if (S_ISDIR(fileStat.st_mode)) {
            searchFiles(path, fileName);  // 재귀적으로 디렉토리 탐색
        } else {
            if (strcmp(entry->d_name, fileName) == 0) {
                printf("File found: %s\n", path);
            }
        }
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./find <directory_path> <file_name>\n");
        return 1;
    }
    
    const char *dirPath = argv[1];
    const char *fileName = argv[2];
    
    searchFiles(dirPath, fileName);
    
    return 0;
}

