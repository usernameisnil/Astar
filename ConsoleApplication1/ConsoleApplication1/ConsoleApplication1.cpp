// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream> 
#include "Astar.h" 
using namespace std;

int main() {
	//初始化地图，用二维矩阵代表地图，1表示障碍物，0表示可通 
	vector<vector<int>> maze = {
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,1,0,1,0,0,0,0,1},
		{1,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,1,1,1},
		{1,1,1,0,0,0,0,0,1,1,0,1},
		{1,1,0,1,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,1,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1}
	};
	Astar astar;

	astar.initAstar(maze);
	Point start(1, 1);
	Point end(6, 10);
	list<Point*> path = astar.getPath(start, end, false);
	//打印 
	for (auto &p : path)
		std::cout << '(' << p->x << ',' << p->y << ')' << std::endl;

	system("pause");

	return 0;
}