#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10
typedef double ElemType;
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
  printf("\n入栈成功: %f\n", e);
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
   char c;
   char str[MAXBUFFER];
   int i = 0;
   double d, e;
   InitStack( &s );
   printf("请按逆波兰表达式输入待计算数据，数据与运算符之间用空格隔开，以#结束\n");
   scanf("&c", &c);
   while( c != '#' ){
    //用于过滤数据
     while ( isdigit(c) || c == '.') {
       printf("c值：%c\n", c);
       str[i++] = c;
        str[i] = '\0';
        if (i >= 10) {
            printf("出错：输入的单个是数据过大\n");
            return -1;
        }
        scanf("%c", &c);
        if (c == ' ') {
          d = atof(str);
          Push(&s, d);
          i = 0;
          break;
        }
     }
     switch ( c ) {
       case '+':
         Pop(&s, &e);
         Pop(&s, &d);
         Push(&s, d + e);
         break;
       case '-':
         Pop(&s, &e);
         Pop(&s, &d);
         Push(&s, d - e);
         break;
       case '*':
         Pop(&s, &e);
         Pop(&s, &d);
         Push(&s, d * e);
         break;
       case '/':
         Pop(&s, &e);
         Pop(&s, &d);
         if( e != 0 ) {
           Push(&s, d / e);
         } else {
           printf("\n出错：除数为零\n");
           return -1;
         }
         break;
      }
     scanf("%c", &c);
   }
   Pop(&s, &d);
   printf("最终的结果为%f\n", d);
   return 0;
}

