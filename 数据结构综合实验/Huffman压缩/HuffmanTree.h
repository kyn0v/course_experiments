#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include <string>
using namespace std;

struct HTNode{
	int weight;
	int parent;
	int lchild;
	int rchild;
	bool flag;
	int visited;
};
typedef HTNode* HuffmanTree;
typedef string* Huffmancode;

int Select(HuffmanTree pHT,int Size);

HuffmanTree Create(int* weight);

int HuffmanCoding(Huffmancode& pHC,HuffmanTree& pHT);

void TestHC(int root,HuffmanTree pHT,Huffmancode pHC);



#endif