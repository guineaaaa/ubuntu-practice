#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	char *cwd;
	
	// 현재 디렉토리 경로를 getcwd로 가져온다
	cwd=getcwd(NULL, BUFSIZ);
	printf("1. Current directory: %s\n",cwd);

	// bit 디렉토리로 이동한다.
	chdir("bit");

	cwd=getcwd(NULL, BUFSIZ);
	printf("2. Current directory: %s\n", cwd);

	free(cwd);
	
}
