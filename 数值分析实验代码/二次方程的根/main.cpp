#include <iostream>
#include <math.h>
using namespace std ;
//���η���Ϊx^2+2*b*x+c=0 
int main(int argc, char** argv) {
	double b,c;
	cout<<"���������b��c"<<endl;
	cin>>b>>c;
	double d=b*b-c;
	if(d<0){
		cout<<"��ʵ��"<<endl;
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
