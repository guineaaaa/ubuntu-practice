#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *dp = opendir(".");
    struct dirent *entry;
    int count = 0;
    long pos = -1;

    if (dp == NULL) {
        perror("디렉토리 열기 실패");
        return 1;
    }

    // 현재 디렉토리 전체 목록 출력
    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
            printf("%s\n", entry->d_name);
            count++;
            if (count == 3) {
                pos = telldir(dp); // 3번째 항목 "읽은 직후" 위치 저장
            }
        }
    }

    rewinddir(dp); // 스트림 처음으로 되돌림

    if (count >= 3) {
        seekdir(dp, pos);         // 저장한 위치로 점프
        entry = readdir(dp);      // 그 다음 항목 읽기
        if (entry != NULL) {
            printf("세 번째 항목 이후: %s\n", entry->d_name);
        } else {
            printf("seekdir 위치 이후 읽을 항목이 없음\n");
        }
    } else {
        printf("디렉토리 항목이 3개 미만이어서 seek 불가\n");
    }

    closedir(dp);
    return 0;
}

