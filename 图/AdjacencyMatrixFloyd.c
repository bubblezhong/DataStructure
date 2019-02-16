#include <stdio.h>
#define MAXVEX 9
#define INFINITY 65535
typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];
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
  //printf("请输入边数和顶点数\n");
  G -> numEdges = 5;
  G -> numVertexes = 4;
 // scanf("%d %d",&G -> numEdges, &G -> numVertexes);
  //读入顶点信息，建立顶点表，初始化数组
  //printf("请输入顶点数组\n");
  fflush(stdin);
  for ( i = 0; i < G -> numVertexes; i ++ ) {
     G -> vex[i] = i;
     //printf("请输入第%d个数据", i);
     //scanf("%c", &G -> vex[i]);
    fflush(stdin);
  }

  //初始化边信息
  for ( i = 0; i < G -> numVertexes; i ++ )
    for( j = 0; j < G -> numVertexes; j ++ )
      G -> arc[i][j] = INFINITY;
  //读入边，建立邻接矩阵
  /*for (k = 0; k < G -> numEdges; k++) {
     printf("请输入边的下标i, j,以及权重k\n");
     scanf("%d %d %d", &i, &j, &quan);
     G -> arc[i][j] = quan;
     G -> arc[j][i] = G -> arc[i][j];
   }*/
  G -> arc[0][1] = 6;G -> arc[0][2] = 8;G -> arc[3][1] = 16;G -> arc[2][1] = 9;G -> arc[2][3] = 5;
  G -> arc[1][0] = 6;G -> arc[2][0] = 8;G -> arc[1][3] = 16;G -> arc[1][2] = 9;G -> arc[3][2] = 5;
 }
 //求网图中各顶点v到其余顶点w最短路径p[v][w]及带权长度D[v][w]
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
                printf("元素%d\n", (*D)[v][w]);
        }
    }
  //显示最短路径
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
  //与线索二叉树对比。不需要分配内存，所以不需要用MGraph*指针。
  MGraph G;
  CreateMGraph(&G);
  Pathmatirx p;
  ShortPathTable D;
  ShortPath_Floyd (G, p, D);
  return 0;
}





















