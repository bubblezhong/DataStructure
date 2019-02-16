#include <stdio.h>
typedef struct BiTNode {
  int data;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
//二叉排序树的查找
SearchBST(BiTree T, int key, BiTree f, BiTree *p) {   //为什么是BiTree *p ？？？？
  if (!T) {
    *p = f;
    return 0;
  } else if (T -> data == key) {
     *p = T;
     return 1;
  } else if (key < T -> data) {
     SearchBST(T -> lchild, key, T, p);
  } else {
     SearchBST(T -> rchild, key, T, p);
  }
}
/*
//二叉排序树的插入
InsertBST(BiTree *T, int key) {
  BiTree p, s;
  if (!SearchBST(*T, key, NULL, &p)) {   //p改变以后需要使用，所以传入地址的地址
    s = (BiTree)malloc(sizeof(BiTNode));
    s -> data = key;
    s -> lchild = s -> rchild = NULL;
    if (!p)
      *T = s;               //插入的s为新的根节点
    else if (key < p -> data)
      p -> lchild = s;      //插入s为左孩子
    else
      p -> rchild = s;
    return 1;

  } else {
    return 0;                 //树中已有关键字，不在输入
  }
}*/
InsertBST(BiTNode *T, int key) {
  BiTree p, s;
  if (!SearchBST(T, key, NULL, &p)) {   //p改变以后需要使用，所以传入地址的地址
    s = (BiTree)malloc(sizeof(BiTNode));
    s -> data = key;
    s -> lchild = s -> rchild = NULL;
    if (!p)
      T = s;               //插入的s为新的根节点
    else if (key < p -> data)
      p -> lchild = s;      //插入s为左孩子
    else
      p -> rchild = s;
    return 1;

  } else {
    return 0;                 //树中已有关键字，不在输入
  }
}
//二叉树的中序遍历
int InOrderTraverse(BiTree T){
  if (T == NULL)
    return 0;
  InOrderTraverse(T -> lchild);
  printf("%d\n", T -> data);
  InOrderTraverse(T -> rchild);
}
//二叉排序树的删除
int DeleteBST (BiTree *T, int key) {
  if (!*T)
    return 0;
  else {
    if (key == (*T) -> data)
      Delete(T);
    else if (key < (*T) -> data)
      DeleteBST(&(*T) -> lchild, key);
    else
      DeleteBST(&(*T) -> rchild, key);
  }
}
Delete(BiTree *T) {
  BiTree q,s;
  if (!(*T) -> lchild) {    //左孩子为空，只需重接右子树
    q = *T;
    *T = (*T) -> rchild;
    free(q);
  } else if (!(*T) -> rchild) {
    q = *T;
    *T = (*T) -> lchild;
    free(q);
  } else {          //左右子树均不为空
    q = *T;
    s = (*T) -> lchild;
    while (s -> rchild) {
      q = s;
      s = s -> rchild;
    }
    (*T) -> data = s -> data;
    if (q != *T)
      q -> rchild = s -> lchild;
    else
      q -> lchild = s -> lchild;

  }
}
void main() {
  int i;
  int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
 // BiTree T = NULL;
    BiTNode T;           //声明指针；地址
   // T = (BiTNode *)malloc(sizeof(BiTNode));
  for (i = 0; i < 10; i++) {
    InsertBST(&T, a[i]);               //传入地址的地址，注意接受处，函数调用处用BiTree *T;
  }
  printf("创建成功,结果为：\n");
  //树的中序遍历
  InOrderTraverse(&T);         //T是一个BiTree==指针，在第37行接受时必须用指针，类型要相匹配
 // DeleteBST(&T,58);
 // printf("删除58后的遍历结果:\n");
 // InOrderTraverse(T);
}





























