#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct BiTNode {
  char data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
//二叉树结构
void CreateBiTree(BiTree *T) {
  char c;
  scanf("%c", &c);
  if ('#' == c) {
    *T = NULL;
  } else {
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    (*T) -> data = c;
    printf("输入%c\n",(*T) -> data);
    CreateBiTree(&(*T) -> lchild);
    CreateBiTree(&(*T) -> rchild);
  }
}
//访问二叉树
void visit(char c, int level) {
  printf("%c所在层%d \n", c, level);
}
//后序遍历
void PostOrderTraverse(BiTree T, int level) {
  if (T) {
    PostOrderTraverse(T -> lchild, level+1);
    PostOrderTraverse(T -> rchild, level+1);
    visit(T -> data, level);
  }
}
void main() {
  int level = 1;
  //声明BiTNode T = NULL;
  BiTree T = NULL;
  CreateBiTree(&T);
  PostOrderTraverse(T, level);
}

