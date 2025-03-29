#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	char *cwd;
	int fd;

	// 현재 디렉토리의 경로를 getcwd()로 읽어들인다.
	cwd=getcwd(NULL, BUFSIZ);
	printf("1. current directory: %s\n", cwd);

	// open() 함수로 bit 디렉토리를 연다
	fd=open("bit", O_RDONLY);
	
	// fchdir()를 통해서 디렉토리로 이동한다.
	// open()함수가 리턴한 파일 디스크립터를 인자로 지정한다
	fchdir(fd);

	cwd=getcwd(NULL, BUFSIZ);
	printf("2. current directory: %s\n", cwd);

	close(fd);
	free(cwd);

	// 디렉토리가 이동되었으나 pwd로 확인해보면 프로그램 내부에서만 변경되었음을 알 수 있다.
}


