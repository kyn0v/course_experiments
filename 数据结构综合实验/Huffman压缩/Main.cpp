#include <stdio.h>
#include <iostream>
#include "HuffmanTree.h"
#include "Compress.h"
using namespace std;

int main(){
	cout<<"Input Location"<<endl;
	char filename[256];
	cin>>filename;
	int a,b;
	Compress(filename,a,b);
	cout<<"ԭ��С"<<a<<endl;
	cout<<"�ִ�С"<<b<<endl;
	cout<<"ѹ����"<<(float)b/a<<endl;

	int x;
	cin>>x;
	return 0;
}