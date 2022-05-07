#pragma once

//���峣��
#define ROW 3
#define COL 3

//Ӧ���ⲿͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//��������

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerInput(char board[ROW][COL], int row, int col);

//��������
void ComInput(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col);

//�ж��Ƿ���
int IsFull(char board[ROW][COL], int row, int col);
