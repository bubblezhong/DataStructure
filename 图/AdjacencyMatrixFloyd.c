#include <stdio.h>
#define MAXVEX 9
#define INFINITY 65535
typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];
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
  //printf("����������Ͷ�����\n");
  G -> numEdges = 5;
  G -> numVertexes = 4;
 // scanf("%d %d",&G -> numEdges, &G -> numVertexes);
  //���붥����Ϣ�������������ʼ������
  //printf("�����붥������\n");
  fflush(stdin);
  for ( i = 0; i < G -> numVertexes; i ++ ) {
     G -> vex[i] = i;
     //printf("�������%d������", i);
     //scanf("%c", &G -> vex[i]);
    fflush(stdin);
  }

  //��ʼ������Ϣ
  for ( i = 0; i < G -> numVertexes; i ++ )
    for( j = 0; j < G -> numVertexes; j ++ )
      G -> arc[i][j] = INFINITY;
  //����ߣ������ڽӾ���
  /*for (k = 0; k < G -> numEdges; k++) {
     printf("������ߵ��±�i, j,�Լ�Ȩ��k\n");
     scanf("%d %d %d", &i, &j, &quan);
     G -> arc[i][j] = quan;
     G -> arc[j][i] = G -> arc[i][j];
   }*/
  G -> arc[0][1] = 6;G -> arc[0][2] = 8;G -> arc[3][1] = 16;G -> arc[2][1] = 9;G -> arc[2][3] = 5;
  G -> arc[1][0] = 6;G -> arc[2][0] = 8;G -> arc[1][3] = 16;G -> arc[1][2] = 9;G -> arc[3][2] = 5;
 }
 //����ͼ�и�����v�����ඥ��w���·��p[v][w]����Ȩ����D[v][w]
ShortPath_Floyd(MGraph G, Pathmatirx *p, ShortPathTable *D) {
  int v, w, k;
  for (v = 0; v < G.numVertexes; v++) {
    for (w = 0; w < G.numVertexes; w++) {
       (*D)[v][w] = G.arc[v][w];
       (*p)[v][w] = w;
    }
  }
  for (k = 0; k < G.numVertexes; k++) {
    for (v = 0; v < G.numVertexes; v++) {
        for (w = 0; w < G.numVertexes; w++) {
          if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) {
            (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
             (*p)[v][w] = (*p)[v][k];
          }
        }
    }
  }
  for (v = 0; v < G.numVertexes; v++) {
        for (w = 0; w < G.numVertexes; w++) {
                printf("Ԫ��%d\n", (*D)[v][w]);
        }
    }
  //��ʾ���·��
  /*for (v = 0; v < G.numVertexes; ++v) {
    for (w = v+1; w < G.numVertexes; w++) {
        printf("v%d-v%d weight %d", v, w, (*D)[v][w]);
        k = p[v][w];
        printf("path: %d", v);
        while(k != w) {
            printf(" -> %d", k);
            k = p[k][w];
        }
        printf("-> %d\n", w);
    }
    printf("\n");
  }*/
}
int main() {
  //�������������Աȡ�����Ҫ�����ڴ棬���Բ���Ҫ��MGraph*ָ�롣
  MGraph G;
  CreateMGraph(&G);
  Pathmatirx p;
  ShortPathTable D;
  ShortPath_Floyd (G, p, D);
  return 0;
}





















