#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("********1 . 开始游戏 ********\n");
	printf("********0 . 结束游戏 ********\n");
	printf("*****************************\n");
}

void game()
{
	
	char arr[ROW][COL] = { 0 };
	char zh = 'c';
	//初始化棋盘
	InitBoard(arr, ROW, COL);
	do
	{
		//打印棋盘
		PrintBoard(arr, ROW, COL);
		//玩家下棋
		printf("轮到玩家下棋\n");
		printf("请输入坐标>:");
		PlayerInput(arr, ROW, COL);
		system("cls");
		zh = IsWin(arr, ROW, COL);
		if (zh != 'C')
		{
			break;
		}
		//电脑下棋
		ComInput(arr, ROW, COL);
		printf("电脑已下棋\n");
		zh = IsWin(arr, ROW, COL);
		if (zh != 'C')
		{
			break;
		}
	} while (1);

	system("cls");
	//判断输赢
	if (zh == 'F')
	{
		printf("\n");
		PrintBoard(arr, ROW, COL);
		printf("平局！！！\n");
	}
	else if (zh == '*')
	{
		printf("\n");
		PrintBoard(arr, ROW, COL);
		printf("玩家胜！！！\n");
	}
	else
	{
		printf("\n");
		PrintBoard(arr, ROW, COL);
		printf("电脑胜！！！\n");
	}
	printf("按回车键继续\n");

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
		printf("你的选择是>:");
A:
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("开始游戏\n");
			//清除缓冲区
			while ((ch = getchar()) != '\n');
			game();
			break;
		case 0:
			printf("程序结束\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			//清除缓冲区
			while ((ch = getchar()) != '\n');
			goto A;
		}
		//按回车键继续
		while ((ch = getchar()) != '\n');
		system("cls");
	} while (input);
	
	return 0;
}