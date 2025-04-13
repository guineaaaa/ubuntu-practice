#include <stdlib.h>
#include <stdio.h>

int main(){
	int ret;

	// remove()를 통해서 tmp.bbb를 삭제한다
	ret=remove("tmp.bbb");

	if(ret==-1){
		perror("Remove tmp.bbb");
		exit(1);
	}

	printf("remove tmp.bbb success!!\n");
}
