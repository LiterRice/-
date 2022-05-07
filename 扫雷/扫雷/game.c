#include "game.h"

//��̬������
//��������
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

//��ͼ������ͳ�Ƹ���������
static void CountMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* clear)
{
	//�ܽ����Ķ���δ���ʹ��ģ�ֱ��+2
	mine[x][y] += 2;

	//�ж��Ƿ��ڱ߽���
	if (x == 0 || x == ROW + 1 || y == 0 || y == COL + 1)
	{
		return;
	}

	//ִ�г���
	int count = 0;
	int i = 0;
	int j = 0;
	//���㸽������
	//��2ȡ������ȥ����flag��Ӱ��
	count = ((mine[x - 1]	[y]		- '0') % 2) +
			((mine[x - 1]	[y - 1] - '0') % 2) +
			((mine[x]		[y - 1] - '0') % 2) +
			((mine[x + 1]	[y - 1] - '0') % 2) +
			((mine[x + 1]	[y]		- '0') % 2) +
			((mine[x + 1]	[y + 1] - '0') % 2) +
			((mine[x]		[y + 1] - '0') % 2) +
			((mine[x - 1]	[y + 1] - '0') % 2);
	
	//���������ף��Զ�����������
	if (count == 0)
	{
		show[x][y] = '-';
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				if (mine[x + i][y + j] < '2')//�жϸ�Ԫ���Ƿ���ʹ�
				{
					CountMine(mine, show, x + i, y + j, clear);
					//PrintBoard(show, ROW, COL);//���ԣ����չʾ����
				}
			}
		}
			
	}
	else
	{
		show[x][y] = count+'0';
	}

	(*clear)--;//ʣ��ɲ��������һ
}



//������

//���������
void DelSave()
{
	char ch = '\n';
	while ((ch = getchar()) != '\n');
}

//��ʼ������
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


//�������
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

//��������
void InputCoor(char show[ROWS][COLS], int* x, int* y, int row, int col, char ch)
{
	*x = row + 1;
	*y = col + 1;

	//������Ч��������淶
	printf("����������>:");
	do
	{
		scanf("%d %d", x, y);
		DelSave();
		if (*x > 0 && *x <= row && *y > 0 && *y <= col)
		{
			if (show[*x][*y] != ch)
			{
				//ȷ����������Ϊδ֪����Ĺ淶
				printf("��������Ҫ������������������������\n");
			}
			else
			{
				break;
			}
		}
		else
			printf("�����������꣬��������������\n");
	} while (1);
}


//��һ������+��������
void InitMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int* clear)
{
	
	int x = 0;
	int y = 0;
	InputCoor(show, &x, &y, row, col, '*');

	mine[x][y] = '1';//������ʱ����һ�����ף�
	
	//��������
	SetMine(mine, row, col);
	mine[x][y] = '0';//ȥ���������ļ���

	//��һ������
	FindMine(mine, show, x, y, clear);


	
}


//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int * clear)
{
	int i = 0;
	if (mine[x][y] == '1')
	{
		system("cls");
		for (i = 0; i < 16; i++)
		{
			printf("���ź����㱻ը����\n");
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
			printf("\n��ϲ�������׳ɹ�������\n");
		}
	}
}


