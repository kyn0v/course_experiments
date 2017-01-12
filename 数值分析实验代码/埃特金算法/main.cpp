#include <iostream>
using namespace std;

struct Point{
	double x;
	double y;
};
int main(int argc, char** argv) {
	/*double x;
	int n=0;
	cin>>x;
	cin>>n;
	Point a[10];
	for(int i=0;i<n;i++){
		cin>>a[i].x;
		cin>>a[i].y;
	}
	for(int j=0;j<n;j++){
		cout<<"x"<<j<<"="<<a[j].x<<" , ";
		cout<<"y"<<j<<"="<<a[j].y<<endl;
	}*/
	double x=125;
	int n=3;
	Point a[10];
	a[0].x=100;a[0].y=10;
	a[1].x=121;a[1].y=11;
	a[2].x=144;a[2].y=12;
	double y=0;
	int k=1;
	while(k<=n){
		for(int j=k;j<=n;j++){
			a[j].y=a[k-1].y+(double)(a[j].y-a[k-1].y)/(a[j].x-a[k-1].x)*(x-a[k-1].x);
		}
		k++;
	}
	cout<<a[n].y<<endl;
	
	cin>>x;
	return 0;
}

