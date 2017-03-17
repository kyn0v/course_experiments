#include <iostream>
#include <math.h>
using namespace std; 
double f(double x);

int main(int argc, char** argv) {
	cout<<"请输入a,b,n"<<endl;
	double a,b,e;
	cin>>a>>b>>e;
	double h=b-a;
	double T1=h/2*(f(a)+f(b));
	double s=0;
	double x=a+h/2;
	s=s+f(x);
	x=x+h;
	while(x<b){
		s=s+f(x);
		x=x+h;
	}
	double T2=T1/2+h/2*s;
	while(abs(T2-T1)>=e){
		h=h/2;
		T1=T2;
		s=0;
		x=a+h/2;
		s=s+f(x);
		x=x+h;
	while(x<b){
		s=s+f(x);
		x=x+h;
	}
	T2=T1/2+h/2*s;
	}
	cout<<"T2="<<T2<<endl;
	return 0;
}
double f(double x){
	double y;
	if(x==0)	y=1;
	else	y=sin(x)/x;
	return y;    //分母不能为零
}
