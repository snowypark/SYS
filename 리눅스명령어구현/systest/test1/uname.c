#include <stdio.h>
#include <sys/utsname.h>

int main() {
    struct utsname system_info;

    if (uname(&system_info) == -1) {
        perror("uname");
        return 1;
    }

    printf("System Name: %s\n", system_info.sysname);
    printf("Node Name: %s\n", system_info.nodename);
    printf("Release: %s\n", system_info.release);
    printf("Version: %s\n", system_info.version);
    printf("Machine: %s\n", system_info.machine);

    return 0;
}

