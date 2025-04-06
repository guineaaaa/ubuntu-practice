#include <unistd.h>

int main(){
	// linux.txt 파일의 심벌릭 링크인 linux.sym을 생성한다.
	// linux.sym이 생성되고 심벌릭 링크를 생성했지만
	// 기존 파일에는 아무 변화가 없음을 확인 가능
	symlink("linux.txt", "linux.sym");
}
