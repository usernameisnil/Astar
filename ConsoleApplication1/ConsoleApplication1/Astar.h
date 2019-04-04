#pragma once
/*
	//A*�㷨������
	
*/
#include <vector>
#include<list>
using namespace std;
const int kCost1 = 10;
const int kCost2 = 14;

struct Point
{
	int x, y;// �����꣬����c++�����������㣬x������ţ�y��������
	int F, G, H;
	Point* parent;
	Point(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL) { //��ʼ������
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
	vector<Point*> getSurroundPoints(const Point* point, bool isIgnoreCorner)const;//�õ��������Χ�ĵ�
	bool isCanreach(const Point* point, const Point* target, bool isIgnoreCorner)const;//�ж�ĳ���Ƿ���Ե���
	Point* isInList(const list<Point*> &list, const Point* point)const;//�ж�ĳ���Ƿ��ڴ�����б���
	Point* getLeastFpoint();//�ӿ����б��з���Fֵ��С�Ľڵ�
	//����FGHֵ
	int calcG(Point*temp_start, Point* point);
	int calcH(Point* point, Point* end);
	int calcF(Point* point);
private:
	vector<vector<int>> maze;//��ά���������е�����
	list<Point*> openList; //�����б�
	list<Point*> closeList;//�ر��б�
};

