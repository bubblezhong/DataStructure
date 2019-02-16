#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define  NULL  ((void *)0)
typedef int ElemType;
typedef int Status;
//初始化单链表
typedef struct Node {
  ElemType data;
  struct Node *next;
} Node;
//定义inkList
typedef struct Node* LinkList;
//LinkList 的区别
//单链表的读取(为什么*e???区别LinkList *L)
//如果是需要对线性表进行操作，则函数调用处传入地址，函数定义处使用指针；
Status GetElem (LinkList L, int i, ElemType *e){
  printf ("进入读取函数%d\n", i, L);
  int j;
  LinkList p;            //声明节点p
  p = L -> next;         //指向链表的第一个节点（与插入区别）
  j = 1;
  //printf("p && j < i %d\n", p);
  while( p && j < i ){
    //printf("j是多少%d\n", j);
    p = p -> next;
    ++j;
  }
  if ( !p || j>i ){
    return ERROR;
  }
  *e = p -> data;
 // printf("*e是%d\n", *e);
  return OK;
}
Status ListInsert (LinkList* L, int i, ElemType e) {
  printf("要插入的元素及位置%d,%d,\n", e, i);
  int j;
  LinkList p, s;
  j = 1;
  p = *L;
  while ( p -> next && j<i ) { // 3 (5)
    p = p -> next; //3
    ++j;//2
  }
    if ( !p || j>i ) {
      return ERROR;
    }
  s = (LinkList)malloc(sizeof(Node));
  s -> data = e;
  s -> next = p -> next;  //null
  p -> next = s;
  printf("插入元素%d成功,\n", s -> data);
  return OK;
}
Status ListDelete (LinkList *L, int i, ElemType *e) {
   int j;
   LinkList p, q;
   p = *L;
   j = 1;
   //为什么是p -> next:p是被删除元素的前一个的节点 1 2 3
   while ( p -> next && j < i ) {  //  4
     p = p -> next;  // 1 2 p=3
     ++j;  //2 3 4
   }
   if ( !( p -> next ) || j > i ) {
    return ERROR;
   }
   q = p -> next;   //null
   p -> next = q -> next;
   *e = q -> data;
   printf("被删除元素q -> data: %d\n", q -> data);
   free(q);
   return OK;
}
showAllData(LinkList L) {
  int j;
  LinkList p;
  p = L -> next;
  j = 1;
    while (p){
      printf("第%d个元素是%d\n", j,p -> data);
      p = p -> next;
      j++;
    }
}
//单链表的整表创建
void CreateListHeade (LinkList *L, int n) {
  LinkList p, r;
  int i;
  int temData;
  //为链表开辟内存，并且保存头指针；
  * L = (LinkList)malloc(sizeof(Node));
  r = *L;
  for ( i = 0; i < n; i ++ ){
    printf("请输入第%d个元素，\n", i);
    scanf("%d",&temData);
    p = (LinkList)malloc(sizeof(Node));
    p -> data = temData;
    r -> next = p;
    r = p;
    printf("p -> data：%d,p: %d\n",p -> data, p);
  }
  r -> next = NULL;  //表示当前链表结束
}
//单链表的整表删除
Status ListClear (LinkList *L) {
  LinkList p, q;
  p = *L;
  while (p) {
    q = p -> next;
    free(p);
    p = q;
  }
  (*L) -> next = NULL;
  printf("删除结束");
  return OK;
}
void main() {
  LinkList linkList;
  int i = 2;
  int result;
  int n = 2;
  int temp = 1;
  int mark;
  int delData;
    CreateListHeade(&linkList, n);
    showAllData(linkList);
    while ( temp < 3 ) {
      ListInsert(&linkList, i, temp + 5);
      temp++;
    }
    showAllData(linkList);
    GetElem(linkList, i, &result);
    printf("读取到第%d元素%d\n", i, result);
    printf("请输入要删除的元素下标\n");
    scanf("%d", &mark);
    ListDelete(&linkList, mark, &delData);
    printf("删除后的结果、\n");
    showAllData(linkList);
    //ListClear(&linkList);
    //showAllData(linkList);

}
