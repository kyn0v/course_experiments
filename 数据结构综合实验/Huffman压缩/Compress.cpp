#include "HuffmanTree.h"
#include "Compress.h"
#include <iostream>
#include <stdio.h>
using namespace std;

char Str2byte(const string pBinStr){
	char b=0x00;
	for(int i=0;i<8;i++){
		b=b<<1;
		if(pBinStr[i]=='1'){
			b=b|0x01;
		}
	}
	return b;
}
bool InitHead(const char* pFilename,Head& sHead,int add){
	strcpy_s(sHead.type,"HUF");
	sHead.length=0;
	for(int i=0;i<256;i++){
		sHead.weight[i]=0;
	}
	sHead.add_0=add;
	FILE* in;
	fopen_s(&in,pFilename,"rb");
	int ch;
	while((ch=getc(in))!=EOF){
		sHead.weight[ch]++;
		sHead.length++;
	}
	fclose(in);
	in=NULL;
	return true;
}
bool WriteFile(const char* pFilename,const Head sHead,const char* pBuffer,const int size){
	char filename[256]={0};
	strcpy_s(filename,pFilename);
	strcat_s(filename,".huf");
	FILE* out;
	fopen_s(&out,filename,"wb");
	fwrite(& sHead,sizeof(Head),1,out);
	fwrite(pBuffer,sizeof(char),size,out);
	fclose(out);
	out=NULL;
	return true;
}
bool Compress(const char* pFilename,int& a,int &b){
	FILE* in1;
	fopen_s(&in1,pFilename,"rb");
	int weight[256]={0};
	int ch;
	a=0;
	while((ch=getc(in1))!=EOF){
		weight[ch]++;
		a++;
	}
	HuffmanTree pHT=Create(weight);
	string* pHC=new string[256];
	HuffmanCoding( pHC,pHT);
	TestHC(510,pHT,pHC);

	int size=0;
	for(int i=0;i<256;i++){
		size=size+weight[i]*pHC[i].length();
	}
	size=(size%8)?size/8+1:size/8;

	string cd="";
	FILE* in2;
	errno_t err2=fopen_s(&in2,pFilename,"rb");
	while((ch=getc(in2))!=EOF){
		cd.append(pHC[ch]);
	}
	int add=cd.length()%8;
	cd.append(8-add,'0');
	cout<<"Huffman ±àÂë:"<<cd<<"\n³¤¶ÈÎª"<<cd.length()<<endl;
	char* pBuffer=new char[size];
	if(! pBuffer){
		cout<<"FAIL!"<<endl;
		return false;
	}
	int pos=0;
	while(cd.length()>=8){
	pBuffer[pos]=Str2byte(cd);
	pos++;
	cd.erase(0,8);		
	}
	if(!pBuffer){
		return false;
	}
	Head sHead;
	InitHead(pFilename,sHead,add);
	WriteFile(pFilename,sHead,pBuffer,size);
	b=sizeof(sHead)+size;
	fclose(in1);
	fclose(in2);
	return true;
}
