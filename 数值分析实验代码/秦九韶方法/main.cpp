#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	cout<<"��������ߴ���ָ��"<<endl;
	int n;
	cin>>n;
	int a[n+1];
	cout<<"������ϵ��a0,a1,a2,...(�����ڵ���ϵ��Ϊ0)"<<endl;
	for(int i=0;i<n+1;i++){
		cin>>a[i];
	}
	cout<<"������x"<<endl;
	int x;
	cin>>x;
	int v=a[n];
	for(int k=1;k<n+1;k++){
		v=x*v+a[n-k];
	} 
	cout<<"���Ϊ"<<v<<endl; 
	cin>>x;
	return 0;
}
