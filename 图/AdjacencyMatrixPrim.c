//�ڽӾ�������ݽṹ�Լ�������������ȣ���϶���
#include <stdio.h>
#define MAXVEX 100
#define INFINITY 65535
typedef char VertextType;
typedef int EdgeType;
typedef int Boolean;
Boolean visited[MAXVEX];
//�ڽӾ�������ݽṹ
typedef struct {
  VertextType vex[MAXVEX];              //�����
  EdgeType arc[MAXVEX][MAXVEX];         //�ڽӾ���
  int numVertexes, numEdges;           //ͼ�е�ǰ�Ķ������ͱ���
} MGraph;
void CreateMGraph (MGraph *G) {
  int i, j, k, quan;
  printf("����������Ͷ�����\n");
  scanf("%d %d",&G -> numEdges, &G -> numVertexes);
  //���붥����Ϣ�������������ʼ������
  //printf("�����붥������\n");
  fflush(stdin);
  for ( i = 0; i < G -> numVertexes; i ++ ) {
    printf("�������%d������", i);
    scanf("%c", &G -> vex[i]);
    fflush(stdin);
  }

  //��ʼ������Ϣ
  for ( i = 0; i < G -> numVertexes; i ++ )
    for( j = 0; j < G -> numVertexes; j ++ ) {
       if (i == j) {
         G -> arc[i][j] = 0;
       } else {
         G -> arc[i][j] = INFINITY;
       }
    }
  //����ߣ������ڽӾ���
  for (k = 0; k < G -> numEdges; k++) {
    printf("������ߵ��±�i, j,�Լ�Ȩ��k\n");
    scanf("%d %d %d", &i, &j, &quan);
    G -> arc[i][j] = quan;
    G -> arc[j][i] = G -> arc[i][j];
    printf("��%d��%d,quan��%d\n", k, quan, G -> arc[j][i]);
  }
}
//prim�㷨������С��
MiniSpanTree_Prim (MGraph G) {
  int i, j, k, min;
  int adjvex[MAXVEX];
  int lowcost[MAXVEX];
  //��ʼ����һ��ȨֵΪ0��ֵΪ0�������±�Ķ����Ѿ�����������
  lowcost[0] = 0;
  adjvex[0] = 0;
  for (i = 1; i < G.numVertexes; i++ ) {
    lowcost[i] = G.arc[0][i];
    adjvex[i] = 0;
  }
  for (i = 1; i < G.numVertexes; i++) {
    min = INFINITY; //��ʼ����СȨֵ
    j = 1;
    for (j = 1; j < G.numVertexes; j++) {
       if (lowcost[j] < min && lowcost[j] != 0) {
         min = lowcost[j];
         k = j;
       }
    }
    printf("��%d��·����(%d, %d)", i, adjvex[k], k);
    lowcost[k] = 0;   //����ǰ�����Ȩֵ����Ϊ0���ʾ�˶����Ѿ��������
    for (j = 1; j < G.numVertexes; j++) {
        if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
            lowcost[j] = G.arc[k][j];
            adjvex[j] = k;         //���±�Ϊk�Ķ������adjvex
        }
    }
  }
}
int main() {
  //�������������Աȡ�����Ҫ�����ڴ棬���Բ���Ҫ��MGraph*ָ�롣
  MGraph G;
  CreateMGraph(&G);
  //BFSTraverse(G);
  MiniSpanTree_Prim(G);
  return 0;
}

