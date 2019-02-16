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
//const ���� , ��ָ�벻�ɱ仯��void��ʾ ��ָ���κ����͵�ָ��
int compInc(const void *a, const void *b)
{
     return ((Edge *)a) -> weight - ((Edge *)b) -> weight;
}
InitEdgeVertex (EdgeVertex* G) {
   int i;
   char temp;
   Edge* p;
   printf("�����붥�����ͱ���\n");
   scanf("%d %d", &G -> numVertexes, &G -> numEdges);
   fflush(stdin);
   for (i = 0; i < G -> numVertexes; i++) {
     printf("�������%d�������ֵ\n", i);
     scanf("%c", &temp);
     fflush(stdin);
     G -> vex[i] = temp;
    // printf("��%d�������ֵ%c\n", i, G -> vex[i]);
   }
   for (i = 0; i < G -> numEdges; i++) {
     printf("�������%d���ߵ��±��Լ�Ȩ��\n", i);
     scanf("%d %d %d", &G -> edges[i].begin, &G -> edges[i].end, &G -> edges[i].weight);
   }
   //for (i = 0; i < G -> numEdges; i++) {
    // printf("��%d���ߵ��±�%d,%d�Լ�Ȩ��%d\n", i, G -> edges[i].begin, G -> edges[i].end, G -> edges[i].weight);
   //}
}
//Kruskal�㷨
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
        printf("(%d, %d)Ȩֵ%d\n", G.edges[i].begin, G.edges[i].end, G.edges[i].weight);
    }
  }
}
void main() {
  int n;
  EdgeVertex G;
  InitEdgeVertex(&G);
  //����c�����Դ��ĺ����Ա߼������������
   qsort (G.edges, G.numEdges, sizeof(Edge), compInc);
   for (n = 0; n < G.numEdges; n++) {
     printf("������%d���ߵ��±�%d,%d�Լ�Ȩ��%d\n", n, G.edges[n].begin, G.edges[n].end, G.edges[n].weight);
   }
   MiniSpanTree_Krukal(G);
}















