#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// dup()는 새로운 파일 기술자를 자동으로 할당한다. 이와 달리 dup2() 함수는
// 새로운 파일 기술자를 지정할 수 있게 해준다.
// dup2() 함수는 파일 기술자 oldfd를 newfd로 복샇나다.

int main(){
	int fd;

	fd=open("tmp.bbb", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	if(fd==-1){
		perror("Create tmp.bbb");
		exit(1);
	}
	
	// dup2() 함수를 사용해 기존 파일 기술자 (fd)를 1번 파일 기술자로 복사한다.
	// 이제 1번 파일 기술자로 출력하면 더이상 출력(화면)이 아닌 fd가 가리키는 파일로 출력된다.
	dup2(fd,1);

	printf("DUF2: Standard Output Redirection\n");

	close(fd);
}
