#include <iostream>
using namespace std; 

double f(double x,double y);
int main(int argc, char** argv) {
	cout<<"ÊäÈëx0,y0,h,N"<<endl;
	double x0,y0,h,x1,y1,K1,K2,K3,K4;
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
		K1=f(x0,y0);
		K2=f(x0+h/2,y0+h/2*K1);
		K3=f(x0+h/2,y0+h/2*K2);
		K4=f(x1,y0+h*K3);
		y1=y0+h/6*(K1+2*K2+2*K3+K4);
		cout<<"x1: "<<x1<<", y1: "<<y1<<endl;
		flag=true;
	}while(n!=N);
	return 0;
}
double f(double x,double y){
	double z=y-2*x/y;
	return z;
}

