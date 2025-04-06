#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

extern int errno;

int main(){
	int perm;
	
	// access() 함수의 mode에 F_OK를 저장해 linux.bak이 존재하는지 확인한다.
	// errno 변수에 저장된 메세지가 ENOENT이면 파일이 없다는 여부 이다
	if(access("linux.bak", F_OK)==-1 && errno==ENOENT)
		printf("linux.bak: File not exist\n");

	// R_OK로 읽기 권한 여부를 확인한다
	perm=access("linux.txt", R_OK);

	// 읽기 권한 검색 결과가 0이면 읽기 권한이 있다는 의미
	if(perm==0)
		printf("linux.txt: Read permission is permitted\n");
	// 읽기 권한 검색 결과가 -1이고 errnoㅇ 저장된 오류 메세지가 EACCES이면 접근 권한이 없다는 의미
	else if(perm==-1 && errno==EACCES)
		printf("linux.txt: Read permission is not permitted\n");

	// linux.bak은 없는 파일이니까 오류 메세지가 출력되고
	// linux.txt 파일에 대한 읽기 권한은 있다는 메세지가 출력될 것이다
}
