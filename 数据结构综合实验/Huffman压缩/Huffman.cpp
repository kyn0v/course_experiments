#include "HuffmanTree.h"
#include <iostream>
using namespace std;
int Select(HuffmanTree pHT,int size){
	int minValue=0x7FFFFFFF;
	int min=0;
	for(int i=0;i<=size;i++){
		if(pHT[i].parent==0&&pHT[i].weight<minValue&&pHT[i].flag==true){
			minValue=pHT[i].weight;
			min=i;
		}
	}
	return min;
}
HuffmanTree Create(int* weight){
	HuffmanTree pHT=new HTNode[512];
	for(int i=0;i<512;i++){
		pHT[i].weight=0;
		pHT[i].parent=0;
		pHT[i].lchild=0;
		pHT[i].rchild=0;
		pHT[i].flag=true;
	}
	for(int i=0;i<256;i++){
		pHT[i].weight=weight[i];
	}
	for(int i=0;i<255;i++){
		int a=Select(pHT,255+i);
		pHT[a].flag=false;
		pHT[a].parent=256+i;
		pHT[256+i].lchild=a;
		pHT[256+i].weight=pHT[a].weight;
		a=Select(pHT,255+i);
		pHT[a].flag=false;
		pHT[a].parent=256+i;
		pHT[256+i].rchild=a;
		pHT[256+i].weight=pHT[a].weight+pHT[256+i].weight;
		pHT[256+i].flag=true;
	}
	return pHT;
}


int HuffmanCoding(Huffmancode& pHC,HuffmanTree& pHT){
	string cd(256,'0') ;
	int cdlen=0;

	for(int i=0;i<511;i++){
		pHT[i].visited=0;
	}
	int p=510;
	while(p!=0){
		if(pHT[p].visited==0){
			pHT[p].visited=1;
			if(pHT[p].lchild!=0){
				p=pHT[p].lchild;
				cd[cdlen]='0';
				cdlen++;
			}
			else if(pHT[p].rchild==0){
				pHC[p].assign(cd,0,cdlen);
			}
		}
		else if(pHT[p].visited==1){
			pHT[p].visited=2;
			if(pHT[p].rchild!=0){
				p=pHT[p].rchild;
				cd[cdlen++]='1';
			}
		}
		else {
			pHT[p].visited=0;
			p=pHT[p].parent;
			--cdlen;
		}
	}
	return 0;
}


void TestHC(int root,HuffmanTree pHT,Huffmancode pHC){
	if(pHT[root].lchild==0&&pHT[root].rchild==0&&pHT[root].weight!=0){
		cout<<root<<"->"<<pHC[root]<<endl;
	}
	if(pHT[root].lchild){
		TestHC(pHT[root].lchild,pHT,pHC);
	}
	if(pHT[root].rchild){
		TestHC(pHT[root].rchild,pHT,pHC);
	}
}
