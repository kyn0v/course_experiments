#include <iostream>
#include "Graph.h"
#include "Tourism.h"
using namespace std;


int main(int argc, char** argv) {
	Graph g;Path* plist=new Path[20];
	cout<<"1.��������ͼ\n2.��ѯ������Ϣ\n3.���ξ��㵼��\n4.�������·��\n5.�����·�滮\n0.�˳�"<<endl;
	cout<<"������:"<<endl;
	int input;
	cin>>input;
	while(input!=0){
		switch(input){
			case 1:
				g.CreatGraph();
				cout<<"�����ѡ�����"<<endl;
				break;		
			case 2:
				Get_SpotInfo(g);
				cout<<"�����ѡ�����"<<endl;
				break;
			case 3:
				Travel(g,plist);
				cout<<"�����ѡ�����"<<endl;
				break;
			case 4:
				cout<<"�����"<<endl;
				cout<<"�����ѡ�����"<<endl;
				break;
			case 5:
				cout<<"�����"<<endl;
				cout<<"�����ѡ�����"<<endl;
				break;
			default:
				cout<<"�������,�����ѡ�����"<<endl;
				break;
		}
		cout<<"1.��������ͼ\n2.��ѯ������Ϣ\n3.���ξ��㵼��\n4.�������·��\n5.�����·�滮\n0.�˳�"<<endl;
		cin>>input;
	}
	delete []plist;
	//int x;
	//cin>>x;
	return 0;
	
}
