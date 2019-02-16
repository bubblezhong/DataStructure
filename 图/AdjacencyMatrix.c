#include <stdio.h>
typedef char VertextType;
typedef int EdgeType;
typedef int Boolean;
#define MAXVEX 100
#define INFINITY 65535
Boolean visited[MAXVEX];
typedef struct {
  VertextType vex[MAXVEX];              //顶点表
  EdgeType arc[MAXVEX][MAXVEX];         //邻接矩阵
  int numVertexes, numEdges;           //图中当前的顶点数和边数
} MGraph;
void CreateMGraph (MGraph *G) {  //G的引用:看底下备注
  int i, j, k;
  printf("请输入边数和顶点数\n");
  scanf("%d %d",&G -> numEdges, &G -> numVertexes);
  //读入顶点信息，建立顶点表，初始化数组
  //printf("请输入顶点数组\n");
  fflush(stdin);
  for ( i = 0; i < G -> numVertexes; i ++ ) {
    printf("请输入第%d个数据", i);
    scanf("%c", &G -> vex[i]);
    fflush(stdin);
  }

  //初始化边信息
  for ( i = 0; i < G -> numVertexes; i ++ )
    for( j = 0; j < G -> numVertexes; j ++ )
      G -> arc[i][j] = INFINITY;
  //读入边，建立邻接矩阵
  for (k = 0; k < G -> numEdges; k++) {
    printf("请输入边的下标i, j\n");
    scanf("%d %d", &i, &j);
    G -> arc[i][j] = 1;
    G -> arc[j][i] = G -> arc[i][j];
  }
}
//邻接矩阵的深度优先算法
void DFS (MGraph G, int i) {
  int j;
  visited[i] = 1;
  printf("第%d个元素是: %c\n", i, G.vex[i]);
  for (j = 0; j < G.numEdges; j++)
    if (G.arc[i][j] == 1 && !visited[j])
      DFS(G, j);
}
//邻接矩阵的深度遍历操作
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
  //与线索二叉树对比。不需要分配内存，所以不需要用MGraph*指针。
  MGraph G;
  CreateMGraph(&G);
  DESTraverse(G);
  return 0;
}
//指针类型的变量只能用->
//普通类型的.和->都能用
