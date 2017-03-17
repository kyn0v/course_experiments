#ifndef COMPRESS_H
#define COMPRESS_H
#include "HuffmanTree.h"

struct Head{
	char type[4];
	int length;
	int weight[256];
	int add_0;
};

bool InitHead(const char* pFilename,Head& sHead);
bool WriteFile(const char* pFilename,const Head sHead,const char* pBuffer,const int size);
bool Compress(const char* pFilename,int& a,int& b);
char Str2byte(const char* pBinStr);

#endif