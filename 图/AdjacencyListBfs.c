//邻接表，数组与链表相结合
#include <stdio.h>
#define MAXVEX 100
typedef char VertextType;
typedef int EdgeType;
int visited[MAXVEX];
typedef struct EdgeNode {
  int adjvex;
  //EdgeType weight;
  struct EdgeNode* next;
} EdgeNode;
typedef struct VertexNode {
  VertextType data;
  EdgeNode* firstNode;
}VertexNode, AdjList[MAXVEX];
typedef struct {
  AdjList adjList;
  int numVertexes, numEdges;
}GraphAdjList;
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
CreateALGraph(GraphAdjList* G) {
  int j, k, i;
  EdgeNode* e;
  printf("请输入顶点数和边数\n");
  scanf("%d %d", &G -> numVertexes, &G -> numEdges);
  fflush(stdin);
  for (i = 0; i < G -> numVertexes; i++) {
    printf("请输入%d个元素\n", i);
    scanf("%c", &G -> adjList[i].data);   //输入顶点信息
    fflush(stdin);
    G -> adjList[i].firstNode = NULL;    //边表置空
  }
 // printf("一共几条边： %d\n", G -> numEdges);
  for (k = 0; k < G -> numEdges; k++) {
    printf("请输入边的顶点序号\n");
    scanf("%d %d", &i, &j);
    fflush(stdin);
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e -> adjvex = j;
    e -> next = G -> adjList[i].firstNode;
    G -> adjList[i].firstNode = e;
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e -> adjvex = i;
    e ->next = G -> adjList[j].firstNode;
    G -> adjList[j].firstNode = e;
  }
}
//邻接表广度优先算法
BFSTraverse (GraphAdjList G) {
  int i;
  EdgeNode* p;
  LinkQueue Q;
  InitQueue(&Q);
  for (i = 0; i < G.numVertexes; i++)
    visited[i] = 0;
  for (i = 0; i < G.numVertexes; i++) {
    if (!visited[i]) {
       printf("第%d个节点是:%c\n", i, G.adjList[i].data);  //打印节点
       visited[i] = 1;
       EnQueue(&Q, G.adjList[i].data);
       while (!QueueEmpty) { //有问题
         Dequeue(&Q, &i);
         p = G.adjList[i].firstNode;
         while (p) {
           if (!visited[p -> adjvex]) {
            printf("第%d个节点是:%c\n", p -> adjvex, G.adjList[p -> adjvex].data);
            visited[p -> adjvex] = 1;
            EnQueue(&Q, p -> adjvex);
           }
         }
         p = p -> next;
       }
    }
  }
}
int main() {
  GraphAdjList G;
  CreateALGraph (&G);
  BFSTraverse (G);
  return 0;
}
