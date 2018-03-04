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
	Vertex AdjV;//�洢�ڽӵ��±�
	WeightType Weight;//�洢��Ȩ��
	PtrToAdjVNode Next;
};

typedef struct Gnode *PtrToGNode;

typedef struct Vnode
{
	PtrToAdjVNode FisrtEdge;
	DataType data;
}AdjList[MaxVertexNum];
//AdjList ���ڽӱ����ͣ���һ���ṹ�����飬Ҳ����˵�������G��һ���ṹ�����飩ÿһ��Ԫ����һ��Vnode
//������ŵ��ǵ�һ���ڵ�

typedef struct Enode *PtrToEnode;
struct Enode
{
	Vertex V1, V2;//һ�������㣬һ���յ�
	WeightType Weight;
};
typedef PtrToEnode Edge;

struct Gnode
{
	int Nv;
	int Ne;
	AdjList G;//�ڽӱ�
};

typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph, Edge E);

int main()
{

	return 0;
}

//���Ƚ������������ж��㵫��û�бߵ�ͼ��
LGraph CreateGraph(int VertexNum)
{
	LGraph Graph;
	Vertex V, W;

	Graph = (LGraph)malloc(sizeof(struct Gnode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FisrtEdge = NULL;//��ζ��ֻ�е��û�б�

	return Graph;
}

//Ȼ����LGraph�������ߣ�
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;//��������
	NewNode->Weight = E->Weight;//����Ȩ��

	//��V2����V1�ı�ͷ
	NewNode->Next = Graph->G[E->V1].FisrtEdge;
	Graph->G[E->V1].FisrtEdge = NewNode;

	//���������ͼ�Ĳ��룺
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;//��������
	NewNode->Weight = E->Weight;//����Ȩ��

	//��V1����V2�ı�ͷ
	NewNode->Next = Graph->G[E->V2].FisrtEdge;
	Graph->G[E->V2].FisrtEdge = NewNode;
}

//����������graph
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