#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE *rfp,*wfp;
	char buf[BUFSIZ];
	int n;

	if((rfp=fopen("linux.txt", "r"))==NULL){
		perror("fopen: linux.txt");
		exit(1);
	}

	if((wfp=fopen("linux.out", "a"))==NULL){
		perror("fopen: linux.out");
		exit(1);
	}
	

	// 항목의 크기를 sizeof(char)의 2배로 하고 한번에 읽어올 개수를 4로 지정한다
	// char의 크기는 1이므로 실제로는 2*4=8바이트씩 읽는다.
	while((n=fread(buf, sizeof(char)*2, 4, rfp))>0){
		// 항목의 크기가 sizeof(char)*2인 항목을 fread()가 리턴한 항목 수인 n만큼씩
		// wfp가 가리키는 파일에 출력한다. fwrite()는 출력할 때 별도로 개행문자를 추가하지 않는다.
		fwrite(buf, sizeof(char)*2, n, wfp);
	}

	fclose(rfp);
	fclose(wfp);
}

