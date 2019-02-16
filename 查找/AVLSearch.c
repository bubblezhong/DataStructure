#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define LH 1
#define EH 0
#define RH -1
typedef struct BiTNode {
  int data;
  int bf;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
//��������ƽ��������Ĳ��������
int InsertAVL(BiTree *T, int e, int *taller) {
  if (!*T) {
    //�����µĽڵ㣬�����ߣ���tallerΪtrue
    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T) -> data = e;
    (*T) -> lchild = (*T) -> rchild = NULL;
    (*T) -> bf = EH;
    *taller = TRUE;
  } else {
    if (e == (*T) -> data) {
     //�����Ѵ��ں�e��ͬ�Ĺؼ��ֵĽ�㣬���ٲ���
       *taller = FALSE;
       return FALSE;
    }
    if (e < (*T) -> data) {
        if (!InsertAVL(&(*T) -> lchild, e, taller))       //δ����
          return FALSE;
        if (*taller) {
           switch((*T) -> bf) {         //���T��ƽ��,
             case LH:                   //ԭ�����������������ߣ���Ҫ����ƽ�⴦��
                printf("���뺯��LeftBalance\n");
               LeftBalance(T);
               printf("�ɹ�����1��\n");
               *taller = FALSE;
               break;
             case EH:                   //ԭ�����������ȸߣ��������������߶�����
               (*T) -> bf = LH;
               *taller = TRUE;
                break;
             case RH:                   //ԭ�����������������ߣ��������������ȸ�
                (*T) -> bf = EH;
                *taller = FALSE;
                break;
           }
        }
    } else {
      if (!InsertAVL(&(*T) -> lchild, e, taller))       //δ����
          return FALSE;
      }
      if (*taller) {
        switch((*T) -> bf) {
          case LH:
            (*T) -> bf = EH;
            *taller = FALSE;
            break;
          case EH:
            (*T) -> bf = RH;
            *taller = TRUE;
            break;
          case RH:
            printf("���뺯��RightBalance\n");
            RightBalance(T);
            printf("�ɹ�����1��\n");
            *taller = FALSE;
            break;
        }
      }
  }
  return TRUE;
}
//��������
void L_Rotate(BiTree *p) {
  BiTree L;
  L = (*p) -> lchild;
  (*p) -> lchild = L ->rchild;
  L ->rchild = *p;
  *p = L;
}
void R_Rotate(BiTree *p) {
  BiTree R;
  R = (*p) -> rchild;
  (*p) -> rchild = R ->lchild;
  R ->rchild = *p;
  *p = R;
}
void LeftBalance (BiTree *T) {
  BiTree L, Lr;
  L = (*T) -> lchild;             //Lָ��T�������������
  switch (L -> bf) {
    //���T����������ƽ��ȣ�������Ӧ��ƽ�⴦��
    case LH:              //�½ڵ������T�����ӵ��������ϣ�������������
      (*T) -> bf = L -> bf = EH;
      R_Rotate(T);
      break;
    case RH:               //�½ڵ������T�����ӵ��������� ,˫������
       Lr = L -> rchild;
       switch(Lr -> bf) {       //�޸�T�������ӵ�ƽ������
         case LH:
           (*T) -> bf = RH;
           L -> bf = EH;
           break;
         case EH:
           (*T) ->bf = L ->bf = EH;
           break;
         case RH:
            (*T) ->bf = EH;
            L ->bf = LH;
            break;
       }
     Lr -> bf = EH;
     L_Rotate(&(*T) -> lchild);
     R_Rotate(T);
     printf("��ת�ɹ�\n");
  }
}
void RightBalance(BiTree *T)
{
 BiTree R,Rl;
 R=(*T)->rchild;
 switch(R->bf)
 {
  case RH://�½ڵ����T���Һ��ӵ��������ϣ�Ҫ������������
   (*T)->bf=R->bf=EH;
   L_Rotate(T);
   break;
  case LH://�½ڵ����T���Һ��ӵ��������ϣ�Ҫ��˫������
   Rl=R->lchild;
   switch(Rl->bf)
   {
    case LH:
     (*T)->bf=EH;
     R->bf=RH;
     break;
    case EH:
     (*T)->bf=R->bf=EH;
     break;
    case RH:
     (*T)->bf=LH;
     R->bf=EH;
     break;
   }
   Rl->bf=EH;
   R_Rotate(&(*T)->rchild);
   L_Rotate(T);
 }
}
void main() {
  int i;
  int a[10] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
  BiTree T = NULL;
  int taller;
  for (i = 0; i < 10; i++) {
        printf("��%d��\n", i);
    InsertAVL(&T, a[i], &taller);
  }
}









































