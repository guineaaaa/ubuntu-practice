#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	int fd;
	mode_t mode;

	mode=S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH;

	// test.txt 파일을 12행에서 지정한 권한으로 생성
	fd=open("test.txt", O_CREAT, mode);

	if(fd==-1){
		perror("creat");
		exit(1);
	}
	close(fd);
}
