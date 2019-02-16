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
//清空栈
void ClearStack (sqStack *s) {
  s -> top = s -> base;
}
//销毁栈
void DestoryStack (sqStack *s) {
  int i, len = s -> stackSize;
  for (i = 0; i < len; i ++) {
    free(s -> base);
    s -> base ++;
  }
  s -> base = s -> top = NULL;
  s -> stackSize = 0;
}
//栈的初始化
void InitStack(sqStack *s) {
  s -> base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
  if ( !s -> base ) {
    exit(0);
  }
  s -> top = s -> base;
  s -> stackSize = STACKINCREMENT;
}
//入栈
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
//出栈
void Pop (sqStack *s, ElemType *e) {
  printf("开始出栈%d的、\n", s -> top == s -> base );
  if (s -> top == s -> base ) {
    return;
  }
  *e = * --(s -> top);
  printf("出栈元素%c,、\n", *e);
}
int StackLen (sqStack s) {
  return (s.top - s.base);
}
void main() {
  sqStack s;
  ElemType c;
  int len, i, currentData, sum = 0;
  InitStack(&s);
  printf("请输入二进制数，用#表示结束\n");
  scanf("%c", &c);
  while( c != '#'){
    Push(&s, c);
    scanf("%c", &c);
  }
  getchar();
  len = StackLen(s);
  printf("当前栈容量为：%d", len);
  for (i = 0; i < len; i++) {
    Pop(&s, &c);
    printf("currentData: %c\n", c);
    sum = sum + (c - 48) * pow(2,i);
  }
  printf("转化为十进制是：%d\n", sum);
}
