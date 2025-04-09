#include <stdio.h>
#include <string.h>

int main(){
	char arr[256][256];
	int i=0;

	printf("문장들을 입력하세요. 공백 엔터를 입력 시 문장 입력이 끝난것으로 간주합니다.\n");

	for(i=0;i<256;i++){
		fgets(arr[i], sizeof(arr[i]), stdin);

		if(arr[i][0]=='\n'){
			break;
		}
	}

	printf("-- 당신이 입력한 문장들 --\n");
	for(int j=0;j<i;j++){ 
		// 줄 단위 출력
		printf("%s", arr[j]);
	}

	return 0;
}
