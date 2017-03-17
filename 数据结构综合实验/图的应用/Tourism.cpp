#include "Graph.h"
#include <iostream>
using namespace std;

void Get_SpotInfo(Graph g){
	for(int i=0;i<g.Get_vexnum();i++){
		Vex a=g.Get_Vex(i);
		cout<<"num: "<<a.num<<"   ";
		cout<<"name: "<<a.name<<"   ";
		cout<<"desc: "<<a.desc<<endl;
	}
	cout<<"�����ѯ�ľ����ţ�"<<endl; 
	int v;
	cin>>v;
	Vex get=g.Get_Vex(v);
	cout<<"num:  "<<get.num<<"  ";
	cout<<"name:  "<<get.name<<"  ";
	cout<<"desc:  "<<get.desc<<endl;
	g.Find_Edge(v);
}
void Travel(Graph& g,Path*& plist){
	cout<<"�������뵱ǰλ�ñ��"<<endl;
	int input;
	cin>>input;
	if(input>=0&&input<g.Get_vexnum()){
		MDFS( g,input,plist);
	}
	else cout<<"����λ������"<<endl;
}
