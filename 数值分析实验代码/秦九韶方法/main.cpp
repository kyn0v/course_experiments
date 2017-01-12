#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	cout<<"请输入最高次幂指数"<<endl;
	int n;
	cin>>n;
	int a[n+1];
	cout<<"请输入系数a0,a1,a2,...(不存在的项系数为0)"<<endl;
	for(int i=0;i<n+1;i++){
		cin>>a[i];
	}
	cout<<"请输入x"<<endl;
	int x;
	cin>>x;
	int v=a[n];
	for(int k=1;k<n+1;k++){
		v=x*v+a[n-k];
	} 
	cout<<"结果为"<<v<<endl; 
	cin>>x;
	return 0;
}
