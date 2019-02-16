#include <stdio.h>
#define MAXVEX 65535
#define INFINITY 65535
int *etv, *ltv;     //�¼����緢��ʱ�����ٷ���ʱ�����飻
int *stack2;        //���ڴ洢�������е�ջ
int top2;           //����stack2��ָ��
typedef struct EdgeNode {  //�߱�ڵ�
  int adjvex;             //�ڽӵ��򣬴洢�ö����Ӧ���±�
  int weight;              //�洢Ȩֵ
  struct EdgeNode *next;      //����ָ����һ���ڽӵ�
}EdgeNode;
//�����ڵ�
typedef struct VextexNode{
  int in;           //�������
  int data;         //������洢������Ϣ
  EdgeNode * firstedge;       //�߱�ͷָ��
}VertexNode, AdjList[MAXVEX];
typedef struct {
  AdjList adjList;
  int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;
//��ʼ��
CreateALGraph(GraphAdjList G) {
  int j, k, i, quan;
  EdgeNode* e;
  printf("�����붥�����ͱ���\n");
  scanf("%d %d", &G -> numVertexes, &G -> numEdges);
  printf("һ��������0�� %d\n", G -> numEdges);
  fflush(stdin);
  for (i = 0; i < G -> numVertexes; i++) {
    printf("������%d��Ԫ�غ����\n", i);
    scanf("%d %d", &G -> adjList[i].data, &G -> adjList[i].in);   //���붥����Ϣ
    fflush(stdin);
    G -> adjList[i].firstedge = NULL;    //�߱��ÿ�
  }
  printf("һ�������ߣ� %d\n", G -> numEdges);
  for (k = 0; k < G -> numEdges; k++) {
    printf("������ߵĶ�������Լ�Ȩ��quan\n");
    scanf("%d %d %d", &i, &j, &quan);
    fflush(stdin);
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e -> adjvex = j;
    e -> weight = quan;
    e -> next = G -> adjList[i].firstedge;
    G -> adjList[i].firstedge = e;
    //����1��ע����������ߺ������
    /*e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e -> adjvex = i;
    e ->next = G -> adjList[j].firstedge;
    G -> adjList[j].firstedge = e;
    */
  }
}
//�����������ڹؼ�·���ļ���
int TopologicalSort (GraphAdjList GL) {
  EdgeNode *e;
  int i, k, gettop;
  int top = 0;           //����ջָ����±�
  int count = 0;          //����ͳ���������ĸ���
  int *stack;            //����ջ�������Ϊ0�Ķ�����ջ
  stack = (int *)malloc(GL -> numVertexes * sizeof(int));
  for (i = 0; i < GL -> numVertexes; i++)
    if (0 == GL -> adjList[i].in)
      stack[++ top] = i;
  top2 = 0;              //��ʼ��Ϊ0
  etv = (int *)malloc(GL -> numVertexes * sizeof(int));   //��ʼ��
  for (i = 0; i < GL -> numVertexes; i++)
    etv[i] = 0;
  //����3�����Ƿ����ڴ�
  stack2 = (int *)malloc(GL -> numVertexes * sizeof(int));
  while (top != 0) {
    gettop = stack[top --];
    count ++;
    stack2[++ top2] = gettop;            //�������Ķ������ѹ����������ջ
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
//��ؼ�·����GLΪ�����������GL�ĸ���ؼ��
void CriticalPath (GraphAdjList GL) {
  EdgeNode *e;
  int i, gettop, k, j;
  int ete, lte;              //��������緢��ʱ�����ٷ���ʱ��
  TopologicalSort(GL);
  ltv = (int *)malloc(GL -> numVertexes * sizeof(int));
  for (i = 0; i < GL -> numVertexes; i++)
    ltv[i] = etv[GL -> numVertexes -1];
  while (top2 != 0){
    gettop = stack2[top2--];
    //����¼����������ʱ��ltv��ֵ
    for (e = GL -> adjList[gettop].firstedge; e; e = e -> next) {
      k = e -> adjvex;
      if (ltv[k] - e -> weight < ltv[gettop])
        ltv[gettop] = ltv[k] - e -> weight;
    }
  }
  //��ete,lte�͹ؼ��
    //����2��ѭ�����⣬==����
    for (j = 0; j < GL -> numVertexes; j++) {
      for (e = GL ->adjList[j].firstedge; e; e = e ->next) {

        k = e -> adjvex;
        ete = etv[j];                   //����緢��ʱ��
        lte = ltv[k] - e -> weight;          //���ٷ���ʱ��
        if (ete == lte) {
          printf("<v%d, v%d>  length: %d\n", GL -> adjList[j].data, GL -> adjList[k].data, e -> weight);
        }
      }
    }
}
void main() {
  graphAdjList GL;
  //��ʼ��
  CreateALGraph(&GL);
  CriticalPath (&GL);
}






















