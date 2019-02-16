#include <stdio.h>
typedef char VertextType;
typedef int EdgeType;
typedef int Boolean;
#define MAXVEX 100
#define INFINITY 65535
Boolean visited[MAXVEX];
typedef struct {
  VertextType vex[MAXVEX];              //�����
  EdgeType arc[MAXVEX][MAXVEX];         //�ڽӾ���
  int numVertexes, numEdges;           //ͼ�е�ǰ�Ķ������ͱ���
} MGraph;
void CreateMGraph (MGraph *G) {  //G������:�����±�ע
  int i, j, k;
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
    for( j = 0; j < G -> numVertexes; j ++ )
      G -> arc[i][j] = INFINITY;
  //����ߣ������ڽӾ���
  for (k = 0; k < G -> numEdges; k++) {
    printf("������ߵ��±�i, j\n");
    scanf("%d %d", &i, &j);
    G -> arc[i][j] = 1;
    G -> arc[j][i] = G -> arc[i][j];
  }
}
//�ڽӾ������������㷨
void DFS (MGraph G, int i) {
  int j;
  visited[i] = 1;
  printf("��%d��Ԫ����: %c\n", i, G.vex[i]);
  for (j = 0; j < G.numEdges; j++)
    if (G.arc[i][j] == 1 && !visited[j])
      DFS(G, j);
}
//�ڽӾ������ȱ�������
void DESTraverse (MGraph G) {
  int i;
  for (i = 0; i < G.numVertexes; i++)
    visited[i] = 0;
  for (i = 0; i < G.numVertexes; i++) {
    if ( !visited[i] )
      DFS(G, i);
  }
}
int main() {
  //�������������Աȡ�����Ҫ�����ڴ棬���Բ���Ҫ��MGraph*ָ�롣
  MGraph G;
  CreateMGraph(&G);
  DESTraverse(G);
  return 0;
}
//ָ�����͵ı���ֻ����->
//��ͨ���͵�.��->������
