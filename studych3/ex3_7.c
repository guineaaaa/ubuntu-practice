#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	// 명령행 인자로 전달받은 파일의 종류
	struct stat statbuf;

	stat("linux.txt", &statbuf);

	printf("파일의 종류=%o\n",(unsigned int) statbuf.st_mode);
}
