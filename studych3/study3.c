#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){

	char filename[100];

	printf("접근 권한을 조작하고 싶은 파일을 입력하세요:");
	scanf("%s",filename);

	struct stat statbuf;

	stat(filename, &statbuf);

	printf("mode=%o\n",(unsigned int)statbuf.st_mode);

	// 사용자 모든 권한, 그룹과 기타에게 읽기 권한 주기
	chmod(filename, S_IRWXU| S_IROTH| S_IRGRP);

	printf("After chmod=%o\n", (unsigned int)statbuf.st_mode);

	// 사용자 쓰기 권한 제거하기
	statbuf.st_mode&=~(S_IWUSR);

	// 앞서 설정한 값으로 chmod()함수를 실행해야한다.
	chmod(filename, statbuf.st_mode);

	printf("User can't write files!=%o\n", (unsigned int)statbuf.st_mode);

	return 0;
}
