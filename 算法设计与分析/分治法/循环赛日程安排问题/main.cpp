//设有n = 2k个运动员要进行循环比赛，现要设计一个满足以下要求的比赛日程表：
//(1) 每个选手必须与其他n - 1个选手各比赛一次。
//(2) 每个选手一天只能比赛一次。
//(3) 循环赛一共需要进行n - 1天。

#include <iostream>
using namespace std;
int main() {
	int num;
	cout << "请输入选手数量(要求为2的指数):" << endl;
	cin >> num;

	// 为日程表分配内存
	int **a = new int*[num + 1];
	for (int i = 0; i < num + 1; ++i) {
		a[i] = new int[num];
	}

	// 填充第一列
	for (int i = 0; i<num + 1; ++i)
		a[i][0] = i;
	for (int i = 0; i < num; ++i)
		a[0][i] = i;

	// s(scale)控制本次处理的块的规模
	for (int s = 1; s<num; s *= 2) {
		// p(part)控制本次处理的块的起始位置，从上到下遍历同一规模的所有块的左上角位置
		for (int p = 1; p <= num; p += s) {
			// i和j循环本次处理的块内的所有内容
			for (int i = p; i<p + s; ++i) {
				for (int j = s; j<2 * s; ++j) {
					// (p+s-1)/s是奇数，取左下
					if (((p + s - 1) / s) % 2 != 0) {
						a[i][j] = a[i + s][j - s];
					}
					// (p+s-1)/s是偶数，取左上
					else {
						a[i][j] = a[i - s][j - s];
					}
				}
			}
		}
	}

	// 输出
	// 虽然二维数组实际上是5X4的，但是第一行仅仅是为了运算时取坐标方便和表示天数，没有意义，故不显示
	cout << "日程表" << endl;
	cout << "第一行为天数，第一列为选手号" << endl << endl;
	for (int i = 0; i < num + 1; ++i) {
		for (int j = 0; j < num; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// 清理
	for (int i = 0; i < num + 1; ++i) {
		delete[] a[i];
	}
	delete[] a;
	system("pause");
	return 0;
}