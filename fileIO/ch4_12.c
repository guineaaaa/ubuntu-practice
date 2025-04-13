#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE *rfp,*wfp;

	char buf[BUFSIZ];

	if((rfp=fopen("linux.txt", "r"))==NULL){
		perror("fopen: linux.txt");
		exit(1);
	}

	if((wfp=fopen("linux.out", "a"))==NULL){
		perror("fopen: linux.out");
		exit(1);
	}

	// fgets()를 통해서 리턴값이 NULL이 될 때 까지 한 행씩 buf로 읽어온다.
	// fgest() 함수의 리턴값이 NULL이 되는 경우는 파일이 비어있거나 파일의 끝을 만났을 때다.
	while(fgets(buf, BUFSIZ, rfp)!=NULL){
		fputs(buf, wfp);
	}

	fclose(rfp);
	fclose(wfp);
}

