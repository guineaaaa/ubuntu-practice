#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	int fd; //파일 디스크립터를 저장하는 변수
	struct stat statbuf; //파일 정보를 저장하는 구조체 변수

	// open()을 통해 "linux.txt"를 읽기 전용으로 열기
	// 성공하면 fd에 파일 디스크립터가 저장됨
	fd=open("linux.txt", O_RDONLY);

	if(fd==-1){
		perror("open: linux.txt");
		exit(1);
	}


	// fstat()는 파일 디스크립터 (fd)를 통해 파일의 정보를 가져옴
	// statbuf 구조체에 해당 파일의 상태를 저장
	fstat(fd, &statbuf);

	printf("INode=%d\n", (int)statbuf.st_ino);
	printf("UID=%d\n", (int)statbuf.st_uid);

	close(fd);
}
