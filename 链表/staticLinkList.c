#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
#define  NULL  ((void *)0)
typedef int ElemType;
typedef int Status;
typedef struct {
  ElemType data;
  int cur;
} Component, StaticLinkList[MAXSIZE];
//��ʼ����̬����
Status InitList (StaticLinkList space) {
  int i;
  for (i = 0; i < MAXSIZE - 1; i++)
    space[i].cur = i + 1;
    space[MAXSIZE-1].cur = 0;
    return OK;
}
//���ձ�������
void Free_SSL(StaticLinkList space, int k) {
  space[k].cur = space[0].cur;
  space[0].cur = k;
}
//�����ÿռ�����ǿգ��򷵻ط���ڵ���±�
int Malloc_SSL(StaticLinkList space) {
  int i;
  i = space[0].cur;
  if (space[0].cur)
    space[0].cur = space[i].cur;
  return i;
}
//��ӡ����������Ԫ��
ShowData(StaticLinkList L) {
  int j = 1;
  int tempCur = L[MAXSIZE - 1].cur; //2
  while (tempCur) { //1
    printf("��%d��Ԫ�أ��±�%d����%d\n",j++, tempCur, L[tempCur].data);
    tempCur = L[tempCur].cur; //3
  }
}
//���ؾ�̬�����е�Ԫ�ظ���
int ListLength(StaticLinkList L) {
  int j = 0;
  int i = L[MAXSIZE - 1].cur; //1

  while(i) { //1
   // printf("��%d��Ԫ����%d\n", i, L[i].data);
    i = L[i].cur; //2
    j ++;
  }
  return j;
}
//ɾ����i��Ԫ��
Status ListDelete(StaticLinkList L, int i) { //2
  int j, k;
  if (i < 1 || i > ListLength(L)) {
    return ERROR;
  }
  k = MAXSIZE - 1;
  for (j = 1; j <= i - 1; j ++) {
    k = L[k].cur;
  }
  j = L[k].cur;
  L[k].cur = L[j].cur;
  Free_SSL(L, j);
  return OK;
}
//ʵ����L�е�i��Ԫ��֮ǰ�����µ�Ԫ��e
//Ϊʲô��L ������ *L
Status ListInsert(StaticLinkList L, int i, ElemType e) {
  int k, j, l;
  k = MAXSIZE - 1;
  if (i < 1 || i > ListLength(L) + 1 ) {
    return ERROR;
  }
  j = Malloc_SSL(L);  //��һ��������Ԫ��8λ��8
  printf("j�Ƕ���%d\n", j);
  if (j) {
    L[j].data = e;
//Ϊ��ȡ����i��Ԫ��֮ǰ��Ԫ��1
    for ( l = 1; l <= i - 1; l ++) {
      k = L[k].cur;
    }
    L[j].cur = L[k].cur;
    L[k].cur = j;
    printf("����%d�ɹ�: %d\n",j,L[j].data);
    return OK;
  }
  return ERROR;
}
void main() {
  int insert;
  int i = 0;
  int del;
  StaticLinkList staticLinkList;
  InitList(staticLinkList);
  printf("staticLinkList[1].cur %d\n", staticLinkList[1].cur);
  while(i < 2){
    printf("������Ҫ�����Ԫ��\n");
    scanf("%d", &insert);
    ListInsert(staticLinkList, 1, insert);
    i++;
  }
  int length = ListLength(staticLinkList);
  printf("StaticLinkList:%d\n", length);
  ShowData(staticLinkList);
  printf("������Ҫɾ����Ԫ���±�\n");
  scanf("%d", &del);
  ListDelete (staticLinkList, del);
  ShowData(staticLinkList);
}


