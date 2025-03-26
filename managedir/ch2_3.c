#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	char* cwd; // 시스템이 할당하는 버퍼의 주소를 저장하기 위한 포인터변수
	char wd1[BUFSIZ]; // 경로를 저장하기 위한 배열, 8KB크기의 배열
	char wd2[10]; // 경로를 저장하기 위한 10바이트 크기 배열
	
	getcwd(wd1, BUFSIZ); // wd1 배열에 현재 경로를 저장하고 출력
	printf("wd1=%s\n", wd1);

	// cwd 포인터에 BUFSIZ 만큼 메모리를 할당하고 이 메모리 경로 저장
	cwd=getcwd(NULL, BUFSIZ);
	printf("cwd1=%s\n", cwd);
	free(cwd);

	// getcwd() 함수의 인자로 NULL과 0을 저장
	// 이 경우 시스템이 자동으로 경로에 필요한 메모리를 할당하고 주소를 리턴
	cwd=getcwd(NULL, 0);
	printf("cwd2=%s\n", cwd);
	free(cwd);

	if(getcwd(wd2,10)==NULL){
		perror("getcwd");
		exit(1);
	}
}
