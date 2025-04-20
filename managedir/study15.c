// "입력받은 디렉토리 안"에 해당 "파일명" 이있는지 확인하는 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc!=3){
		fprintf(stderr, "사용법: %s [디렉토리경로] [파일명]\n",argv[0]);
		return 1;
	}

	const char* dir_path=argv[1];
	const char* file_name=argv[2];


	DIR* dp=opendir(dir_path);
	struct dirent *entry;
	if(dp==NULL){
		perror("디렉토리 열기실패");
		return 1;
	}

	int is_found=0;
	while((entry=readdir(dp))!=NULL){
		if(!strcmp(file_name,entry->d_name)){
			is_found=1;
			break;
		}
	}

	if(is_found){
		printf("%s안에 %s가 있네요.\n", dir_path, file_name);
	}else{
		printf("없어요..\n");
	}

	closedir(dp);
	return 0;
}
