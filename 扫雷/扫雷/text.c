#include "game.h"

//��ʼ�˵�
void menu()
{
	printf("*****************************\n");
	printf("********1 . ��ʼ��Ϸ ********\n");
	printf("********0 . ������Ϸ ********\n");
	printf("*****************************\n");
}


//��Ϸִ�к���
void game()
{
	int input = 3;
	int Clear = ROW * COL - mine_count;
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	int x = ROWS;
	int y = COLS;
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//�������
	//PrintBoard(mine, ROW, COL);//���ԣ��������
	PrintBoard(show, ROW, COL);

	//��һ������+��������
	InitMine(mine, show, ROW, COL, &Clear);
	
	//��ʼ����
	while (Clear)
	{
		system("cls");
		//PrintBoard(mine, ROW, COL);//���ԣ��������
		PrintBoard(show, ROW, COL);
		printf("\"1 ����\"��ʾ����\n\"2 ����\"��ʾ����\n\"3 ����\"��ʾ����\n");
A:
		printf("��������ֵ>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			//PrintBoard(mine, ROW, COL);//���ԣ��������
			PrintBoard(show, ROW, COL);
			printf("��ʼ���ף�");
			InputCoor(show, &x, &y, ROW, COL, '*');
			FindMine(mine, show, x, y, &Clear);
			break;
		case 2:
			system("cls");
			//PrintBoard(mine, ROW, COL);//���ԣ��������
			PrintBoard(show, ROW, COL);
			printf("��ʼ���죬");
			InputCoor(show, &x, &y, ROW, COL, '*');
			show[x][y] = '@';//���ϲ����־
			break;
		case 3:
			system("cls");
			//PrintBoard(mine, ROW, COL);//���ԣ��������
			PrintBoard(show, ROW, COL);
			printf("��ʼ����,");
			InputCoor(show, &x, &y, ROW, COL, '@');
			show[x][y] = '*';//�ָ���δ֪����
			break;
		default:
			printf("�����������������룡����\n");
			DelSave();
			goto A;
		}
	}
	printf("��Ϸ���������س���������Ϸ�˵�\n");



}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 1;
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
			//���������
			DelSave();
			game();
			break;
		case 0:
			printf("�������\n");
			break;
		default:
			printf("�����������������\n");
			//���������
			DelSave();
			goto A;
		}
		//���س�������
		DelSave();
		system("cls");
	} while (input);

	return 0;
}