#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	int fd;

	// 0번 파일 기술자를 닫는다.
	close(0);

	// 남아 있는 파일 기술자 중 가장 작은 숫자가 0이기 때문에 test.txt 파일을 열고 할당되는 파일 기술자는 실행 결과와 같아야 한다.
	fd=open("test.txt", O_RDWR);
	if(fd==-1){
		perror("Open");
		exit(1);
	}

	printf("test.txt: fd=%d\n", fd);
	close(fd);
}

