#include <stdio.h>
#include <string.h>

int main(){
	char arr[256][256];

	printf("gogo\n");

	int i;
	for(i=0;i<256;i++){
		fgets(arr[i], sizeof(arr[i]), stdin);

		if(arr[i][0]=='\n'){
			break;
		}
	}

	for(int j=0;j<i;j++){
		printf("%s\n", arr[j]);
	}
	
	return 0;
}

	
