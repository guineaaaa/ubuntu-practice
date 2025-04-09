#include <stdio.h>
#include <sys/stat.h> //파일의 상태 정보를 위한 헤더 stat(), fstat(), lstat(), struct stat 구조체, S_IFREG, S_IFDIR 같은 파일 종류 및 권한 매크로
#include <sys/types.h> // mode_t, off_t, pid_t, uid_t 같은 특수 타입
#include <unistd.h> // 유닉스, 리눅스 시스템 호출 함수들
		    // access(), read(), write(), getpid(), chdir()
int main(){
	struct stat statbuf;

	const char *filename="linux.txt";

		
	// 파일명, inode번호, 파일 종류, 접근 권한, UID
	
	if(stat(filename, &statbuf)==-1){
		perror("stat");
		return 1;
	}

	printf("파일명:%s\n",filename);
	printf("inode:%d\n",(int)statbuf.st_ino);
	printf("파일종류:%o\n", statbuf.st_mode);
	// 하위 9비트 마스킹
	printf("접근권한:%o\n", statbuf.st_mode & 0777);

	printf("UID:%d\n", statbuf.st_uid);
	return 0;
}
