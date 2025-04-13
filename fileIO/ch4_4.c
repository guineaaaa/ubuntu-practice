#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int fd, n;
	char buf[10];

	// linux.txt를 읽기 전용으로 연다.
	fd=open("linux.txt", O_RDONLY);

	if(fd==-1){
		perror("Open");
		exit(1);
	}

	// 5바이트를 읽어 buf에 저장하고, read() 함수의 리턴값을 저장한다.
	n=read(fd, buf, 5);

	if(n==-1){
		perror("Read");
		exit(1);
	}

	// read() 함수는 읽어온 데이터의 끝에 자동으로 널을 추가하지 않기 때문에 buf에 널 문자를 추가한다.
	// buf를 문자열로 출력하려면 끝에 null을 추가해야 한다.
	buf[n]='\0';

	// linux.txt 파일에서 읽어온 바이트 수와 buf의 내용을 출력한다. (실행 파일을 보면 linux.txt 파일의 처음 5바이트를 읽어왔음을 알 수 있다
	printf("n=%d, buf=%s\n", n, buf);

	close(fd);
}
