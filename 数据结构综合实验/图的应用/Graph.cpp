#define MAX_SIZE 20
#include "Graph.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

bool Graph::InitGraph(){
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++)
		matrix[i][j]=0;
	}
	//vex_array[i]={i,NULL,NULL}; 
	for(int i=0;i<20;i++){
		vex_array[i].num=0;
		strcpy_s(vex_array[i].name,"null");
		//cout<<vex_array[i].name<<endl;
		strcpy_s(vex_array[i].desc,"null");
	}
	for(int i=0;i<190;i++){
		edge_array[i].vex1=-1;
		edge_array[i].vex2=-1;
		edge_array[i].weight=-1;
	}
	return true;
}
bool Graph::Insert(Vex add){
	if(vexnum==MAX_SIZE){
		cout<<"SIZE ERROR!"<<endl;
		return false;
	}
	vex_array[vexnum++]=add;
	return true;
} 
bool Graph::InsertEdge(Edge add){
	if(add.vex1<0||add.vex1>vexnum||add.vex2<0||add.vex2>vexnum){
		cout<<"下标越界！"<<endl; 
		return false;
	}
	matrix[add.vex1][add.vex2]=add.weight;
	matrix[add.vex2][add.vex1]=add.weight;
	return true;
}
void Graph::CreatGraph(){
	InitGraph();
	cout<<"输入Vex文件路径:"<<endl;
	string Vex;Vex="./Vex.txt";
	cout<<Vex<<endl;
	//cin>>Vex;
	cout<<"输入Edge文件路径:"<<endl;
	string Edge;Edge="./Edge.txt"; 
	cout<<Edge<<endl;
	//cin>>Edge;
	
	
	ifstream Vex_in(Vex.c_str(),std::ios::binary);
	ifstream Edge_in(Edge.c_str(),std::ios::binary);
	//注意此处的“filename.c_str()”，
	//（Because the constructor for an ifstream takes a const char*, not a string pre-C++11.） 	
	//读入Vex文件： 
	if (Vex_in.is_open()&&Edge_in.is_open()){
		string s1,s2;
		char ch;
		int cnt=0;
		getline(Vex_in,s1);
		//cout<<s1<<endl;
		vexnum=atoi(s1.data());
		//cout<<"vexnum="<<vexnum<<endl;
		while(!Vex_in.eof()){
			Vex_in >> s1;
			vex_array[cnt].num=atoi(s1.c_str());
			//cout<<vex_array[cnt].num<<endl;
			Vex_in>>s1;                                    //此处不能用getline读取，因为会将换行符一并读入，导致输出错误
			strcpy_s(vex_array[cnt].name,s1.c_str());
			//若name,desc 为string如何处理？ 
			Vex_in>>s1;                                     //这里也是一样
			strcpy_s(vex_array[cnt].desc,s1.c_str());
			//cout<<vex_array[cnt].desc<<"  ";
			cnt++;
		}
		//读入Edge文件：
		cnt=0; 
		while(!Edge_in.eof()){      //注意文件最后一行不能换行 
			s2=Edge_in.get();
			edge_array[cnt].vex1=atoi(s2.c_str());
			//cout<<edge_array[cnt].vex1<<endl;
			ch=Edge_in.get();
			while(ch==' '){		//注意' '与tab区别
				//cout<<"blank!"<<endl;
				ch=Edge_in.get();
			}
			s2=ch;
			edge_array[cnt].vex2=atoi(s2.c_str());
			//cout<<edge_array[cnt].vex2<<endl;
			ch=Edge_in.get();
			while(ch==' '){
				ch=Edge_in.get();
			}
			s2=ch;
			getline(Edge_in,s1);
			s2.append(s1);
			edge_array[cnt].weight=atoi(s2.c_str());
			//cout<<"edge_array[cnt].weight="<<edge_array[cnt].weight<<endl;
			cnt++;
		}
		
    	Edge_in.close();
    	Vex_in.close();
		//建图
		for(int i=0;i<cnt;i++){
			InsertEdge(edge_array[i]);
		}

    }
    else cout << "Unable to open file"<<endl;
}

Vex Graph::Get_Vex(int v){
	return vex_array[v];
}
bool Graph::Is_neighbor(int i,int j){
	if(matrix[i][j]!=0)return true;
	else return false;
}
void Graph::Find_Edge(int v){
	if(v>=0&&v<Get_vexnum()){
		cout<<Get_Vex(v).name<<endl;
		for(int i=0;i<190;i++){
			//cout<<edge_array[i].weight<<endl;
			if(edge_array[i].vex1==v||edge_array[i].vex2==v){	
				int des=edge_array[i].vex1==v?edge_array[i].vex2:edge_array[i].vex1;
				cout<<"-> "<<Get_Vex(des).name<<"路程:"<<edge_array[i].weight<<endl;
			}
		}
	}
	else cout<<"输入编号不存在！"<<endl;
}

void DFS(Graph& g,int v,bool visited[],int& index,Path*& plist,int& cnt){
	visited[v]=true;
	plist->vexs[index++]=v;
	if(index==g.Get_vexnum()){
		cout<<"路线"<<cnt<<" : ";
		for(int i=0;i<g.Get_vexnum();i++){
			cout<<g.Get_Vex(plist->vexs[i]).name<<"  ";
		}
		cnt++;
		cout<<endl;
	}
	else{
		for(int i=0;i<20;i++){
			if(g.Is_neighbor(i,v)&&!visited[i]){
				DFS(g,i,visited,index,plist,cnt);
				visited[i]=false;
				index--;
			}
		}
	}
	
}
void MDFS(Graph& g,int v,Path*& plist){
	int index=0,cnt=1;
	bool visited[20]={false};
	DFS(g,v,visited,index,plist,cnt);
	cout<<endl;
}















