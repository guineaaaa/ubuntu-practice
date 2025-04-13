#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	/**
	 * write() 함수는 read() 함수와 인자의 구조는 같지만 의미는 다르다.
	 * 파일 기술자는 쓰기를 수행할 파일을 가리키고, buf는 파일에 기록할 데이터를 저장하고 있는 메모리 영역을 가리킨다.
	 * buf가 가리키는 메모리 영역에서 count로 지정한 크기만큼 읽어 파일에 쓰기를 수행한다.
	 * write() 함수도 실제로 쓰기를 수행한 바이트 수를 리턴하며 오류가 발생하면 -1을 리턴한다.
	 * 파일을 읽어서 다른 파일에 쓰기를 수행해보기 위해선 파일 기술자가 2개 필요하다
	 */

	int rfd, wfd, n;
	char buf[10];


	// linux.txt 파일을 읽기 전용으로 열고, 파일 기술자를 rfd에 
	rfd=open("linux.txt", O_RDONLY);
	if(rfd==-1){
		perror("open linux.txt");
		exit(1);
	}

	// linux.bak을 쓰기 전용으로 생성하고, 기존 파일이 있으면 내용을 비운다.
	wfd=open("linux.bak", O_CREAT|O_WRONLY|O_TRUNC, 0644);
	if(wfd==-1){
		perror("open linux.bak");
		exit(1);
	}

	// while 문을 이용해 linux.txt 파일을 6바이트 씩 읽고 출력한다.
	// read()함수가 리턴한 값이 buf에 저장된 데이터의 크기이므로 write()의 세번재 인자로 사용할 수 있다.
	// 출력할 데이터의 크기인 n과 다르면 쓰기 동작에 문제가 있다는 으미ㅣ이므로 오류 메세지르르 
	while((n=read(rfd, buf, 6))>0){
		if(write(wfd,buf,n)!=n)perror("Write");
	}

	if(n==-1){
		perror("read");
	}

	close(rfd);
	close(wfd);
}
