#include<iostream>
#include<stdlib.h>

#define MaxVertexNum 100

using namespace std;

typedef int WeightType;
typedef int DataType;
typedef int Vertex;

typedef struct Gnode *PtrToGnode;
struct Gnode
{
	int Nv;//顶点数
	int Ne;//边数
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];//存放顶点的数据
};

typedef PtrToGnode MGraph;//代表以邻接矩阵存储的图类型
						  
//下面定义边的数据结构
typedef struct Enode *PtrToEnode;
struct Enode
{
	Vertex V1, V2;//一个出发点，一个终点
	WeightType Weight;
};
typedef PtrToEnode Edge;

MGraph CreateGraph(int vertexnum);
void InsertEdge(MGraph Graph, Edge E);

int main()
{	
	return 0;
}

//创建一个有VertexNum个顶点但是没有边的图
MGraph CreateGraph(int vertexnum)
{
	MGraph Graph;
	Vertex V, W;

	Graph = (MGraph)malloc(sizeof(struct Gnode));
	Graph->Nv = vertexnum;
	Graph->Ne = 0;

	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = 0;

	return Graph;
}

//然后向MGraph当中插入边

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = E->Weight;
	//如果是无向图，交换顺序也要插入边
	Graph->G[E->V2][E->V1] = E->Weight;
}
//输入完整的图
MGraph BulidGraph()
{
	MGraph Graph;
	int Nv;

	cin >> Nv;
	Graph = CreateGraph(Nv);
	cin >> Graph->Ne;//可以少声明一个变量
	if (Graph->Ne != 0)
	{
		Edge E;
		E = (Edge)malloc(sizeof(struct Enode));
		for (int i = 0; i < Graph->Ne; i++)
		{
			cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(Graph,E);
		}
	}
	//一种顶点有数据的情况
	for (Vertex V = 0; V < Graph->Nv; V++)
	{
		cin >> Graph->Data[V];
	}
	return Graph;
}