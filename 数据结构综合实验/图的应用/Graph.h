#ifndef GRAPH_H
#define GRAPH_H

struct Vex{    //顶点信息 
	int num;
	char name[20];
	char desc[1024];
};

struct Edge{   //边信息 
	int vex1;
	int vex2;
	int weight;
};

struct Path{
	int vexs[20];
	Path* next;
};

void DFS(int start,bool visit[],int depth,Path*& plist,int size);
class Graph{
	private:
		int vexnum;
		int matrix[20][20];
		Vex vex_array[20];
		Edge edge_array[190]; 
	public:
		//Vex vex_array[20];
		//Edge edge_array[190]; 
		int Get_vexnum(){return vexnum;};
		bool InitGraph();
		bool Insert(Vex add);
		bool InsertEdge(Edge add);
		void CreatGraph();
		Vex Get_Vex(int v);
		void Find_Edge(int v);
		bool Is_neighbor(int i,int j);
};
void DFS(Graph& g,int v,bool visited[],int& index,Path*& plist,int& cnt);
void MDFS(Graph& g,int v,Path*& plist);

#endif


