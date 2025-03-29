#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct stat statbuf;

    // 파일이 존재하는지 확인
    if (stat("linux.txt", &statbuf) == -1) {
        perror("stat error");
        return 1;
    }

    printf("Inode=%d\n", (int)statbuf.st_ino);
    printf("Mode=%o\n", (unsigned int)statbuf.st_mode);
    printf("Nlink=%o\n", (unsigned int)statbuf.st_nlink);
    printf("UID=%d\n", (int)statbuf.st_uid);
    printf("GID=%d\n", (int)statbuf.st_gid);
    printf("SIZE=%d\n", (int)statbuf.st_size);
    printf("Blksize=%d\n", (int)statbuf.st_blksize);
    printf("Blocks=%d\n", (int)statbuf.st_blocks);

    return 0;
}
	
