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
	bool tag;	//���ֱ�ǩ
};

//���������
double random_unint(unsigned int min, unsigned int max, unsigned int seed = 0)
{
	static std::default_random_engine e(seed);
	static std::uniform_real_distribution<double> u(min, max);
	return u(e);
}

Point *PruduceRandom(int size) {
	Point *random = new Point[size];
	for (int i = 0; i < size; i++) {
		random[i].x = random_unint(0, 10, (unsigned)time(NULL));
		random[i].y = random_unint(0, 10, (unsigned)time(NULL));
	}
	for (int i = 0; i < size; i++) {
		cout << random[i].x << "  " << random[i].y << endl;
	}
	return random;
}

void Cluster(Point *pointset,int size) {
	int base1 = 0;	//����Ϊ�˷����ֱ��ѡȡ0,1Ϊ���ӵ�,��Ӧ���ǲ��Ե�,֮���Ż�
	int base2 = 1;
	double dist1,dist2;	//����׼�ľ���
	double temp_x, temp_y;
	for (int i = 0; i < size; i++) {
		temp_x = pointset[i].x - pointset[base1].x;
		temp_y = pointset[i].y - pointset[base1].y;
		dist1 = temp_x*temp_x + temp_y*temp_y;
		temp_x = pointset[i].x - pointset[base2].x;
		temp_y = pointset[i].y - pointset[base2].y;
		dist2 = temp_x*temp_x + temp_y*temp_y;
		dist1 < dist2 ? pointset[i].tag = 0 : pointset[i].tag = 1;
	}
	for (int i = 0; i < size; i++) {
		cout << pointset[i].x <<" "<< pointset[i].y <<" " <<pointset[i].tag << endl;
	}
}

int main() {
	Point *trainset = PruduceRandom(MAXSIZE);
	Cluster(trainset, MAXSIZE);
	initgraph(640, 480);   // ����ͼ�ν���
	circle(200, 200, 100); // ��Բ��Բ��(200, 200)���뾶 100
	getch();               // �����������
	closegraph();          // �ر�ͼ�ν���
	return 0;
}