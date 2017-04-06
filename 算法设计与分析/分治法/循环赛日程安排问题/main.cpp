//����n = 2k���˶�ԱҪ����ѭ����������Ҫ���һ����������Ҫ��ı����ճ̱�
//(1) ÿ��ѡ�ֱ���������n - 1��ѡ�ָ�����һ�Ρ�
//(2) ÿ��ѡ��һ��ֻ�ܱ���һ�Ρ�
//(3) ѭ����һ����Ҫ����n - 1�졣

#include <iostream>
using namespace std;
int main() {
	int num;
	cout << "������ѡ������(Ҫ��Ϊ2��ָ��):" << endl;
	cin >> num;

	// Ϊ�ճ̱�����ڴ�
	int **a = new int*[num + 1];
	for (int i = 0; i < num + 1; ++i) {
		a[i] = new int[num];
	}

	// ����һ��
	for (int i = 0; i<num + 1; ++i)
		a[i][0] = i;
	for (int i = 0; i < num; ++i)
		a[0][i] = i;

	// s(scale)���Ʊ��δ���Ŀ�Ĺ�ģ
	for (int s = 1; s<num; s *= 2) {
		// p(part)���Ʊ��δ���Ŀ����ʼλ�ã����ϵ��±���ͬһ��ģ�����п�����Ͻ�λ��
		for (int p = 1; p <= num; p += s) {
			// i��jѭ�����δ���Ŀ��ڵ���������
			for (int i = p; i<p + s; ++i) {
				for (int j = s; j<2 * s; ++j) {
					// (p+s-1)/s��������ȡ����
					if (((p + s - 1) / s) % 2 != 0) {
						a[i][j] = a[i + s][j - s];
					}
					// (p+s-1)/s��ż����ȡ����
					else {
						a[i][j] = a[i - s][j - s];
					}
				}
			}
		}
	}

	// ���
	// ��Ȼ��ά����ʵ������5X4�ģ����ǵ�һ�н�����Ϊ������ʱȡ���귽��ͱ�ʾ������û�����壬�ʲ���ʾ
	cout << "�ճ̱�" << endl;
	cout << "��һ��Ϊ��������һ��Ϊѡ�ֺ�" << endl << endl;
	for (int i = 0; i < num + 1; ++i) {
		for (int j = 0; j < num; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// ����
	for (int i = 0; i < num + 1; ++i) {
		delete[] a[i];
	}
	delete[] a;
	system("pause");
	return 0;
}