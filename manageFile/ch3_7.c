#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(){
	struct stat statbuf;
	
	// 기존 권한에 관계 없이 linux.txt 파일의 권한을 변경한다.
	// 소유자는 읽기, 쓰기, 실행 권한, 그룹은 읽기, 실행권한, 기타 사용자는 읽기 권한으로 변경한다
	chmod("linux.txt", S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH);

	// stat() 함수로 파일의 정보를 읽고 st_mode 값을 출력한다
	stat("linux.txt", &statbuf);
	printf("1. Mode=%o\n", (unsigned int)statbuf.st_mode);

	// st_mode의 현재 값에 그룹의 쓰기 권한을 추가하고 기타 사용자의 읽기 권한을 제거하도록 설정한다
	statbuf.st_mode |=S_IWGRP;
	statbuf.st_mode &=~(S_IROTH);

	// 앞서 설정한 값으로 chmod() 함수를 실행한다
	chmod("linux.txt", statbuf.st_mode);

	// linux.txt 파일의 접근 권한이 변경되었음을 알 수있다.
	stat("linux.txt", &statbuf);
	printf("2. Mode=%o\n", (unsigned int) statbuf.st_mode);
}
