#include <stdio.h>
#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX]; //���ڴ洢���·���±������Pathac[i] = 3;��ʾi��ǰ����3
typedef int ShortPathTable[MAXVEX];  //���ڴ洢���������·����Ȩֵ֮��
typedef char VertextType;
typedef int EdgeType;
typedef int Boolean;
typedef struct {
  VertextType vex[MAXVEX];              //�����
  EdgeType arc[MAXVEX][MAXVEX];         //�ڽӾ���
  int numVertexes, numEdges;           //ͼ�е�ǰ�Ķ������ͱ���
} MGraph;
void CreateMGraph (MGraph *G) {  //G������:�����±�ע
  int i, j, k, quan;
  printf("����������Ͷ�����\n");
  G -> numEdges = 5;
  G -> numVertexes = 4;
  //scanf("%d %d",&G -> numEdges, &G -> numVertexes);
  //���붥����Ϣ�������������ʼ������
  //printf("�����붥������\n");
  fflush(stdin);
  for ( i = 0; i < G -> numVertexes; i ++ ) {
     G -> vex[i] = i;
    //printf("�������%d������", i);
   // scanf("%c", &G -> vex[i]);
    fflush(stdin);
  }

  //��ʼ������Ϣ
  for ( i = 0; i < G -> numVertexes; i ++ )
    for( j = 0; j < G -> numVertexes; j ++ )
      G -> arc[i][j] = INFINITY;
  //����ߣ������ڽӾ���
  //for (k = 0; k < G -> numEdges; k++) {
    //printf("������ߵ��±�i, j,�Լ�Ȩ��k\n");
  //  scanf("%d %d %d", &i, &j, &quan);
  //  G -> arc[i][j] = k;
   // G -> arc[j][i] = G -> arc[i][j];
 // }
  G -> arc[0][1] = 6;G -> arc[0][2] = 8;G -> arc[3][1] = 16;G -> arc[2][1] = 9;G -> arc[2][3] = 5;
  G -> arc[1][0] = 6;G -> arc[2][0] = 8;G -> arc[1][3] = 16;G -> arc[1][2] = 9;G -> arc[3][2] = 5;
//  for ( i = 0; i < G -> numVertexes; i ++ )
 //   for( j = 0; j < G -> numVertexes; j ++ )
  //    printf("��(%d,%d)��Ԫ��%d\n",i,j, G->arc[i][j]);

}
//Dijkstra�㷨�����·��
void ShortPath_Dijkstra (MGraph G, Patharc *p, ShortPathTable *D) {
  int i, v, w, k, min;
  int final[MAXVEX], tempData[MAXVEX];   //finial[i] = 1��ʾ����ö���0��i֮���·��
  for (i = 0; i < G.numVertexes; i++) {
    final[i] = 0;
    (*D)[i] = G.arc[0][i];
    (*p)[i] = 0;
  }
  (*D)[0] = 0;
  final[0] = 1;
  //��ʼ��ѭ��,ÿѭ����õ�0�����㵽��i����������·��
  for (i = 1; i < G.numVertexes; i++) {
    min = INFINITY;
    for (v = 0; v < G.numVertexes; v++ ) {
      if (!final[v] && (*D)[v] < min) {
        min = (*D)[v];
        k = v;
      }
    }
    final[k] = 1;
    for (v = 0; v < G.numVertexes; v++) {
      if (!final[v] && (min + G.arc[k][v] < (*D)[v]) ) {
        (*D)[v] = min + G.arc[k][v];
        (*p)[v] = k;
      }
    }
  }
  //��ӡ���
  printf("��ӡ���\n");
  printf("%d\n", (*p)[0]);
  for (v = 0; v < G.numVertexes; v++) {
    printf("����Ϊ���·��%d\n", (*p)[v]);
   // tempData[v] = G.vex[(*p)[v]]
  }
}
showData (MGraph G, Patharc *p, int x) {
  int temp;
  printf("���·��%d", G.vex[x]);
  temp = (*p)[x];
  printf("temp:%d\n")
  if (temp != 0) {
    showData(G, p, temp);
  } else {
    printf("%d", G.vex[0]);
  }
}
int main() {
  //�������������Աȡ�����Ҫ�����ڴ棬���Բ���Ҫ��MGraph*ָ�롣
  MGraph G;
  CreateMGraph(&G);
  Patharc p;
  ShortPathTable D;
  ShortPath_Dijkstra(G, p, D);
  showData(G, p, G.vex[G.numVertexes - 1]);
  return 0;
}




















