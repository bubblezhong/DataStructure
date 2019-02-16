//�ڽӾ�������ݽṹ�Լ�������������ȣ���϶���
#include <stdio.h>
#define MAXVEX 100
#define INFINITY 65535
typedef char VertextType;
typedef int EdgeType;
typedef int Boolean;
Boolean visited[MAXVEX];
//�ڽӾ�������ݽṹ
typedef struct {
  VertextType vex[MAXVEX];              //�����
  EdgeType arc[MAXVEX][MAXVEX];         //�ڽӾ���
  int numVertexes, numEdges;           //ͼ�е�ǰ�Ķ������ͱ���
} MGraph;
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
void CreateMGraph (MGraph *G) {
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
//�ڽӾ���Ĺ�������㷨����϶���
BFSTraverse (MGraph G) {
  LinkQueue Q;
  int i, j;
  for (i = 0; i < G.numVertexes; i++)
    visited[i] = 0;
  //��Q�����rear��front����洢�ռ�,���Բ���Ҫ��ַ�ĵ�ַ��ע�⿴���˭�����ڴ�
  InitQueue(&Q);
  for (i = 0; i < G.numVertexes; i++) {
    if (!visited[i]) {
        printf("��%d��Ԫ����%c:\n", i,G.vex[i]);
        visited[i] = 1;
        EnQueue(&Q, i);
        while (!QueueEmpty(Q)) {
          Dequeue(&Q, &i);
          for (j = 0; j < G.numVertexes; j++) {
            if (G.arc[i][j] == 1 && !visited[j]) {
              printf("��%d��Ԫ����:%c\n", i, G.vex[i]);
              visited[i] = 1;
              EnQueue(&Q, j);
            }
          }
        }
    }
  }
}
int main() {
  //�������������Աȡ�����Ҫ�����ڴ棬���Բ���Ҫ��MGraph*ָ�롣
  MGraph G;
  CreateMGraph(&G);
  BFSTraverse(G);
  return 0;
}
