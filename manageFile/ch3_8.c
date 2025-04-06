#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	struct stat statbuf;
	
	// 하드 링크를 생성하기 이전의 링크 개수를 확인
	stat("linux.txt", &statbuf);
	printf("Before Link Count=%d\n", (int)statbuf.st_nlink);

	// 리눅스 파일의 하드 링크로 linux.ln을 생성
	link("linux.txt", "linux.ln");

	// 하드 링크를 생성한 이후의 링크 개수를 확인한다.
	stat("linux.txt", &statbuf);
	// linux.ln 파일이 생성되었고, 링크 개수가 변경되었다.
	// linux.txt와 linux.ln의 inode가 동일함을 확인 가능하다.
	printf("After Link Count=%d\n", (int)statbuf.st_nlink);
}

