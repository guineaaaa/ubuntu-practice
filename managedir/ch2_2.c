#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	if(rmdir("my")==-1){
		perror("my");
		exit(1);
	}
}
