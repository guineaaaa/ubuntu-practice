#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	struct stat statbuf;
	int kind;

	stat("linux.txt", &statbuf);

	printf("Mode=%o\n", (unsigned int)statbuf.st_mode);

	if(S_ISLNK(statbuf.st_mode))
		printf("linux.txt: Symbolic link\n");
	if(S_ISDIR(statbuf.st_mode))
		printf("linux.txt: Directory\n");
	if(S_ISREG(statbuf.st_mode))
		printf("linux.txt: Regular file\n");
	if(S_ISBLK(statbuf.st_mode))
		printf("linux.txt: 블록 장치 특수 파일\n");
	if(S_ISCHR(statbuf.st_mode))
		printf("linux.txt: 문자 장치 특수 파일\n");
	
}
