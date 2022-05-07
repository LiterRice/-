#include "game.h"

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("   ");
	for (i = 0;i < row; i++)
	{
		printf(" %d  ", i + 1);
	}
	printf("\n  |");
	for (i = 0;i < row; i++)
	{
		printf("---|");
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		printf("%2d|", i + 1);
		for (j = 0; j < col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n  |");
		for (j = 0; j < col; j++)
		{
			printf("---|");
		}
		printf("\n");
	}
}

//�������
void PlayerInput(char board[ROW][COL], int row, int col)
{
	char ch = '\n';
	int x = row + 1;
	int y = col + 1;

	do
	{
		scanf("%d %d", &x, &y);
		//���������
		while ((ch = getchar()) != '\n');
		if (x > 0 && x < (row + 1) && y > 0 && y < (col + 1))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("��λ����ռ�ã�����������\n");
			}
		}
		else
		{
			printf("�����������������\n");
		}
	} while (1);
	
}

//��������
void ComInput(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	do
	{
		x = rand() % row;
		y = rand() % row;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	} while (1);
}

//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int zh = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}

	zh = IsFull(board, ROW, COL);
	if (zh == 1)
	{
		return 'F';
	}
	
	return 'C';
}

//�ж��Ƿ���
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}


