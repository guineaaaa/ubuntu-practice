#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(){
	char arr[256];

	// 상수를 이용해 파일 검색하기
	// 매크로를 이용해 파일 검색하기
	
	printf("종류를 검색하고 싶은 파일명을 작성하세요: ");
	scanf("%s", arr);

	struct stat statbuf;

	stat(arr, &statbuf);

	int kind=statbuf.st_mode & S_IFMT;

	switch(kind){
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFREG:
			printf("regular file\n");
			break;
	}

	// 매크로를 통해 검색하기
	if(S_ISREG(statbuf.st_mode))
		printf("regular file (mecro)\n");

	return 0;
}
