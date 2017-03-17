#include <iostream>
using namespace std; 
double f(double x,double y);
int main(int argc, char** argv) {
	cout<<"ÊäÈëx0,y0,h,N"<<endl;
	double x0,y0,h,x1,y1,yp,yc;
	int N;
	cin>>x0>>y0>>h>>N;
	int n=1;
	bool flag=false;
	do{
		if(flag){
			n++;
			x0=x1;
			y0=y1;
		}
		x1=x0+h;
		yp=y0+h*f(x0,y0);
		yc=y0+h*f(x1,yp);
		y1=(yc+yp)/2;
		cout<<"x1: "<<x1<<", y1: "<<y1<<endl;
		flag=true;
	}while(n!=N);
	return 0;
}
double f(double x,double y){
	double z=y-2*x/y;
	return z;
}
