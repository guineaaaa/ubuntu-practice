#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

// 디렉토리가 비어있는지 확인하고 비어있다는 메세지를 출력하고 해당 디렉토리 삭제하는 프로그램
int main(){

	DIR* dp=opendir("emptydir");
	int empty_flag=1;
	struct dirent* entry;

	while((entry=readdir(dp))!=NULL){
		if(strcmp(entry->d_name,".")&&strcmp(entry->d_name,"..")){
			empty_flag=0;
			break;
		}
	}

	if(empty_flag){
		rmdir("emptydir");
		printf("디렉토리가 비어있습니다. 삭제하겠습니다");
	}else{
		printf("디렉토리 안에 뭔가있구요 그거못지우겠습니다\n");
	}
	
	closedir(dp);

	return 0;
}	
	
