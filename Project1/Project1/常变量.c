#include  <stdio.h>

int main()
{
	int t =1;
	//const 修饰的常变量
	const int num = 10; //num就是10了，不能改变了。但它还是属于变量的范畴
	//num = 20;
	printf("%d", num);

	char arr2[] = { 'a', 'b', 'c', '\0', 'd' };
	printf("%s", arr2);
	printf("%d", strlen(arr2));
	
	printf("\a");
	printf("%d", strlen("c:\test\328\test.c"));
	
	return 0;
}