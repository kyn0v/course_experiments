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
	cout<<"原大小"<<a<<endl;
	cout<<"现大小"<<b<<endl;
	cout<<"压缩率"<<(float)b/a<<endl;

	int x;
	cin>>x;
	return 0;
}