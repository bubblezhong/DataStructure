#include <stdio.h>
typedef enum {Link, Thread} PointerTag;
typedef struct BitThrNode {
  char data;
  struct BitThrNode *lchild, *rchild;
  PointerTag ltag;
  PointerTag rtag;
} BitThrNode, *BitThrTree;
//全局变量，刚刚访问过的节点
BitThrTree pre;  //BitThrNode * pre
//按照前序遍历的方式输入数据，创建一颗二叉树
//相当于BitThrNode **T,指针的指针，对指针进行初始化，传指针的地址
CreateBiThrTree (BitThrTree *T) {
  char c;
  scanf("%c", &c);
  if (' ' == c) {
    *T = NULL;
  } else {
    *T = (BitThrNode *)malloc(sizeof(BitThrNode));
    (*T) -> data = c;
    CreateBiThrTree(&(*T) -> lchild);
    CreateBiThrTree(&(*T) -> rchild);
    (*T) -> ltag = Link;
    (*T) -> rtag = Link;
   }
}
//中序遍历线索化
InThreading (BitThrTree T) {
  if (T) {
    InThreading(T -> lchild);
    if (! T -> lchild) {
        T -> ltag = Thread;
        T -> lchild = pre;
    }
    if (! pre -> rchild) {
        pre -> rtag = Thread;
        pre -> rchild = T;
    }
    pre = T;
    InThreading(T -> rchild);
  }
}
InOrderThreading (BitThrTree *P, BitThrTree T) {
  *P = (BitThrTree)malloc(sizeof(BitThrNode));
  (*P) -> ltag = Link;
  (*P) -> rtag = Thread;
  (*P) -> rchild = *P;
  if ( ! T ) {
    (*P) -> lchild = *P;
  } else {
    (*P) -> lchild = T;
    pre = *P;
    InThreading(T);
    pre -> rtag = Thread;
    pre -> rchild = *P;
    (*P) -> rchild = pre;
  }
}
//中序遍历二叉树，非递归..T是头指针
void InOrderTraverse ( BitThrTree T) {
  BitThrTree P;
  P = T -> lchild; //头结点
  while ( P != T) {  //头结点不等于头指针
    while (P -> ltag == Link) { //找到最左边的叶子节点
        P = P -> lchild;
    }
    printf("%c", P -> data);
    while (P -> rtag == Thread && P -> rchild != T) {
      P = P -> rchild;
      printf("%c", P -> data);
    }
    P = P -> rchild;
  }
}
int main() {
  BitThrTree P, T = NULL;
  CreateBiThrTree( &T );
  InOrderThreading(&P, T);
  printf("中序遍历输出的结果为:");
  InOrderTraverse(P);
  return 0;
}
