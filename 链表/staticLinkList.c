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
//初始化静态链表
Status InitList (StaticLinkList space) {
  int i;
  for (i = 0; i < MAXSIZE - 1; i++)
    space[i].cur = i + 1;
    space[MAXSIZE-1].cur = 0;
    return OK;
}
//回收备用链表
void Free_SSL(StaticLinkList space, int k) {
  space[k].cur = space[0].cur;
  space[0].cur = k;
}
//若备用空间链表非空，则返回分配节点的下标
int Malloc_SSL(StaticLinkList space) {
  int i;
  i = space[0].cur;
  if (space[0].cur)
    space[0].cur = space[i].cur;
  return i;
}
//打印链表中所有元素
ShowData(StaticLinkList L) {
  int j = 1;
  int tempCur = L[MAXSIZE - 1].cur; //2
  while (tempCur) { //1
    printf("第%d个元素（下标%d）是%d\n",j++, tempCur, L[tempCur].data);
    tempCur = L[tempCur].cur; //3
  }
}
//返回静态链表中的元素个数
int ListLength(StaticLinkList L) {
  int j = 0;
  int i = L[MAXSIZE - 1].cur; //1

  while(i) { //1
   // printf("第%d个元素是%d\n", i, L[i].data);
    i = L[i].cur; //2
    j ++;
  }
  return j;
}
//删除第i个元素
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
//实现在L中第i个元素之前插入新的元素e
//为什么传L 而不是 *L
Status ListInsert(StaticLinkList L, int i, ElemType e) {
  int k, j, l;
  k = MAXSIZE - 1;
  if (i < 1 || i > ListLength(L) + 1 ) {
    return ERROR;
  }
  j = Malloc_SSL(L);  //第一个可以用元素8位置8
  printf("j是多少%d\n", j);
  if (j) {
    L[j].data = e;
//为了取到第i个元素之前的元素1
    for ( l = 1; l <= i - 1; l ++) {
      k = L[k].cur;
    }
    L[j].cur = L[k].cur;
    L[k].cur = j;
    printf("插入%d成功: %d\n",j,L[j].data);
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
    printf("请输入要插入的元素\n");
    scanf("%d", &insert);
    ListInsert(staticLinkList, 1, insert);
    i++;
  }
  int length = ListLength(staticLinkList);
  printf("StaticLinkList:%d\n", length);
  ShowData(staticLinkList);
  printf("请输入要删除的元素下表\n");
  scanf("%d", &del);
  ListDelete (staticLinkList, del);
  ShowData(staticLinkList);
}


