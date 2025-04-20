#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// 현재 디렉토리를 기억했다가
// 다른 디렉토리로 이동한 후
// 다시 원래 디렉토리로 돌아오는 프로그램

int main(){
	int original_fd;
	char* cwd;

	cwd=getcwd(NULL, 1024);

	if(cwd==NULL){
		perror("getcwd 실패");
		exit(1);
	}

	printf("현재 디렉토리:%s\n", cwd);

	// 현재 디렉토리 기억하기
	original_fd=open(".", O_RDONLY);

	// 디렉토리 이동
	if(chdir("fileIO")==-1){
		perror("디렉토리 이동 실패\n");
		exit(1);
	}

	cwd=getcwd(NULL, 1024);
	printf("이동된 디렉토리:%s\n", cwd);

	// 원래 디렉토리로 이동하기
	fchdir(original_fd);

	cwd=getcwd(NULL,1024);
	printf("원래 디렉토리:%s\n", cwd);

	return 0;
}
