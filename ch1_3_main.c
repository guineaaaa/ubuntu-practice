
#include <stdio.h>

extern int addnum(int a, int b);

int main(){
	int sum;

	sum=addnum(1,5);
	printf("sum 1~5=%d\n", sum);
}
