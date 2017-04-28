#include <iostream>
#include <random>
#include <ctime>
#include <math.h>
#include <graphics.h>
#include <conio.h>

using namespace std;

#define MAXSIZE 100

struct Point {
	double x;
	double y;
	bool tag;	//区分标签
	Point() :x(0), y(0), tag(0) {};
	Point(double set_x, double set_y, bool set_tag) :x(set_x), y(set_y), tag(set_tag) {};
};

//生成随机数
double random_unint(unsigned int min, unsigned int max, unsigned int seed = 0)
{
	static std::default_random_engine e(seed);
	static std::uniform_int_distribution<int> u(min, max);
	return u(e);
}

Point *ProduceRandom(int size) {
	Point *random = new Point[size];
	for (int i = 0; i < size; i++) {
		random[i].x = random_unint(0, 100, (unsigned)time(NULL));
		random[i].y = random_unint(0, 100, (unsigned)time(NULL));
	}
	for (int i = 0; i < size; i++) {
		cout << random[i].x << "  " << random[i].y << endl;
	}
	return random;
}

Point* GetCenter(Point *point, int tag, int size) {
	int cnt = 0;	//计数
	double sum_x = 0, sum_y = 0;
	for (int i = 0; i < size; i++) {
		if (point[i].tag == 0) {
			sum_x += point[i].x;
			sum_y += point[i].y;
			cnt++;
		}
	}
	Point *center = new Point(sum_x / cnt, sum_y / cnt, tag);
	return center;
}

void Cluster(Point *pointset, int size) {
	int base_0 = 0;	//这里为了方便就直接选取0,1为种子点,这应该是不对的,但此处为了方便
	int base_1 = 1;
	double dist_0, dist_1;	//到基准的距离
	double temp_x, temp_y;
	for (int i = 0; i < size; i++) {
		temp_x = pointset[i].x - pointset[base_0].x;
		temp_y = pointset[i].y - pointset[base_0].y;
		dist_0 = temp_x*temp_x + temp_y*temp_y;
		temp_x = pointset[i].x - pointset[base_1].x;
		temp_y = pointset[i].y - pointset[base_1].y;
		dist_1 = temp_x*temp_x + temp_y*temp_y;
		dist_0 < dist_1 ? pointset[i].tag = 0 : pointset[i].tag = 1;	//离1近标签设置为0，否则设置为1
	}

	int cnt = 1000;	//迭代次数
	Point *center_0 = GetCenter(pointset, 0, size);
	Point *center_1 = GetCenter(pointset, 1, size);
	while (cnt--) {
		center_0 = GetCenter(pointset, 0, size);
		center_1 = GetCenter(pointset, 1, size);
		for (int i = 0; i < size; i++) {
			temp_x = pointset[i].x - center_0->x;
			temp_y = pointset[i].y - center_0->y;
			dist_0 = temp_x*temp_x + temp_y*temp_y;
			temp_x = pointset[i].x - center_1->x;
			temp_y = pointset[i].y - center_1->y;
			dist_1 = temp_x*temp_x + temp_y*temp_y;
			dist_0 < dist_1 ? pointset[i].tag = 0 : pointset[i].tag = 1;	//离0近标签设置为0，否则设置为1
		}
	}
	/*for (int i = 0; i < size; i++) {
		cout << pointset[i].x << " " << pointset[i].y << " " << pointset[i].tag << endl;
	}*/
}

void Drawing(Point *pointset,int size) {
	initgraph(640, 480, SHOWCONSOLE);   // 创建图形界面,同时显示控制台窗口		
	setaspectratio(2, 2);
	setbkcolor(BLUE);	// 设置背景色为蓝色
	cleardevice();	// 用背景色清空屏幕

	for (int i = 0; i < size; i++) {
		putpixel(pointset[i].x, pointset[i].y, BLACK);
		circle(pointset[i].x, pointset[i].y, 1);
	}
	_getch();               // 按任意键继续
	closegraph();          // 关闭图形界面
}

int main() {
	//Point *trainset = ProduceRandom(MAXSIZE);
	//Cluster(trainset, MAXSIZE);
	Point *trainset = ProduceRandom(MAXSIZE);
	Drawing(trainset,MAXSIZE);
	return 0;
}