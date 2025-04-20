#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* argv[]){
	if(argc!=2){
		fprintf(stderr,"사용법:%s [파일명]\n", argv[0]);
		return 1;
	}

	DIR* dp=opendir(".");
	struct dirent* entry;

	int is_found=0;

	while((entry=readdir(dp))!=NULL){
		if(!strcmp(argv[1], entry->d_name)){
			is_found=1;
			break;
		}
	}

	if(is_found){
		printf("%s가 있습니다\n", argv[1]);
	}else{
		printf("%s가 없습니다\n", argv[1]);
	}

	closedir(dp);
	return 0;
}
