//邻接矩阵的数据结构以及遍历（广度优先）结合队列
#include <stdio.h>
#define MAXVEX 100
#define INFINITY 65535
typedef char VertextType;
typedef int EdgeType;
typedef int Boolean;
Boolean visited[MAXVEX];
//邻接矩阵的数据结构
typedef struct {
  VertextType vex[MAXVEX];              //顶点表
  EdgeType arc[MAXVEX][MAXVEX];         //邻接矩阵
  int numVertexes, numEdges;           //图中当前的顶点数和边数
} MGraph;
void CreateMGraph (MGraph *G) {
  int i, j, k, quan;
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
    for( j = 0; j < G -> numVertexes; j ++ ) {
       if (i == j) {
         G -> arc[i][j] = 0;
       } else {
         G -> arc[i][j] = INFINITY;
       }
    }
  //读入边，建立邻接矩阵
  for (k = 0; k < G -> numEdges; k++) {
    printf("请输入边的下标i, j,以及权重k\n");
    scanf("%d %d %d", &i, &j, &quan);
    G -> arc[i][j] = quan;
    G -> arc[j][i] = G -> arc[i][j];
    printf("第%d个%d,quan是%d\n", k, quan, G -> arc[j][i]);
  }
}
//prim算法生成最小树
MiniSpanTree_Prim (MGraph G) {
  int i, j, k, min;
  int adjvex[MAXVEX];
  int lowcost[MAXVEX];
  //初始化第一个权值为0，值为0表明此下标的顶点已经加入生成树
  lowcost[0] = 0;
  adjvex[0] = 0;
  for (i = 1; i < G.numVertexes; i++ ) {
    lowcost[i] = G.arc[0][i];
    adjvex[i] = 0;
  }
  for (i = 1; i < G.numVertexes; i++) {
    min = INFINITY; //初始化最小权值
    j = 1;
    for (j = 1; j < G.numVertexes; j++) {
       if (lowcost[j] < min && lowcost[j] != 0) {
         min = lowcost[j];
         k = j;
       }
    }
    printf("第%d条路径是(%d, %d)", i, adjvex[k], k);
    lowcost[k] = 0;   //将当前顶点的权值设置为0则表示此顶点已经完成任务
    for (j = 1; j < G.numVertexes; j++) {
        if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
            lowcost[j] = G.arc[k][j];
            adjvex[j] = k;         //将下标为k的顶点存入adjvex
        }
    }
  }
}
int main() {
  //与线索二叉树对比。不需要分配内存，所以不需要用MGraph*指针。
  MGraph G;
  CreateMGraph(&G);
  //BFSTraverse(G);
  MiniSpanTree_Prim(G);
  return 0;
}

