#include  <stdio.h>

int main()
{
	int t =1;
	//const ���εĳ�����
	const int num = 10; //num����10�ˣ����ܸı��ˡ������������ڱ����ķ���
	//num = 20;
	printf("%d", num);

	char arr2[] = { 'a', 'b', 'c', '\0', 'd' };
	printf("%s", arr2);
	printf("%d", strlen(arr2));
	
	printf("\a");
	printf("%d", strlen("c:\test\328\test.c"));
	
	return 0;
}