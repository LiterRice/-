#pragma once

//定义常数
#define ROW 15
#define COL 15
#define mine_count 20
#define ROWS ROW+2
#define COLS COL+2



//应用外部头文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//声明函数

//清除缓冲区
void DelSave();

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int row, int col, char set);

//输出棋盘
void PrintBoard(char board[ROWS][COLS], int row, int col);

//输入坐标
void InputCoor(char show[ROWS][COLS], int* x, int* y, int row, int col, char ch);

//第一次输入+设置雷区
void InitMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int* count);

//排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* count);

