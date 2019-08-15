#ifndef _WALL_HEAD//防止头文件被重复编译
#define _WALL_HEAD

#include<iostream>
using namespace std;

class Wall
{
public:
	enum
	{
		ROW = 26, //行数
		COL = 26//列数
	};
	//初始化墙壁
	void initWall();
	//画出墙壁
	void drawWall();
	//根据索引来设置 二维数组里的内容
	//设置蛇的部分的时候和设置食物要用
	void setWall(int x, int y, char c);
	//根据索引来获取当前位置的符号
	char getWall(int x, int y);
private:
	char gameArray[ROW][COL];
};


#endif