#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("********1 . ��ʼ��Ϸ ********\n");
	printf("********0 . ������Ϸ ********\n");
	printf("*****************************\n");
}

void game()
{
	
	char arr[ROW][COL] = { 0 };
	char zh = 'c';
	//��ʼ������
	InitBoard(arr, ROW, COL);
	do
	{
		//��ӡ����
		PrintBoard(arr, ROW, COL);
		//�������
		printf("�ֵ��������\n");
		printf("����������>:");
		PlayerInput(arr, ROW, COL);
		system("cls");
		zh = IsWin(arr, ROW, COL);
		if (zh != 'C')
		{
			break;
		}
		//��������
		ComInput(arr, ROW, COL);
		printf("����������\n");
		zh = IsWin(arr, ROW, COL);
		if (zh != 'C')
		{
			break;
		}
	} while (1);

	system("cls");
	//�ж���Ӯ
	if (zh == 'F')
	{
		printf("\n");
		PrintBoard(arr, ROW, COL);
		printf("ƽ�֣�����\n");
	}
	else if (zh == '*')
	{
		printf("\n");
		PrintBoard(arr, ROW, COL);
		printf("���ʤ������\n");
	}
	else
	{
		printf("\n");
		PrintBoard(arr, ROW, COL);
		printf("����ʤ������\n");
	}
	printf("���س�������\n");

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 1;
	char ch = '\n';
	do
	{
		input = 2;
		menu();
		printf("���ѡ����>:");
A:
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("��ʼ��Ϸ\n");
			//���������
			while ((ch = getchar()) != '\n');
			game();
			break;
		case 0:
			printf("�������\n");
			break;
		default:
			printf("�����������������\n");
			//���������
			while ((ch = getchar()) != '\n');
			goto A;
		}
		//���س�������
		while ((ch = getchar()) != '\n');
		system("cls");
	} while (input);
	
	return 0;
}