#pragma once

//���峣��
#define ROW 15
#define COL 15
#define mine_count 20
#define ROWS ROW+2
#define COLS COL+2



//Ӧ���ⲿͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//��������

//���������
void DelSave();

//��ʼ������
void InitBoard(char board[ROWS][COLS], int row, int col, char set);

//�������
void PrintBoard(char board[ROWS][COLS], int row, int col);

//��������
void InputCoor(char show[ROWS][COLS], int* x, int* y, int row, int col, char ch);

//��һ������+��������
void InitMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int* count);

//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* count);

