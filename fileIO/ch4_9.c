#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

// 현재 열려있는 파일에 대한 파일 기술자의 속성을 확인하고 제어할 수 있다.
// fcntl()를 사용하면 파일을 열 때 설정한 플래그를 조정할 수 있다.
// fcntl()는 파일 기술자가 가리키는 팡리에 cmd로 지정한 명령을 수행한다.
// cmd의 종류에 따라 인자를 지정해야할 수도 있다.
// fcntl()함수의 두번째 인자인 명령은 fcntl.h 파일에 정의되어있으며 다음 두 가지를 많이 사용한다.
// F_GETFL: 상태 플래그 정보를 읽어온다
// F_SETFL: 상태 플래그 정보를 저장. 설정 가능한것들은 대부분 open()함수에서 지정하는 플래그이다.

int main(){
	int fd, flags;
	
	// 텍스트 파일을 읽기 쓰기용으로 열기	
	fd=open("linux.txt", O_RDWR);

	if(fd==-1){
		perror("open");
		exit(1);
	}

	// F_GETFL 명령을 실행해 fcntl()함수를 호출하면 현재 설정된 플래그 값이 리턴됨
	if((flags=fcntl(fd, F_GETFL))==-1){
		perror("fcntl");
		exit(1);
	}

	flags |=O_APPEND;

	// 저장된 플래그를 F_SETFL 명령으로 설정해 fcntl() 함수를 호출하면 기존 플래그가 새로운 플래그로 변경도니다
	if(fcntl(fd, F_SETFL, flags)==-1){
		perror("fcntl");
		exit(1);
	}

	// 파일 설정을 O_APPEND로 변경해서 파일에 출력하면 내용이 파일 끝부분에 추가된다.
	// 이는 실행 파일에서 확인 가능하다
	if(write(fd, "hanbit academpy\n", 15)!=15) perror("write");

	close(fd);
}
