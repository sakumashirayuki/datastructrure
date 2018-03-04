#include<iostream>
#include<stdlib.h>

#define MaxVertexNum 100

using namespace std;

typedef int DataType;
typedef int Vertex;
typedef int WeightType;

typedef struct AdjVNode *PtrToAdjVNode;

struct AdjVNode
{
	Vertex AdjV;//存储邻接点下标
	WeightType Weight;//存储边权重
	PtrToAdjVNode Next;
};

typedef struct Gnode *PtrToGNode;

typedef struct Vnode
{
	PtrToAdjVNode FisrtEdge;
	DataType data;
}AdjList[MaxVertexNum];
//AdjList 是邻接表类型（是一个结构体数组，也就是说，下面的G是一个结构体数组）每一个元素是一个Vnode
//这里面放的是第一个节点

typedef struct Enode *PtrToEnode;
struct Enode
{
	Vertex V1, V2;//一个出发点，一个终点
	WeightType Weight;
};
typedef PtrToEnode Edge;

struct Gnode
{
	int Nv;
	int Ne;
	AdjList G;//邻接表
};

typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph, Edge E);

int main()
{

	return 0;
}

//首先建立包含了所有顶点但是没有边的图：
LGraph CreateGraph(int VertexNum)
{
	LGraph Graph;
	Vertex V, W;

	Graph = (LGraph)malloc(sizeof(struct Gnode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FisrtEdge = NULL;//意味着只有点而没有边

	return Graph;
}

//然后向LGraph里面插入边：
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;//存入名字
	NewNode->Weight = E->Weight;//存入权重

	//将V2插入V1的表头
	NewNode->Next = Graph->G[E->V1].FisrtEdge;
	Graph->G[E->V1].FisrtEdge = NewNode;

	//如果是无向图的插入：
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;//存入名字
	NewNode->Weight = E->Weight;//存入权重

	//将V1插入V2的表头
	NewNode->Next = Graph->G[E->V2].FisrtEdge;
	Graph->G[E->V2].FisrtEdge = NewNode;
}

//建立完整的graph
LGraph BuildGraph()
{
	LGraph Graph;
	int Nv;

	cin >> Nv;
	Graph = CreateGraph(Nv);
	cin >> Graph->Ne;
	if (Graph->Ne != 0)
	{
		Edge E;
		E = (Edge)malloc(sizeof(struct Enode));
		for (int i = 0; i < Graph->Ne; i++)
		{
			cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(Graph, E);
		}
		for (Vertex V = 0; V < Graph->Nv; V++)
		{
			cin >> Graph->G[V].data;
		}
	}
	return Graph;
}