#pragma once

//定义常数
#define ROW 3
#define COL 3

//应用外部头文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//声明函数

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerInput(char board[ROW][COL], int row, int col);

//电脑下棋
void ComInput(char board[ROW][COL], int row, int col);

//判断输赢
char IsWin(char board[ROW][COL], int row, int col);

//判断是否满
int IsFull(char board[ROW][COL], int row, int col);
