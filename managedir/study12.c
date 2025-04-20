// '.'와 '..'를 제외하고 디렉토리에 있는 파일이나 하위 디렉토리명을 출력하는 myls 프로그램을 만들기
#include <stdio.h>
#include <dirent.h>
#include <string.h>
int main(){
	struct dirent* entry;
	DIR* dp=opendir(".");

	if(!dp){
		perror("opendir");
		return 1;
	}

	// 디렉토리의 내용 읽기
	while((entry=readdir(dp))!=NULL){
		if(strcmp(entry->d_name,".")&&strcmp(entry->d_name,"..")){
			printf("%s\n", entry->d_name);
		}
	}

	closedir(dp);
	return 0;
}
