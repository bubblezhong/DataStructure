//�ڽӱ���������������
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
//���ö��е���ʽ�洢�ṹ
typedef struct QNode{
  int data;
  struct QNode* next;
}QNode, *QueuePtr;
typedef struct {
  QueuePtr front, rear;
}LinkQueue;
//���в�����ش���
//���еĳ�ʼ��,��Ҫ����Ҫ�����ڴ�
void InitQueue (LinkQueue *Q) {
  QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
  p -> next = NULL;
  Q -> front = Q -> rear = p;
  printf("���г�ʼ�����\n");
}
//��Ӳ���
void EnQueue (LinkQueue *Q, int e) {
  QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
  s -> data = e;
  s -> next = NULL;
  Q -> rear -> next = s;
  Q -> rear = s;
  printf("���Ԫ��%d�ɹ�\n", e);
}
//���Ӳ���
//�Ƿ�Ϊ�ն���
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
  *e = p -> data;  //ע��*��
   p = p -> next;
   //����ֻ��һ��Ԫ��,ɾ����ͷβָ�����
   if (Q -> rear == p)
     Q -> front == Q -> rear;
   free(p);
   printf("���Ԫ��%c�ɹ�\n", *e);
}
CreateALGraph(GraphAdjList* G) {
  int j, k, i;
  EdgeNode* e;
  printf("�����붥�����ͱ���\n");
  scanf("%d %d", &G -> numVertexes, &G -> numEdges);
  fflush(stdin);
  for (i = 0; i < G -> numVertexes; i++) {
    printf("������%d��Ԫ��\n", i);
    scanf("%c", &G -> adjList[i].data);   //���붥����Ϣ
    fflush(stdin);
    G -> adjList[i].firstNode = NULL;    //�߱��ÿ�
  }
 // printf("һ�������ߣ� %d\n", G -> numEdges);
  for (k = 0; k < G -> numEdges; k++) {
    printf("������ߵĶ������\n");
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
//�ڽӱ��������㷨
BFSTraverse (GraphAdjList G) {
  int i;
  EdgeNode* p;
  LinkQueue Q;
  InitQueue(&Q);
  for (i = 0; i < G.numVertexes; i++)
    visited[i] = 0;
  for (i = 0; i < G.numVertexes; i++) {
    if (!visited[i]) {
       printf("��%d���ڵ���:%c\n", i, G.adjList[i].data);  //��ӡ�ڵ�
       visited[i] = 1;
       EnQueue(&Q, G.adjList[i].data);
       while (!QueueEmpty) { //������
         Dequeue(&Q, &i);
         p = G.adjList[i].firstNode;
         while (p) {
           if (!visited[p -> adjvex]) {
            printf("��%d���ڵ���:%c\n", p -> adjvex, G.adjList[p -> adjvex].data);
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
