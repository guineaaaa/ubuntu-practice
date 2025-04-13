#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	int fd, n;
	off_t start, cur;
	char buf[256];

	// 텍스트 파일을 읽기 전용으로 열기 
	fd=open("linux.txt", O_RDONLY);
	if(fd==-1){
		perror("Open linux.txt");
		exit(1);
	}

	// 파일의 현재 오프셋 위치를 파악해보면 0임을 알 수 있다. 
	start=lseek(fd,0,SEEK_CUR);

	// 파일을 읽고 마지막에 널값을 넣어 출력한다. 출력 값은=> '읽은 글자 수+널 문자 개수' 
	n=read(fd,buf,255);

	buf[n]='\0';
	printf("Offset start=%d, n=%d, Read str=%s", (int)start, n, buf);

	// 파일의 시작을 기준으로 오프셋이 6인 위치로 이동한 후 데이터를 읽고 널값을 채워 출력한다
	cur=lseek(fd, 6, SEEK_SET);
	n=read(fd, buf, 255);
	buf[n]='\0';

	printf("Offset start=%d, n=%d, Read str=%s", (int)start, n, buf);

	// 실행 결과-> 오프셋의 위치에 따라서 읽어온데이터가 다름을 알 수 있다.
	close(fd);
}
