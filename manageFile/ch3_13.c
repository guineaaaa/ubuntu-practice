#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	struct stat statbuf;

	// stat() 함수로 linux.ln 파일의 정보를 검색해 링크 개수를 출력
	stat("linux.ln", &statbuf);
	printf("1. linux.ln: Link Count=%d\n", (int)statbuf.st_nlink);

	// unlink() 함수를 사용해 하드 링크 파일인 linux.ln의 링크를 끊어서 삭제한다.
	unlink("linux.ln");

	// stat() 함수로 원본 파일인 linux.txt 파일의 정보를 검색해 링크를 끊어 삭제한다.
	stat("linux.txt", &statbuf);
	printf("2. linux.txt: Link Count=%d\n", (int)statbuf.st_nlink);

	// unlink() 함수를 사용해 심벌릭 링크 파일인 linux.sym의 링크를 끊어 삭제한다.
	unlink("linux.sym");

}
