#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(){
	struct stat statbuf;
	int kind;

	stat("linux.txt", &statbuf);

	printf("Mode=%o\n", (unsigned int)statbuf.st_mode);

	kind=statbuf.st_mode & S_IFMT;

	switch(kind){
		case S_IFLNK:
			printf("linux.txt: Symbolic link");
			break;
		case S_IFDIR:
			printf("linux.txt: Directory");
			break;
		case S_IFREG:
			printf("linux.txt: Regular File");
			break;
	}
}
