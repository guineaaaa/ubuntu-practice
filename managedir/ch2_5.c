#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	if(rename("bit","wow")==-1){
		perror("rename");
		exit(1);
	}
}
