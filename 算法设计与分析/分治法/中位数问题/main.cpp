#include <iostream>
using namespace std;

int Adjust_array(int *a, int l, int r) {
	int i = l, j = r;
	int x = a[l];     //基准值 
	while (i<j) {
		while (j>i&&a[j] >= x) {
			j--;
		}
		if (i<j) {
			a[i] = a[j];
			i++;
		}
		while (i<j&&a[i]<x) {   //<=
			i++;
		}
		if (i<j) {
			a[j] = a[i];
			j--;
		}
	}
	a[i] = x;
	return i;
}

void Quick(int *a, int l, int r) {
	if (l<r) {    //结束条件 
		int base = Adjust_array(a, l, r);
		Quick(a, l, base - 1);      //将base排除在外，将左右区间递归快速排序
		Quick(a, base + 1, r);
	}

}

void Print(int *a, int size) {
	for (int i = 0; i<size; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	Print(a, n);
	Quick(a, 0, n - 1);
	Print(a, n);
	if (n % 2 == 1) {
		cout << a[n / 2] << endl;
	} else {
		cout << (a[n / 2] + a[n / 2 - 1]) / 2 << endl;
	}
	system("pause");
	return 0;
}
//8 23 29 20 32 23 21 33 25
//9 23 29 20 32 23 21 33 25 34