#include <stdlib.h>
#include <stdio.h>

// 파일 오프셋 이동: fseek()
// 현재 오프셋 구하기: ftell()
// 처음 위치로 오프셋 이동: rewind()
int main(){
	FILE *fp;
	int n;
	long cur;
	char buf[BUFSIZ];

	if((fp=fopen("linux.txt", "r"))==NULL){
		perror("fopen: linux.txt");
		exit(1);
	}

	cur=ftell(fp);
	printf("Offset cur=%d\n", (int)cur);

	n=fread(buf, sizeof(char),5,fp);
	buf[n]='\0';
	printf("---- Read str=%s\n",buf);

	// 현재 오프셋을 기준으로 1만큼 이동한다.
	// 현재 오프셋이 5였는데, 밑의 코드를 실행한 결과 오프셋이 6으로 이동한다.
	fseek(fp,1, SEEK_CUR);

	cur=ftell(fp);
	printf("Offset cur=%d\n", (int)cur);

	n=fread(buf,sizeof(char),6,fp);
	buf[n]='\0';
	printf("-- Read str=%s\n",buf);

	fseek(fp,1,SEEK_CUR);

	cur=ftell(fp);
	printf("Offset cur=%d\n", (int)cur);

	n=fread(buf, sizeof(char), 11,fp);
	buf[n]='\0';


	printf("--- Read str=%s\n", buf);

	rewind(fp);

	cur=ftell(fp);
	printf("Rewind Offset cur=%d\n", (int)cur);

	fclose(fp);
}
