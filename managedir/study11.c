// 디렉토리명을 명령형 인자로 입력받아 생성하고 작업디렉토리를 새로 생성한 디렉토리로 이동시키는 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
	
	if(mkdir(argv[1],0755)==-1){
		perror("디렉토리 생성 실패");
		return 1;
	}


	char* cwd=getcwd(NULL, 1024);
	printf("현재 디렉토리: %s", cwd);

	if(chdir(argv[1])==-1){
		perror("디렉토리 이동 실패");
		return 1;
	}

	cwd=getcwd(NULL, 1024);
	printf("이동된 디렉토리:%s", cwd);


	free(cwd);

	return 0;
}
