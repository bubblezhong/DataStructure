#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
typedef char ElemType;
typedef struct {
  ElemType *base;
  ElemType *top;
  int stackSize;
}sqStack;
//���ջ
void ClearStack (sqStack *s) {
  s -> top = s -> base;
}
//����ջ
void DestoryStack (sqStack *s) {
  int i, len = s -> stackSize;
  for (i = 0; i < len; i ++) {
    free(s -> base);
    s -> base ++;
  }
  s -> base = s -> top = NULL;
  s -> stackSize = 0;
}
//ջ�ĳ�ʼ��
void InitStack(sqStack *s) {
  s -> base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
  if ( !s -> base ) {
    exit(0);
  }
  s -> top = s -> base;
  s -> stackSize = STACKINCREMENT;
}
//��ջ
void Push (sqStack *s, ElemType e) {
  if (s -> top - s -> base >= s -> stackSize) {
    s -> base = (ElemType *)realloc(s -> base, (s -> stackSize + STACKINCREMENT) * sizeof(ElemType));
    if ( !s -> base ) {
     exit(0);
    }
  }
  *(s -> top) = e;
  s -> top ++;
}
//��ջ
void Pop (sqStack *s, ElemType *e) {
  printf("��ʼ��ջ%d�ġ�\n", s -> top == s -> base );
  if (s -> top == s -> base ) {
    return;
  }
  *e = * --(s -> top);
  printf("��ջԪ��%c,��\n", *e);
}
int StackLen (sqStack s) {
  return (s.top - s.base);
}
void main() {
  sqStack s;
  ElemType c;
  int len, i, currentData, sum = 0;
  InitStack(&s);
  printf("�����������������#��ʾ����\n");
  scanf("%c", &c);
  while( c != '#'){
    Push(&s, c);
    scanf("%c", &c);
  }
  getchar();
  len = StackLen(s);
  printf("��ǰջ����Ϊ��%d", len);
  for (i = 0; i < len; i++) {
    Pop(&s, &c);
    printf("currentData: %c\n", c);
    sum = sum + (c - 48) * pow(2,i);
  }
  printf("ת��Ϊʮ�����ǣ�%d\n", sum);
}
