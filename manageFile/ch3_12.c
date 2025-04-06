#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(){
	char buf[BUFSIZ];
	
	// realpath() 함수를 통해 linux.sym의 원본 파일 경로를 얻고 출력
	realpath("linux.sym", buf);
	printf("linux.sym: REALPATH=%s\n", buf);
}
