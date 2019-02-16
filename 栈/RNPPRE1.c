#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 1000
typedef char ElemType;
typedef struct {
  ElemType *base;
  ElemType *top;
  int stackSize;
}sqStack;
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
  if (s -> top == s -> base ) {
    return;
  }
  *e = * --(s -> top);
}
int StackLen (sqStack s) {
  return (s.top - s.base);
}
int main() {
   sqStack s;
   char c, e;
   char tempArr[MAXBUFFER];
   int j = 0, i = 0;
  // double d, e;
   InitStack( &s );
   printf("请输入中缀表达式，以#结束\n");
   scanf("%c", &c);
   while( c != '#'){
     while( c >= '0' && c <= '9' ){
        printf("%c", c);  //5  3 7
        tempArr[j++] = c;
        scanf("%c", &c);
        if(c < '0' || c > '9' ) {
          printf(" ");
          tempArr[j++] = " ";
        }
     }
     if ( c == ')') {
       Pop(&s, &e);
       while( e != '(' ){
         printf("%c ", e);
         tempArr[j++] = e;
         Pop(&s, &e);
       }
     } else if ( c == '+' || c == '-') {
       if ( ! StackLen(s) ) { //空栈
         Push(&s, c);
       } else {
         do {
            Pop(&s, &e);
            if (e == '(') {
              Push(&s, e);  //???
            } else {
              printf("%c ", e);   //* +
              tempArr[j++] = e;
            }
         }while( StackLen(s) && e != '(');
         Push(&s, c);
       }
     }else if (c == '*' || c == '/' || c == '(') {
       Push(&s, c);
     } else if (c == '#') {
       break;
     } else {
        printf("输入格式错误\n");
        return -1;
     }
     scanf("%c", &c);
   }
   while(StackLen(s)){
    Pop(&s, &e);
    printf("%c ", e);
    tempArr[j++] = e;
   }
   printf("数组长度%d",j);
   for (i = 0; i < j; i++) {
     printf("第%d个元素是%c\n", i, tempArr[i]);
   }
  return 0;
}


