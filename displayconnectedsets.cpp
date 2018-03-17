#include<iostream>
#include<stdlib.h>
#include<string.h>

#define MaxVertexNum 10
#define true 1
#define ERROR -1

using namespace std;

typedef int WeightType;
typedef int DataType;
typedef int Vertex;
typedef int ElementType;

typedef struct Gnode *PtrToGnode;
struct Gnode
{
	int Nv;//������
	int Ne;//����
	WeightType G[MaxVertexNum][MaxVertexNum];
	//DataType Data[MaxVertexNum];//��Ŷ��������
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

struct QNode
{
	ElementType Data[MaxVertexNum];
	int rear;
	int front;
};
typedef struct QNode *Queue;

int visited[MaxVertexNum] = {0};

MGraph CreateGraph(int vertexnum);
void InsertEdge(MGraph Graph, Edge E);
MGraph BuildGraph();
void DFS(Vertex V, MGraph G);
void ListComponentsDFS(MGraph G);
void BFS(Vertex V, MGraph G,Queue Q);
void Enqueue(Queue PtrQ, ElementType item);
ElementType Dequeue(Queue PtrQ);
Queue CreateQueue();
bool IsEmpty(Queue PtrQ);
void ListComponentsBFS(MGraph G);


int main()
{
	MGraph G;
	G = BuildGraph();
	ListComponentsDFS(G);
	memset(visited, 0, sizeof(visited));
	ListComponentsBFS(G);

	system("pause");
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
MGraph BuildGraph()
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
			cin >> E->V1 >> E->V2;
			E->Weight = 1;
			InsertEdge(Graph, E);
		}
	}
	//һ�ֶ��������ݵ����
	/*
	for (Vertex V = 0; V < Graph->Nv; V++)
	{
		cin >> Graph->Data[V];
	}
	*/
	return Graph;
}

//DFS�����㷨
void DFS(Vertex V,MGraph G)
{
	visited[V] = true;
	cout << V << " ";

	//������V���ӵ�ÿһ�����
	for (Vertex W=0;W<G->Nv;W++)
	{
		if (G->G[V][W] == 1)
		{
			if (!visited[W])
				DFS(W, G);
		}
		else
		{
			continue;
		}
	}
}
//BFS�����㷨
void BFS(Vertex V, MGraph G,Queue Q)
{
	visited[V] = true;
	cout << V << " ";
	Enqueue(Q,V);
	while (!IsEmpty(Q))
	{
		V = Dequeue(Q);
		//������V���ӵ�ÿ�����
		for (Vertex W = 0; W < G->Nv; W++)
		{
			if (G->G[V][W] == 1)
			{
				if (!visited[W])
				{
					visited[W] = true;
					cout << W << " ";
					Enqueue(Q,W);
				}
			}
			else continue;
			
		}
	}
}

void ListComponentsDFS(MGraph G)
{
	
	for (Vertex V=0;V<G->Nv;V++)
	{
		if (!visited[V])
		{
			cout << "{ ";
			DFS(V, G);
			cout << "}" << endl;
		}
	}
	
}

void ListComponentsBFS(MGraph G)
{
	Queue Q;
	Q = CreateQueue();
	for (Vertex V = 0; V<G->Nv; V++)
	{
		if (!visited[V])
		{
			cout << "{ ";
			BFS(V, G,Q);
			cout << "}" << endl;
		}
	}

}

//�����
void Enqueue(Queue PtrQ, ElementType item)
{
	if ((PtrQ->rear + 1) % MaxVertexNum == PtrQ->front)
	{
		cout << "the queue is full" << endl;
		return;
	}
	PtrQ->rear = (PtrQ->rear + 1) % MaxVertexNum;
	PtrQ->Data[PtrQ->rear] = item;
}

ElementType Dequeue(Queue PtrQ)
{
	if (PtrQ->front == PtrQ->rear)
	{
		cout << "the queue is empty" << endl;
		return ERROR;
	}
	else 
	{
		PtrQ->front = (PtrQ->front + 1) % MaxVertexNum;
		return PtrQ->Data[PtrQ->front];
	}
}

//���ɿն���
Queue CreateQueue()
{
	Queue NewQ= (Queue)malloc(sizeof(struct QNode));
	for (int i = 0; i < MaxVertexNum; i++)
	{
		NewQ->Data[i] = 0;
	}
	NewQ->front = -1;
	NewQ->rear = -1;

	return NewQ;
}

bool IsEmpty(Queue PtrQ)
{
	if (PtrQ->front == PtrQ->rear)
	{
		return 1;
	}
	else return 0;
}