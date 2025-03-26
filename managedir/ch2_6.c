#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	char *cwd;
	
	cwd=getcwd(NULL, BUFSIZ);
	printf("1. currentDirectory:%s\n", cwd);

	chdir("bit");

	cwd=getcwd(NULL, BUFSIZ);

	printf("2. currentDirectory:%s\n", cwd);

	free(cwd);
}
	
	
