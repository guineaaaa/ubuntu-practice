#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	struct stat statbuf;

	// 기존 linux.tx 파일의 정보를 stat()으로 검색해 링크 개수와 inode 번호 출력
	printf("1. stat: linux.txt ---\n");
	stat("linux.txt", &statbuf);

	printf("linux.txt: Link Count=%d\n", (int)statbuf.st_nlink);
	printf("linux.txt: Inode=%d\n", (int)statbuf.st_ino);

	// stat() 함수를 사용해 심벌릭 링크 파일인 linux.sym의 정보를 검색하고 링크 개수와 inode 번호 출력
	printf("2. stat: linux.sym ---\n");
	stat("linux.sym", &statbuf);
	
	printf("linux.sym: Link Count=%d\n", (int)statbuf.st_nlink);
	printf("linux.sym: Inode=%d\n", (int)statbuf.st_ino);

	// lstat() 함수를 사용해 심벌릭 링크 파일인 linux.sym의 정보를 검색하고 링크 개수와 inode번호 출력
	printf("3. lstat: linux.sym ---\n");
	lstat("linux.sym", &statbuf);
	printf("linux.sym: Link Count=%d\n", (int)statbuf.st_nlink);
	printf("linux.sym: Inode=%d\n", (int)statbuf.st_ino);

	// 심벌릭 링크의 정보를 stat()으로 검색하면 원본 파일의 정보가 검색됨을 알 수 있다.
	// lstat() 함수로 검색한 심벌릭 링크의 정보는 링크 파일 자체에 대한 정보로 다른 값이 출력되었음
	// lstat()은 심벌릭 링크 자체의 파일 정보
	// 심벌릭 링크를 stat()으로 검색하면 원본에 대한 정보

}
