#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	char *cwd;
	// 이 함수를 통해서 경로를 검색한다.
	// 인자로는 아무것도 전달하지 않으며,
	// 시스템이 메모리를 자동으로 할당해 경로를 저장하고 리턴한다.
	cwd=get_current_dir_name();

	printf("cwd=%s\n", cwd);

	free(cwd);
}
