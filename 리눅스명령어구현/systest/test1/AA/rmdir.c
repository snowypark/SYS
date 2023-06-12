#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char directory[256];

    printf("Enter the directory to remove: ");
    scanf("%s", directory);

    if (rmdir(directory) == 0) {
        printf("Directory '%s' removed successfully.\n", directory);
        return 0;
    } else {
        perror("Failed to remove directory");
        return 1;
    }
}

