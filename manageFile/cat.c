#include <stdio.h>

int main(int argc, char *argv[]){
	char buf[100];
	int fd;

	if(argc<2){
		perror("인자의 개수가 모자릅니다");
		exit(1);
	}
	int len;
	len=1;
	else{
		while(len<argc){
		fd=open(argv[len]);

		while(read(fd,buf,100)>0){
			write(1,buf,100);
		}
		close(fd);
		len++;
		}
	}
}

