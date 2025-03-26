#include <stdio.h>

int main() {
    // 폴더 이름 변경: "1.pipe" -> "piping_command"
    if (rename("1.pipe", "piping_command") == 0) {
        printf("폴더 이름이 성공적으로 변경되었습니다.\n");
    } else {
        perror("폴더 이름 변경 실패");
    }
    return 0;
}

