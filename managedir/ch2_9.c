#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(){
	DIR *dp;
	struct dirent *dent;

	long loc;

	// 디렉토리 열기
	dp=opendir(".");

	// 디렉토리 스트림에서 현재 위치를 출력한다
	printf("Start position:%ld\n", telldir(dp));
	
	// 디렉토리의 내용을 차례대로 읽어 파일명과 디렉토리 스트림에서
	// 현재 위치를 출력한다.
	// 디렉토리 내용을 읽은 후에 위치를 출력하는 것이므로 다음에 읽을 위치를 출력한다.
	// readdir()는 디렉토리에서 파일을 하나씩 읽어 struct dirent 반환
	// d_name에는 파일명이 있고, telldir(dp)를 통해 다음 파일의 읽을 위치 출력
	while((dent=readdir(dp))){
		printf("Read: %s", dent->d_name);
		printf("Cur position:%ld\n", telldir(dp));
	}

	printf("Directory Position rewind\n");
	// 디렉토리의 위치를 처음으로 되돌리기
	rewinddir(dp);
	loc=telldir(dp);
	seekdir(dp, loc);

	printf("Cur position:%ld\n", telldir(dp));

	dent=readdir(dp);
	printf("Read:%s\n", dent->d_name);

	closedir(dp);
}


