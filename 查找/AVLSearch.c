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
//主函数，平衡二叉树的插入与调整
int InsertAVL(BiTree *T, int e, int *taller) {
  if (!*T) {
    //插入新的节点，树长高，置taller为true
    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T) -> data = e;
    (*T) -> lchild = (*T) -> rchild = NULL;
    (*T) -> bf = EH;
    *taller = TRUE;
  } else {
    if (e == (*T) -> data) {
     //树中已存在和e相同的关键字的结点，不再插入
       *taller = FALSE;
       return FALSE;
    }
    if (e < (*T) -> data) {
        if (!InsertAVL(&(*T) -> lchild, e, taller))       //未插入
          return FALSE;
        if (*taller) {
           switch((*T) -> bf) {         //检查T的平衡,
             case LH:                   //原本左子树比右子树高，需要做左平衡处理
                printf("进入函数LeftBalance\n");
               LeftBalance(T);
               printf("成功结束1、\n");
               *taller = FALSE;
               break;
             case EH:                   //原本左右子树等高，现因左子树增高而增高
               (*T) -> bf = LH;
               *taller = TRUE;
                break;
             case RH:                   //原本右子树比左子树高，现在左右子树等高
                (*T) -> bf = EH;
                *taller = FALSE;
                break;
           }
        }
    } else {
      if (!InsertAVL(&(*T) -> lchild, e, taller))       //未插入
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
            printf("进入函数RightBalance\n");
            RightBalance(T);
            printf("成功结束1、\n");
            *taller = FALSE;
            break;
        }
      }
  }
  return TRUE;
}
//右旋处理
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
  L = (*T) -> lchild;             //L指向T的左子树跟结点
  switch (L -> bf) {
    //检查T的左子树的平衡度，并做相应的平衡处理
    case LH:              //新节点插入在T的左孩子的左子树上，做简单右旋处理
      (*T) -> bf = L -> bf = EH;
      R_Rotate(T);
      break;
    case RH:               //新节点插入在T的左孩子的右子树上 ,双旋处理
       Lr = L -> rchild;
       switch(Lr -> bf) {       //修改T及其左孩子的平衡因子
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
     printf("左转成功\n");
  }
}
void RightBalance(BiTree *T)
{
 BiTree R,Rl;
 R=(*T)->rchild;
 switch(R->bf)
 {
  case RH://新节点插在T的右孩子的右子树上，要做单左旋处理
   (*T)->bf=R->bf=EH;
   L_Rotate(T);
   break;
  case LH://新节点插在T的右孩子的左子树上，要做双旋处理
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
        printf("第%d次\n", i);
    InsertAVL(&T, a[i], &taller);
  }
}









































