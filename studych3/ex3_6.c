#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
	struct stat statbuf;

	stat("linux.txt", &statbuf);

	// 명령행 인자로 전달받은 파일의 크기
	printf("Size=%d\n", (int)statbuf.st_size);
}
