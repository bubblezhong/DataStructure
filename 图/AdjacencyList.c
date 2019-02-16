//�ڽӱ���������������
#include <stdio.h>
#define MAXVEX 100
typedef char VertextType;
typedef int EdgeType;
int visited[MAXVEX];
typedef struct EdgeNode {
  int adjvex;
  //EdgeType weight;
  struct EdgeNode* next;
} EdgeNode;
typedef struct VertexNode {
  VertextType data;
  EdgeNode* firstNode;
}VertexNode, AdjList[MAXVEX];
typedef struct {
  AdjList adjList;
  int numVertexes, numEdges;
}GraphAdjList;
CreateALGraph(GraphAdjList* G) {
  int j, k, i;
  EdgeNode* e;
  printf("�����붥�����ͱ���\n");
  scanf("%d %d", &G -> numVertexes, &G -> numEdges);
  fflush(stdin);
  for (i = 0; i < G -> numVertexes; i++) {
    printf("������%d��Ԫ��\n", i);
    scanf("%c", &G -> adjList[i].data);   //���붥����Ϣ
    fflush(stdin);
    G -> adjList[i].firstNode = NULL;    //�߱��ÿ�
  }
  printf("һ�������ߣ� %d\n", G -> numEdges);
  for (k = 0; k < G -> numEdges; k++) {
    printf("������ߵĶ������\n");
    scanf("%d, %d", &i, &j);
    fflush(stdin);
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e -> adjvex = j;
    e ->next = G -> adjList[i].firstNode;
    G -> adjList[i].firstNode = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e -> adjvex = i;
    e ->next = G -> adjList[j].firstNode;
    G -> adjList[j].firstNode = e;
  }
}
//�ڽӱ���������㷨
void DFS(GraphAdjList G, int i) {
  EdgeNode* p;
  p = G.adjList[i].firstNode;
  printf("��%d��Ԫ����:%c\n", i, G.adjList[i].data);
  visited[i] = 1;
  while (p) {
    if (!visited[p -> adjvex])
      DFS(G, p -> adjvex);
    p = p -> next;
  }
}
//�ڽӱ����ȱ�������
void DFSTraverse (GraphAdjList G) {
  int i;
  for (i = 0; i < G.numVertexes; i++)
    visited[i] = 0;
  for (i = 0; i < G.numVertexes; i++)
    if (!visited[i])
      DFS(G, i);
}
int main() {
  GraphAdjList G;
  CreateALGraph (&G);
  DFSTraverse (G);
  return 0;
}
