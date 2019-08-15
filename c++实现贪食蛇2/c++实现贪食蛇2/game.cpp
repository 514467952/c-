#include<iostream>

using namespace std;
#include"wall.h"
#include"snake.h"
#include"food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>

//解决光标问题
void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量


int main()
{
	//添加随机种子
	srand((unsigned int)time(NULL));

	//是否死亡的标识
	bool isDead = false;

	char preKey = NULL;
	Wall wall;
	wall.initWall();
	wall.drawWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall,food);
	snake.InitSnake();


	
	gotoxy(hOut, 0, Wall::ROW);
	cout << "得分：" << snake.getScore() << "分" << endl;
	//gotoxy(hOut, 10, 5);//y*2 x 
	//接受用户的输入

	while (!isDead)
	{
		char key = _getch();

		//判断如果是第一次按了，左键，才不能激活游戏
		//判断上一次移动方向
		if (preKey == NULL&&key == snake.LEFT)
		{
			continue;
		}


		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//判断本次按键是否与上次冲突
				if ((key == snake.LEFT&&preKey == snake.RIGHT )||
					(key == snake.RIGHT&&preKey == snake.LEFT )||
					(key == snake.UP&&preKey == snake.DOWN) ||
					(key == snake.DOWN&&preKey == snake.UP) 
					)
				{
					key = preKey;
				}
				else
				{
					preKey = key;//不是冲突按键，可以更新按键
				}
				
				if (snake.move(key) == true)
				{
					//移动成功
					//system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0, Wall::ROW);
	
					cout << "得分：" << snake.getScore() << "分" << endl;
					Sleep(snake.getSleepTime());
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey;//强制将错误按键变为上一次移动的方向
			}
		
		} while (!_kbhit());//当没有键盘输入的时候返回0
		
	}
	

	

	system("pause");
	return 0;
}