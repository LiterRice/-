#include "game.h"

//开始菜单
void menu()
{
	printf("*****************************\n");
	printf("********1 . 开始游戏 ********\n");
	printf("********0 . 结束游戏 ********\n");
	printf("*****************************\n");
}


//游戏执行函数
void game()
{
	int input = 3;
	int Clear = ROW * COL - mine_count;
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	int x = ROWS;
	int y = COLS;
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//输出棋盘
	//PrintBoard(mine, ROW, COL);//测试：输出雷区
	PrintBoard(show, ROW, COL);

	//第一次输入+设置雷区
	InitMine(mine, show, ROW, COL, &Clear);
	
	//开始排雷
	while (Clear)
	{
		system("cls");
		//PrintBoard(mine, ROW, COL);//调试：输出雷区
		PrintBoard(show, ROW, COL);
		printf("\"1 坐标\"表示排雷\n\"2 坐标\"表示插旗\n\"3 坐标\"表示拔旗\n");
A:
		printf("请输入数值>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			//PrintBoard(mine, ROW, COL);//调试：输出雷区
			PrintBoard(show, ROW, COL);
			printf("开始排雷，");
			InputCoor(show, &x, &y, ROW, COL, '*');
			FindMine(mine, show, x, y, &Clear);
			break;
		case 2:
			system("cls");
			//PrintBoard(mine, ROW, COL);//调试：输出雷区
			PrintBoard(show, ROW, COL);
			printf("开始插旗，");
			InputCoor(show, &x, &y, ROW, COL, '*');
			show[x][y] = '@';//做上插旗标志
			break;
		case 3:
			system("cls");
			//PrintBoard(mine, ROW, COL);//调试：输出雷区
			PrintBoard(show, ROW, COL);
			printf("开始拔棋,");
			InputCoor(show, &x, &y, ROW, COL, '@');
			show[x][y] = '*';//恢复成未知区域
			break;
		default:
			printf("输入有误，请重新输入！！！\n");
			DelSave();
			goto A;
		}
	}
	printf("游戏结束，按回车键返回游戏菜单\n");



}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 1;
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
			//清除缓冲区
			DelSave();
			game();
			break;
		case 0:
			printf("程序结束\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			//清除缓冲区
			DelSave();
			goto A;
		}
		//按回车键继续
		DelSave();
		system("cls");
	} while (input);

	return 0;
}