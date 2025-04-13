#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE *rfp, *wfp;
	int c;

	if((rfp=fopen("linux.txt","r"))==NULL){
		perror("fopen: linux.txt");
		exit(1);
	}

	if((wfp=fopen("linux.out", "w"))==NULL){
		perror("fopen: linux.out");
		exit(1);
	}
	
	// fgetc()를 이용해서 EOF를 만날때까지 한 문자씩 읽어들인다
	// 읽은 문자를 fputc()를 사용해서 파일에 기록한다.
	while((c=fgetc(rfp))!=EOF){
		fputc(c, wfp);
	}

	// 모든 작업을 완료하면 열려있는 두 파일을 파일 포인터를 사용해 닫는다.
	// linux.txt, linux.out 파일의 내용이 같음을 알 수 있다.
	fclose(rfp);
	fclose(wfp);
}
