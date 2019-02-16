#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define  NULL  ((void *)0)
typedef int ElemType;
typedef int Status;
typedef struct DulNode {
  ElemType data;
  struct DulNode *prior;
  struct DulNode *next;
}DulNode, *DulLinkList;
//¶ÁÈ¡ÔªËØ
Status GetElem(DulLinkList L, int i, ElemType *e) {
  int j;
  LinkList p;
  p = L -> next;
  j = 1;
  while (p && j < i)
}
