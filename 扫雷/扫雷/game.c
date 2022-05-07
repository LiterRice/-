#include "game.h"

//静态函数区
//生成雷区
static void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int i = 0;
	int x;
	int y;
	for (i = mine_count; i > 0; )
	{
		x = rand() % row + 1;
		y = rand() % row + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			i--;
		}
	}
}

//开图，并且统计附近雷数量
static void CountMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* clear)
{
	//能进来的都是未访问过的，直接+2
	mine[x][y] += 2;

	//判断是否在边界区
	if (x == 0 || x == ROW + 1 || y == 0 || y == COL + 1)
	{
		return;
	}

	//执行程序
	int count = 0;
	int i = 0;
	int j = 0;
	//计算附近雷区
	//对2取余是消去访问flag的影响
	count = ((mine[x - 1]	[y]		- '0') % 2) +
			((mine[x - 1]	[y - 1] - '0') % 2) +
			((mine[x]		[y - 1] - '0') % 2) +
			((mine[x + 1]	[y - 1] - '0') % 2) +
			((mine[x + 1]	[y]		- '0') % 2) +
			((mine[x + 1]	[y + 1] - '0') % 2) +
			((mine[x]		[y + 1] - '0') % 2) +
			((mine[x - 1]	[y + 1] - '0') % 2);
	
	//若附近无雷，自动打开其他雷区
	if (count == 0)
	{
		show[x][y] = '-';
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				if (mine[x + i][y + j] < '2')//判断该元素是否访问过
				{
					CountMine(mine, show, x + i, y + j, clear);
					//PrintBoard(show, ROW, COL);//调试：输出展示棋盘
				}
			}
		}
			
	}
	else
	{
		show[x][y] = count+'0';
	}

	(*clear)--;//剩余可操作区域减一
}



//函数区

//清除缓冲区
void DelSave()
{
	char ch = '\n';
	while ((ch = getchar()) != '\n');
}

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}


//输出棋盘
void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%2d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%2c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//输入坐标
void InputCoor(char show[ROWS][COLS], int* x, int* y, int row, int col, char ch)
{
	*x = row + 1;
	*y = col + 1;

	//进行有效坐标输入规范
	printf("请输入坐标>:");
	do
	{
		scanf("%d %d", x, y);
		DelSave();
		if (*x > 0 && *x <= row && *y > 0 && *y <= col)
		{
			if (show[*x][*y] != ch)
			{
				//确保输入坐标为未知区域的规范
				printf("该区域不需要这样操作，请重新输入坐标\n");
			}
			else
			{
				break;
			}
		}
		else
			printf("输入错误的坐标，请重新输入坐标\n");
	} while (1);
}


//第一次输入+设置雷区
void InitMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int* clear)
{
	
	int x = 0;
	int y = 0;
	InputCoor(show, &x, &y, row, col, '*');

	mine[x][y] = '1';//雷区临时放上一个假雷；
	
	//生成雷区
	SetMine(mine, row, col);
	mine[x][y] = '0';//去除掉雷区的假雷

	//第一次排雷
	FindMine(mine, show, x, y, clear);


	
}


//排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int * clear)
{
	int i = 0;
	if (mine[x][y] == '1')
	{
		system("cls");
		for (i = 0; i < 16; i++)
		{
			printf("很遗憾，你被炸死了\n");
		}
		*clear = 0;
	}
	else
	{
		CountMine(mine, show, x, y, clear);
		if (!*clear)
		{
			system("cls");
			PrintBoard(show, ROW, COL);
			printf("\n恭喜您，排雷成功！！！\n");
		}
	}
}


