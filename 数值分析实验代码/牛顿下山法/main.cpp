#include <iostream>
#include <math.h> 
using namespace std;

double f(double x);
double fx(double x);

int main(int argc, char** argv) {
	double x0;
	bool flag=true;
	double y,r;
	while(flag){
		cout<<"���������ֵx0"<<endl;
		cin>>x0;
		r=1;
		y=f(x0);
		int cnt=0;
		flag=false;
		while(abs(f(y))>abs(f(x0))){
			r=r/2;
			y=r*fx(x0)+(1-r)*x0;
			cnt++;
			//cout<<"cnt:  "<<cnt<<"  y: "<<y<<" r "<<r<<endl;
			if(cnt==100){
				flag=true;
				cout<<"��ɽʧ�ܣ������������ֵ"<<endl;
				break;	
			}
		}
	}
	cout<<"��ɽ�ɹ�! "<<"��ɽ����Ϊ��"<<r<<"�������x1Ϊ��"<<y<<endl;
	return 0;
}
double f(double x){
	return x*x*x-x-1;
}
double fx(double x){
	double y;
	y=x-(x*x*x-x-1)/(3*x*x-1);
	return y;
}

