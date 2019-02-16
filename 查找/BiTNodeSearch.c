#include <stdio.h>
typedef struct BiTNode {
  int data;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
//�����������Ĳ���
SearchBST(BiTree T, int key, BiTree f, BiTree *p) {   //Ϊʲô��BiTree *p ��������
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
//�����������Ĳ���
InsertBST(BiTree *T, int key) {
  BiTree p, s;
  if (!SearchBST(*T, key, NULL, &p)) {   //p�ı��Ժ���Ҫʹ�ã����Դ����ַ�ĵ�ַ
    s = (BiTree)malloc(sizeof(BiTNode));
    s -> data = key;
    s -> lchild = s -> rchild = NULL;
    if (!p)
      *T = s;               //�����sΪ�µĸ��ڵ�
    else if (key < p -> data)
      p -> lchild = s;      //����sΪ����
    else
      p -> rchild = s;
    return 1;

  } else {
    return 0;                 //�������йؼ��֣���������
  }
}*/
InsertBST(BiTNode *T, int key) {
  BiTree p, s;
  if (!SearchBST(T, key, NULL, &p)) {   //p�ı��Ժ���Ҫʹ�ã����Դ����ַ�ĵ�ַ
    s = (BiTree)malloc(sizeof(BiTNode));
    s -> data = key;
    s -> lchild = s -> rchild = NULL;
    if (!p)
      T = s;               //�����sΪ�µĸ��ڵ�
    else if (key < p -> data)
      p -> lchild = s;      //����sΪ����
    else
      p -> rchild = s;
    return 1;

  } else {
    return 0;                 //�������йؼ��֣���������
  }
}
//���������������
int InOrderTraverse(BiTree T){
  if (T == NULL)
    return 0;
  InOrderTraverse(T -> lchild);
  printf("%d\n", T -> data);
  InOrderTraverse(T -> rchild);
}
//������������ɾ��
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
  if (!(*T) -> lchild) {    //����Ϊ�գ�ֻ���ؽ�������
    q = *T;
    *T = (*T) -> rchild;
    free(q);
  } else if (!(*T) -> rchild) {
    q = *T;
    *T = (*T) -> lchild;
    free(q);
  } else {          //������������Ϊ��
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
    BiTNode T;           //����ָ�룻��ַ
   // T = (BiTNode *)malloc(sizeof(BiTNode));
  for (i = 0; i < 10; i++) {
    InsertBST(&T, a[i]);               //�����ַ�ĵ�ַ��ע����ܴ����������ô���BiTree *T;
  }
  printf("�����ɹ�,���Ϊ��\n");
  //�����������
  InOrderTraverse(&T);         //T��һ��BiTree==ָ�룬�ڵ�37�н���ʱ������ָ�룬����Ҫ��ƥ��
 // DeleteBST(&T,58);
 // printf("ɾ��58��ı������:\n");
 // InOrderTraverse(T);
}





























