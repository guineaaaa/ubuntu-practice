#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	char filename[256];
	struct stat statbuf;

	printf("파일명을 입력하세요: ");
	scanf("%255s", filename);

	if(stat(filename,&statbuf)==-1){
		perror("파일 정보 조회 실패");
		return 1;
	}

	// 파일명 UID 출려
	printf("%s %d", filename, statbuf.st_uid);

	// 접근 권한 출력 (rwx 형식)
	// 사용자 권한
	printf("%c", (statbuf.st_mode & S_IRUSR) ? 'r':'-');
	printf("%c", (statbuf.st_mode & S_IWUSR) ? 'w':'-');
	printf("%c", (statbuf.st_mode & S_IXUSR) ? 'x':'-');

	// 그룹 권한
	printf("%c", (statbuf.st_mode & S_IRGRP) ? 'r':'-');
	printf("%c", (statbuf.st_mode & S_IWUSR) ? 'w':'-');
	printf("%c", (statbuf.st_mode & S_IXUSR) ? 'x':'-');

	// Others 권한
	        printf("%c", (statbuf.st_mode & S_IROTH) ? 'r':'-');
        printf("%c", (statbuf.st_mode & S_IWOTH) ? 'w':'-');
        printf("%c", (statbuf.st_mode & S_IXOTH) ? 'x':'-');

	return 0;
}
