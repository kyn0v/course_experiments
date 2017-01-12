#include <iostream>
#include <math.h> 
using namespace std;
double f(double x);
int main(int argc, char** argv) {
	cout<<"请输入a,b,n"<<endl;
	double a,b,n;
	cin>>a>>b>>n;
	double h=(b-a)/n;
	double s=f(b)-f(a);
	double x=a;
	int k=1;
	x=x+h/2;
	s=s+4*f(x);
	x=x+h/2;
	s=s+2*f(x);
	while(k!=n){
		x=x+h/2;
		s=s+4*f(x);
		x=x+h/2;
		s=s+2*f(x);
		k++;
	}
	s=h/6*s;
	cout<<"s="<<s<<endl;
	cin>>s;
	return 0;
}
double f(double x){
	double y;
	if(x==0)	y=1;
	else	y=sin(x)/x;
	return y;   //分母不能为零
}
