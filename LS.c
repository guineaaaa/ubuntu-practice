#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

void list_dir(const char *path, int detailed, int recursive) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    char fullpath[1024];

    if ((dp = opendir(path)) == NULL) {
        perror("opendir error");
        return;
    }

    printf("\n%s:\n", path);
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') continue; // 숨김 파일 제외

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        stat(fullpath, &statbuf);

        if (detailed) // -l 옵션: inode 번호와 파일 크기 출력
            printf("Inode: %-10lu %-20s %ld bytes\n", statbuf.st_ino, entry->d_name, statbuf.st_size);
        else
            printf("%s  ", entry->d_name);
    }
    printf("\n");

    if (recursive) { // -r 옵션
        rewinddir(dp);
        while ((entry = readdir(dp)) != NULL) {
            if (entry->d_name[0] == '.') continue;

            snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
            stat(fullpath, &statbuf);

            if (S_ISDIR(statbuf.st_mode)) {
                list_dir(fullpath, detailed, recursive);
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    int detailed = 0, recursive = 0;
    char *path = ".";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0)
            detailed = 1;
        else if (strcmp(argv[i], "-r") == 0)
            recursive = 1;
        else
            path = argv[i];
    }

    list_dir(path, detailed, recursive);
    return 0;
}

