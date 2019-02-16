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
//采用队列的链式存储结构
typedef struct QNode{
  int data;
  struct QNode* next;
}QNode, *QueuePtr;
typedef struct {
  QueuePtr front, rear;
}LinkQueue;
//队列部分相关代码
//队列的初始化,不要忘记要分配内存
void InitQueue (LinkQueue *Q) {
  QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
  p -> next = NULL;
  Q -> front = Q -> rear = p;
  printf("队列初始化完成\n");
}
//入队操作
void EnQueue (LinkQueue *Q, int e) {
  QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
  s -> data = e;
  s -> next = NULL;
  Q -> rear -> next = s;
  Q -> rear = s;
  printf("入队元素%d成功\n", e);
}
//出队操作
//是否为空队列
int QueueEmpty(LinkQueue Q) {
  if (Q.front == Q.rear)
    return 0;
  return 1;
}
void Dequeue (LinkQueue *Q, int *e) {
   QueuePtr p;
   if (Q -> front == Q -> rear)
     return 0;
   p = Q -> front -> next;
  *e = p -> data;  //注意*号
   p = p -> next;
   //队列只有一个元素,删除后，头尾指针相等
   if (Q -> rear == p)
     Q -> front == Q -> rear;
   free(p);
   printf("入队元素%c成功\n", *e);
}
void CreateMGraph (MGraph *G) {
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
//邻接矩阵的广度优先算法，结合队列
BFSTraverse (MGraph G) {
  LinkQueue Q;
  int i, j;
  for (i = 0; i < G.numVertexes; i++)
    visited[i] = 0;
  //给Q里面的rear和front分配存储空间,所以不需要地址的地址；注意看清给谁分配内存
  InitQueue(&Q);
  for (i = 0; i < G.numVertexes; i++) {
    if (!visited[i]) {
        printf("第%d个元素是%c:\n", i,G.vex[i]);
        visited[i] = 1;
        EnQueue(&Q, i);
        while (!QueueEmpty(Q)) {
          Dequeue(&Q, &i);
          for (j = 0; j < G.numVertexes; j++) {
            if (G.arc[i][j] == 1 && !visited[j]) {
              printf("第%d个元素是:%c\n", i, G.vex[i]);
              visited[i] = 1;
              EnQueue(&Q, j);
            }
          }
        }
    }
  }
}
int main() {
  //与线索二叉树对比。不需要分配内存，所以不需要用MGraph*指针。
  MGraph G;
  CreateMGraph(&G);
  BFSTraverse(G);
  return 0;
}
