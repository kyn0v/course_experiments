#include <iostream>
#include <math.h>
using namespace std ;
//二次方程为x^2+2*b*x+c=0 
int main(int argc, char** argv) {
	double b,c;
	cout<<"请输入参数b和c"<<endl;
	cin>>b>>c;
	double d=b*b-c;
	if(d<0){
		cout<<"无实根"<<endl;
	}
	else {
		if(d==0){
			cout<<"x1="<<-b<<endl<<"x2="<<-b<<endl;
		}
		else{
			cout<<"x1="<<(-b+sqrt(d))<<endl<<"x2="<<(-2*b-(-b+sqrt(d)))<<endl;
		}
	}
	return 0;
}
