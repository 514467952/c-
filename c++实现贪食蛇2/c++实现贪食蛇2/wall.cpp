#include<iostream>
#include"wall.h"
using namespace std;


void Wall::initWall() //初始化墙壁，用二维数组
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//放墙壁的地方
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
			{
				gameArray[i][j] = '*';
			}
			else
			{
				gameArray[i][j] = ' ';
			}
		}
	}
}

void Wall::drawWall()
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			//画的时候多加一个空格，看起来好看一些
			cout << gameArray[i][j] << " ";
		}
		if (i == 4)
		{
			cout << "版本：1.0";
		}
		if (i == 5)
		{
			cout << "制作人：刘晓昱";
		}
		if (i == 6)
		{
			cout << "a:向左";
		}
		if (i == 7)
		{
			cout << "d:向右";
		}
		if (i == 8)
		{
			cout << "w:向上";
		}
		if (i == 9)
		{
			cout << "s:向下";
		}
		cout << endl;
	}
}

void Wall::setWall(int x, int y, char c)
{
	gameArray[x][y] = c;
}

char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
}