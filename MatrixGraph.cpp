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
	int Nv;//������
	int Ne;//����
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];//��Ŷ��������
};

typedef PtrToGnode MGraph;//�������ڽӾ���洢��ͼ����
						  
//���涨��ߵ����ݽṹ
typedef struct Enode *PtrToEnode;
struct Enode
{
	Vertex V1, V2;//һ�������㣬һ���յ�
	WeightType Weight;
};
typedef PtrToEnode Edge;

MGraph CreateGraph(int vertexnum);
void InsertEdge(MGraph Graph, Edge E);

int main()
{	
	return 0;
}

//����һ����VertexNum�����㵫��û�бߵ�ͼ
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

//Ȼ����MGraph���в����

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = E->Weight;
	//���������ͼ������˳��ҲҪ�����
	Graph->G[E->V2][E->V1] = E->Weight;
}
//����������ͼ
MGraph BulidGraph()
{
	MGraph Graph;
	int Nv;

	cin >> Nv;
	Graph = CreateGraph(Nv);
	cin >> Graph->Ne;//����������һ������
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
	//һ�ֶ��������ݵ����
	for (Vertex V = 0; V < Graph->Nv; V++)
	{
		cin >> Graph->Data[V];
	}
	return Graph;
}