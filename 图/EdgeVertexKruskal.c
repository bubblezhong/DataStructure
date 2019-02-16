#include <stdio.h>
#define MAXVEX 100
typedef char VertextType;
typedef struct {
  int begin;
  int end;
  int weight;
} Edge;
typedef struct {
  VertextType vex[MAXVEX];
  Edge edges[MAXVEX];
  int numVertexes, numEdges;
} EdgeVertex;
//const 常量 , 让指针不可变化，void表示 不指向任何类型的指针
int compInc(const void *a, const void *b)
{
     return ((Edge *)a) -> weight - ((Edge *)b) -> weight;
}
InitEdgeVertex (EdgeVertex* G) {
   int i;
   char temp;
   Edge* p;
   printf("请输入顶点数和边数\n");
   scanf("%d %d", &G -> numVertexes, &G -> numEdges);
   fflush(stdin);
   for (i = 0; i < G -> numVertexes; i++) {
     printf("请输入第%d个顶点的值\n", i);
     scanf("%c", &temp);
     fflush(stdin);
     G -> vex[i] = temp;
    // printf("第%d个顶点的值%c\n", i, G -> vex[i]);
   }
   for (i = 0; i < G -> numEdges; i++) {
     printf("请输入第%d条边的下标以及权重\n", i);
     scanf("%d %d %d", &G -> edges[i].begin, &G -> edges[i].end, &G -> edges[i].weight);
   }
   //for (i = 0; i < G -> numEdges; i++) {
    // printf("第%d条边的下标%d,%d以及权重%d\n", i, G -> edges[i].begin, G -> edges[i].end, G -> edges[i].weight);
   //}
}
//Kruskal算法
int Find (int *parent, int f ) {
   while (parent[f] > 0) {
     f = parent[f];
   }
   return f;
}
void MiniSpanTree_Krukal (EdgeVertex G) {
    int i, n, m;
  int parent[MAXVEX];
  for (i = 0; i < G.numVertexes; i++)
    parent[i] = 0;
  for (i = 0; i < G.numEdges; i++) {
    n = Find(parent, G.edges[i].begin);
    m = Find(parent, G.edges[i].end);
    if (m != n) {
        parent[n] = m;
        printf("(%d, %d)权值%d\n", G.edges[i].begin, G.edges[i].end, G.edges[i].weight);
    }
  }
}
void main() {
  int n;
  EdgeVertex G;
  InitEdgeVertex(&G);
  //采用c语言自带的函数对边集数组进行排序
   qsort (G.edges, G.numEdges, sizeof(Edge), compInc);
   for (n = 0; n < G.numEdges; n++) {
     printf("排序后第%d条边的下标%d,%d以及权重%d\n", n, G.edges[n].begin, G.edges[n].end, G.edges[n].weight);
   }
   MiniSpanTree_Krukal(G);
}















