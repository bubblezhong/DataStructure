#include <stdio.h>
#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX]; //用于存储最短路径下标的数组Pathac[i] = 3;表示i的前驱是3
typedef int ShortPathTable[MAXVEX];  //用于存储到各点最短路径的权值之和
typedef char VertextType;
typedef int EdgeType;
typedef int Boolean;
typedef struct {
  VertextType vex[MAXVEX];              //顶点表
  EdgeType arc[MAXVEX][MAXVEX];         //邻接矩阵
  int numVertexes, numEdges;           //图中当前的顶点数和边数
} MGraph;
void CreateMGraph (MGraph *G) {  //G的引用:看底下备注
  int i, j, k, quan;
  printf("请输入边数和顶点数\n");
  G -> numEdges = 5;
  G -> numVertexes = 4;
  //scanf("%d %d",&G -> numEdges, &G -> numVertexes);
  //读入顶点信息，建立顶点表，初始化数组
  //printf("请输入顶点数组\n");
  fflush(stdin);
  for ( i = 0; i < G -> numVertexes; i ++ ) {
     G -> vex[i] = i;
    //printf("请输入第%d个数据", i);
   // scanf("%c", &G -> vex[i]);
    fflush(stdin);
  }

  //初始化边信息
  for ( i = 0; i < G -> numVertexes; i ++ )
    for( j = 0; j < G -> numVertexes; j ++ )
      G -> arc[i][j] = INFINITY;
  //读入边，建立邻接矩阵
  //for (k = 0; k < G -> numEdges; k++) {
    //printf("请输入边的下标i, j,以及权重k\n");
  //  scanf("%d %d %d", &i, &j, &quan);
  //  G -> arc[i][j] = k;
   // G -> arc[j][i] = G -> arc[i][j];
 // }
  G -> arc[0][1] = 6;G -> arc[0][2] = 8;G -> arc[3][1] = 16;G -> arc[2][1] = 9;G -> arc[2][3] = 5;
  G -> arc[1][0] = 6;G -> arc[2][0] = 8;G -> arc[1][3] = 16;G -> arc[1][2] = 9;G -> arc[3][2] = 5;
//  for ( i = 0; i < G -> numVertexes; i ++ )
 //   for( j = 0; j < G -> numVertexes; j ++ )
  //    printf("数(%d,%d)组元素%d\n",i,j, G->arc[i][j]);

}
//Dijkstra算法求最短路径
void ShortPath_Dijkstra (MGraph G, Patharc *p, ShortPathTable *D) {
  int i, v, w, k, min;
  int final[MAXVEX], tempData[MAXVEX];   //finial[i] = 1表示已求得顶点0到i之间的路径
  for (i = 0; i < G.numVertexes; i++) {
    final[i] = 0;
    (*D)[i] = G.arc[0][i];
    (*p)[i] = 0;
  }
  (*D)[0] = 0;
  final[0] = 1;
  //开始主循环,每循环求得第0个顶点到第i个顶点的最短路径
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
  //打印结果
  printf("打印结果\n");
  printf("%d\n", (*p)[0]);
  for (v = 0; v < G.numVertexes; v++) {
    printf("以下为最短路径%d\n", (*p)[v]);
   // tempData[v] = G.vex[(*p)[v]]
  }
}
showData (MGraph G, Patharc *p, int x) {
  int temp;
  printf("最短路径%d", G.vex[x]);
  temp = (*p)[x];
  printf("temp:%d\n")
  if (temp != 0) {
    showData(G, p, temp);
  } else {
    printf("%d", G.vex[0]);
  }
}
int main() {
  //与线索二叉树对比。不需要分配内存，所以不需要用MGraph*指针。
  MGraph G;
  CreateMGraph(&G);
  Patharc p;
  ShortPathTable D;
  ShortPath_Dijkstra(G, p, D);
  showData(G, p, G.vex[G.numVertexes - 1]);
  return 0;
}




















