#include <iostream>
#include <cmath>  //cmath��abs()�����ɷ���double����math.h��ֻ�ܷ���int 
using namespace std; 
double f(double x);
int main(int argc, char** argv) {
	cout<<"����x0,e,N"<<endl;
	double x0,e,x1;
	int N;
	cin>>x0>>e>>N;
	int k=1;
	do{
		x1=f(x0);
		if(abs(x1-x0)<e){
			break;
		}
		if(k==N){
			cout<<"����ʧ��"<<endl;
			exit(0);
		}
		cout<<"k: "<<k<<", xk: "<<x1<<endl;
		k++;
		x0=x1;
	}while(true);
	cout<<x1<<endl;
	return 0;
}


double f(double x){
	double y=pow(x+1,1.0/3);
	return y;
}
