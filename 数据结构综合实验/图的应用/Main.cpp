#include <iostream>
#include "Graph.h"
#include "Tourism.h"
using namespace std;


int main(int argc, char** argv) {
	Graph g;Path* plist=new Path[20];
	cout<<"1.创建景点图\n2.查询景点信息\n3.旅游景点导航\n4.搜索最短路径\n5.铺设电路规划\n0.退出"<<endl;
	cout<<"请输入:"<<endl;
	int input;
	cin>>input;
	while(input!=0){
		switch(input){
			case 1:
				g.CreatGraph();
				cout<<"请继续选择操作"<<endl;
				break;		
			case 2:
				Get_SpotInfo(g);
				cout<<"请继续选择操作"<<endl;
				break;
			case 3:
				Travel(g,plist);
				cout<<"请继续选择操作"<<endl;
				break;
			case 4:
				cout<<"待完成"<<endl;
				cout<<"请继续选择操作"<<endl;
				break;
			case 5:
				cout<<"待完成"<<endl;
				cout<<"请继续选择操作"<<endl;
				break;
			default:
				cout<<"输入错误,请继续选择操作"<<endl;
				break;
		}
		cout<<"1.创建景点图\n2.查询景点信息\n3.旅游景点导航\n4.搜索最短路径\n5.铺设电路规划\n0.退出"<<endl;
		cin>>input;
	}
	delete []plist;
	//int x;
	//cin>>x;
	return 0;
	
}
