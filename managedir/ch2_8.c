#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(){
	
	DIR *dp;
	struct dirent *dent;

	// 현재 디렉토리를 연다
	dp=opendir(".");

	while((dent=readdir(dp))){
		printf("Name:%s", dent->d_name);
		printf("d_type:%d", dent->d_type);
		printf("Inode:%d\n", (int)dent->d_ino);
	}

	closedir(dp);
}
