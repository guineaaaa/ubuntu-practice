#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	char buf[BUFSIZ];
	int n;
	
	// linux.sym 파일의 내용을 readlink()로 읽어들여 buf에 저장
	n=readlink("linux.sym",buf, BUFSIZ);
	if(n==-1){
		perror("readlink");
		exit(1);
	}

	// buf 끝에 null을 추가하고 저장된 내용을 출력
	buf[n]='\0';
	printf("linux.sym: READLINK=%s\n", buf);

	// 심벌릭 링크를 ls -l 명령으로 확인 했을 때 '->' 뒤에 오는
	// 원본 파일의 경로가 심벌릭 링크의 데이터 블록에 저장된 내용이다.
	// 심벌릭 링크의 크기는 'linux.txt'의 바이트 수를 알 수 있다
}
