#include <stdio.h>
#define MAXVEX 65535
#define INFINITY 65535
int *etv, *ltv;     //事件最早发生时间和最迟发生时间数组；
int *stack2;        //用于存储拓扑序列的栈
int top2;           //用于stack2的指针
typedef struct EdgeNode {  //边表节点
  int adjvex;             //邻接点域，存储该顶点对应的下标
  int weight;              //存储权值
  struct EdgeNode *next;      //链域，指向下一个邻接点
}EdgeNode;
//顶点表节点
typedef struct VextexNode{
  int in;           //顶点入度
  int data;         //顶点域存储顶点信息
  EdgeNode * firstedge;       //边表头指针
}VertexNode, AdjList[MAXVEX];
typedef struct {
  AdjList adjList;
  int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;
//初始化
CreateALGraph(GraphAdjList G) {
  int j, k, i, quan;
  EdgeNode* e;
  printf("请输入顶点数和边数\n");
  scanf("%d %d", &G -> numVertexes, &G -> numEdges);
  printf("一共几条边0： %d\n", G -> numEdges);
  fflush(stdin);
  for (i = 0; i < G -> numVertexes; i++) {
    printf("请输入%d个元素和入度\n", i);
    scanf("%d %d", &G -> adjList[i].data, &G -> adjList[i].in);   //输入顶点信息
    fflush(stdin);
    G -> adjList[i].firstedge = NULL;    //边表置空
  }
  printf("一共几条边： %d\n", G -> numEdges);
  for (k = 0; k < G -> numEdges; k++) {
    printf("请输入边的顶点序号以及权重quan\n");
    scanf("%d %d %d", &i, &j, &quan);
    fflush(stdin);
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e -> adjvex = j;
    e -> weight = quan;
    e -> next = G -> adjList[i].firstedge;
    G -> adjList[i].firstedge = e;
    //问题1：注意区别有向边和无向边
    /*e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e -> adjvex = i;
    e ->next = G -> adjList[j].firstedge;
    G -> adjList[j].firstedge = e;
    */
  }
}
//拓扑排序，用于关键路径的计算
int TopologicalSort (GraphAdjList GL) {
  EdgeNode *e;
  int i, k, gettop;
  int top = 0;           //用于栈指针的下标
  int count = 0;          //用于统计输出顶点的个数
  int *stack;            //建立栈，将入度为0的顶点入栈
  stack = (int *)malloc(GL -> numVertexes * sizeof(int));
  for (i = 0; i < GL -> numVertexes; i++)
    if (0 == GL -> adjList[i].in)
      stack[++ top] = i;
  top2 = 0;              //初始化为0
  etv = (int *)malloc(GL -> numVertexes * sizeof(int));   //初始化
  for (i = 0; i < GL -> numVertexes; i++)
    etv[i] = 0;
  //问题3：忘记分配内存
  stack2 = (int *)malloc(GL -> numVertexes * sizeof(int));
  while (top != 0) {
    gettop = stack[top --];
    count ++;
    stack2[++ top2] = gettop;            //将弹出的顶点序号压入拓扑序列栈
    for (e = GL -> adjList[gettop].firstedge; e; e = e -> next) {
      k = e -> adjvex;
      if (! (-- GL -> adjList[k].in))
        stack[++top] = k;
      if ((etv[gettop] + e -> weight) > etv[k]) {
         etv[k] = etv[gettop] + e -> weight;
      }

    }
  }
  if (count < GL -> numVertexes) {
    return 0;
  } else {
    return 1;
  }
}
//求关键路径，GL为有向网，输出GL的各项关键活动
void CriticalPath (GraphAdjList GL) {
  EdgeNode *e;
  int i, gettop, k, j;
  int ete, lte;              //声明活动最早发生时间和最迟发生时间
  TopologicalSort(GL);
  ltv = (int *)malloc(GL -> numVertexes * sizeof(int));
  for (i = 0; i < GL -> numVertexes; i++)
    ltv[i] = etv[GL -> numVertexes -1];
  while (top2 != 0){
    gettop = stack2[top2--];
    //求各事件发生的最迟时间ltv的值
    for (e = GL -> adjList[gettop].firstedge; e; e = e -> next) {
      k = e -> adjvex;
      if (ltv[k] - e -> weight < ltv[gettop])
        ltv[gettop] = ltv[k] - e -> weight;
    }
  }
  //求ete,lte和关键活动
    //问题2：循环问题，==问题
    for (j = 0; j < GL -> numVertexes; j++) {
      for (e = GL ->adjList[j].firstedge; e; e = e ->next) {

        k = e -> adjvex;
        ete = etv[j];                   //活动最早发生时间
        lte = ltv[k] - e -> weight;          //活动最迟发生时间
        if (ete == lte) {
          printf("<v%d, v%d>  length: %d\n", GL -> adjList[j].data, GL -> adjList[k].data, e -> weight);
        }
      }
    }
}
void main() {
  graphAdjList GL;
  //初始化
  CreateALGraph(&GL);
  CriticalPath (&GL);
}






















