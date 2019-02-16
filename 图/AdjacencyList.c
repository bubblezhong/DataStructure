//邻接表，数组与链表相结合
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
  printf("请输入顶点数和边数\n");
  scanf("%d %d", &G -> numVertexes, &G -> numEdges);
  fflush(stdin);
  for (i = 0; i < G -> numVertexes; i++) {
    printf("请输入%d个元素\n", i);
    scanf("%c", &G -> adjList[i].data);   //输入顶点信息
    fflush(stdin);
    G -> adjList[i].firstNode = NULL;    //边表置空
  }
  printf("一共几条边： %d\n", G -> numEdges);
  for (k = 0; k < G -> numEdges; k++) {
    printf("请输入边的顶点序号\n");
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
//邻接表深度优先算法
void DFS(GraphAdjList G, int i) {
  EdgeNode* p;
  p = G.adjList[i].firstNode;
  printf("第%d个元素是:%c\n", i, G.adjList[i].data);
  visited[i] = 1;
  while (p) {
    if (!visited[p -> adjvex])
      DFS(G, p -> adjvex);
    p = p -> next;
  }
}
//邻接表的深度遍历操作
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
