#include <stdio.h>
#include <string.h>

int main(){
	// 사용자로부터 문자열을 입력받으면
	// 이를 2차원 배열에 저장하고 출력하는 프로그램
	// 예) hello \n, systemprogramming#include <stdio.h>

	char[256][256] arr;
	int i=0;

	printf("문자열을 입력하세요 (입력 끝은 빈줄 Enter):\n");

	for(i=0;i<256;i++){
		fgets(arr[i], sizeof(arr[i]), stdin);

		if(arr[i][0]=='\n'){
			break;
		}
	}

	printf("\n -- 입력한 문장들 -- \n");
	for(int j=0;j<i;j++){
		printf("%s", arr[j]);
		// fgets는 개행이 포함되어서 \n 안붙여도됨
	}

	return 0;
}
	
