#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(){
	// 디렉토리 열기
	DIR *dp=opendir(".");
	struct dirent *entry;

	int count=0; long pos=-1;

	if(dp==NULL){
		perror("디렉토리 열기 실패");
		return 1;
	}

	// 현재 디렉토리 전체 목록 출력
	while((entry=readdir(dp))!=NULL){
		if(strcmp(entry->d_name,".")&&strcmp(entry->d_name,"..")){
			printf("%s\n", entry->d_name);
			count++;

			if(count==3){
				pos=telldir(dp); //3번째 항목 다음위치지정
			}
		}
	}

	// 스트림을 처음으로 되돌림
	rewinddir(dp);

	if(count>=3){
		// 3번째 항목으로 위치 이동
		seekdir(dp, pos);
		entry=readdir(dp);
		if(entry!=NULL){
			printf("seekdir 위치 이후 읽을 항목이 없음\n");
		}
	}else{
		printf("디렉토리 항목이 3개 미만이여서 seek 불가\n");
	}

	closedir(dp);
	return 0;
}
