#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE *rfp;
	char buf[BUFSIZ];
	int n;

	if((rfp=fopen("linux.txt", "r"))==NULL){
		perror("fopen: linux.txt");
		exit(1);
	}

	// 항목의 크기를 sizeof(char)의 2배로 하고 한번에 읽어올 개수를 4로 지정한다.
	// char의 크기는 1이므로 실제로는 8바이트(2*4)씩 읽어온다.
	// 문자열로 출력하기 위해 끝에 널문자 추가한다.
	// 실행 결과: 한번에 8바이트씩 끊어서 읽어온다. 리턴값을 지정한 n의 출력값을 보면 한번에 4개 항목을 읽었음을 알 수 있다.
	while((n=fread(buf,sizeof(char)*2,4,rfp))>0){
		buf[8]='\0';
		printf("n=%d, buf=%s\n",n,buf);
	}

	fclose(rfp);
}
