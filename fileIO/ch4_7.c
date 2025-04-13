#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	int fd, fd1;

	// tmp.aaa 파일을 생성한다.
	fd=open("tmp.aaa", O_CREAT|O_WRONLY|O_TRUNC, 0644);

	if(fd==-1){
		perror("Create tmp.aaa");
		exit(1);
	}

	// 파일 기술자 1번을 닫는다. 1번은 표준 출력이다. 즉, 화면으로 출력되는것을 닫음
	close(1);

	// dup(fd)를 실행하면 파일 기술자 fd가 가리키는 파일에 새로운 파일 기술자가 지정된다.
	// 위 행에서 1번을 닫았기 때문에 현재 가장 작은 값은 1이고, 이 값이 새로운 기술자로 부여된다.
	fd1=dup(fd);

	// printf문으로 출력하면 현재 1번 파일 기술자라 가리키는 파일인 tmp.aaa로 출력된다.
	printf("DUF FD=%d\n", fd1);
	printf("Standard output redirection\n");

	// 실행 결과: 위에서 출력한 내용이 tmp.aaa파일에 저장되었다.
	// close(1)로 1번 파일 디스크립터를 닫았고 이제 가장 작은 사용한 디스크립터 번호는 1이 된다.
	// 그리고 dup(fd)를 호출하면, fd가 가리키는 파일을 가장 작은 비어있는 파일 디스크립터에 복사. 지금 1번이 비어있으니 dup(fd)는 1번을 새로 할당.
	// 즉, 이제 1번 파일 디스크립터는 tmp.aaa를 가리키게 된다.
	// printf()는 내부적으로 write(1, ...) 시스템 콜을 호출할 때 1번 파일 디스크립터가 tmp.aaa를 가리키고 있으니 파일로 출력되는 것이다.
	// 1. printf()는 stdout->1번 파일 디스크립터로 출력
	// 2. dup(fd)로 1번 tmp.aaa 복제했으니
	// 3. printf()의 출력이 터미널 대신 tmp.aaa 파일로 저장됨	
	close(fd);
}
