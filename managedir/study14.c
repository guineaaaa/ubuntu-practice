// 파일명을 명령행 인자로 입력받고 현재 디렉토리에 있는지 확인하는 프로그램

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	DIR *dp=opendir(".");
	struct dirent* entry;
	int is_dir=0;

	while((entry=readdir(dp))!=NULL){
		if(strcmp(argv[1],entry->d_name)){
			is_dir=1;
			break;
		}
	}
	
	if(is_dir){
		printf("%s가 있네요\n",argv[1]);
	}else{
		printf("없었다.\n");
	}

	closedir(dp);

	return 0;
}

