#include <iostream>
#include <math.h>
using namespace std;
double f(double x);
int main(int argc, char** argv) {
	cout<<"输入a,b,e"<<endl;
	double a,b,e,s,x,T1,T2,S1,S2,C1,C2,R1=999999,R2=0;
	cin>>a>>b>>e;
	double h=b-a;
	T1=h/2*(f(a)+f(b));
	int k=1;
	do{
		s=0;
		x=a+h/2;
		while(x<b){
			s=f(x)+s;
			x=x+h;
		}
		T2=T1/2+h/2*s;
		
		S2=T2+1/3*(T2-T1);
		switch(k){	
			case 2:
				S2=T2+1/3*(T2-T1);
				C2=S2+1/15*(S2-S1);break;
			case 3:
				S2=T2+1/3*(T2-T1);
				C2=S2+1/15*(S2-S1);
				R2=C2+1/63*(C2-C1);break;
		}
		switch(k){
			case 3:
				R1=R2;
			case 2:
				C1=C2;
			case 1:
				k++;
				h=h/2;
				T1=T2;
				S1=S2;break;
		}
	}while(abs(R2-R1)>e);
	cout<<R2<<endl;
	return 0;
}
double f(double x){
	double y;
	if(x==0)	y=1;
	else	y=sin(x)/x;
	return y;   //分母不能为零
}
