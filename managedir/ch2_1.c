#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	if(mkdir("my",0755)==-1){
		perror("my");
		exit(1);
	}
}
