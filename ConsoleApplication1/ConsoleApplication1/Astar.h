#pragma once
/*
	//A*算法对象类
	
*/
#include <vector>
#include<list>
using namespace std;
const int kCost1 = 10;
const int kCost2 = 14;

struct Point
{
	int x, y;// 点坐标，按照c++的数组来计算，x代表横排，y代表竖排
	int F, G, H;
	Point* parent;
	Point(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL) { //初始化变量
	}
};
class Astar
{
public:
	Astar();
	~Astar();
public:
	void initAstar(vector<vector<int>> &_maze);
	list<Point*> getPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
private:
	Point* findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
	vector<Point*> getSurroundPoints(const Point* point, bool isIgnoreCorner)const;//得到传入点周围的点
	bool isCanreach(const Point* point, const Point* target, bool isIgnoreCorner)const;//判断某点是否可以到达
	Point* isInList(const list<Point*> &list, const Point* point)const;//判断某点是否在传入的列表中
	Point* getLeastFpoint();//从开启列表中返回F值最小的节点
	//计算FGH值
	int calcG(Point*temp_start, Point* point);
	int calcH(Point* point, Point* end);
	int calcF(Point* point);
private:
	vector<vector<int>> maze;//二维数组存放所有点坐标
	list<Point*> openList; //开启列表
	list<Point*> closeList;//关闭列表
};

