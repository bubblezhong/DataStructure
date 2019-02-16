#include <stdio.h>
typedef enum {Link, Thread} PointerTag;
typedef struct BitThrNode {
  char data;
  struct BitThrNode *lchild, *rchild;
  PointerTag ltag;
  PointerTag rtag;
} BitThrNode, *BitThrTree;
//ȫ�ֱ������ոշ��ʹ��Ľڵ�
BitThrTree pre;  //BitThrNode * pre
//����ǰ������ķ�ʽ�������ݣ�����һ�Ŷ�����
//�൱��BitThrNode **T,ָ���ָ�룬��ָ����г�ʼ������ָ��ĵ�ַ
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
//�������������
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
//����������������ǵݹ�..T��ͷָ��
void InOrderTraverse ( BitThrTree T) {
  BitThrTree P;
  P = T -> lchild; //ͷ���
  while ( P != T) {  //ͷ��㲻����ͷָ��
    while (P -> ltag == Link) { //�ҵ�����ߵ�Ҷ�ӽڵ�
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
  printf("�����������Ľ��Ϊ:");
  InOrderTraverse(P);
  return 0;
}
