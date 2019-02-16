#define OK 1
#define ERROR 0
#define  NULL  ((void *)0)
typedef char SElemType;
typedef int Status;
typedef struct StackNode {
  SElemType data;
  struct StackNode *next;
} StackNode, *LinkStackPtr;
//LinkStackPtr是指向StackNode型的指针
typedef struct LinkStackPtr {
  LinkStackPtr top;
  int count;
} LinkStack;
//初始化栈
void InitStack(LinkStack *s) {
   // printf("s.count: %d", s.count);
 // s = (LinkStack)malloc(sizeof(StackNode));
  s -> top = NULL;
  s -> count = 0;
  printf("s.count: %d", s -> count);
}
//插入元素e为新的栈顶元素
Status Push (LinkStack *s, SElemType e) {
  printf("count%d", s -> count);
  LinkStackPtr temp = (LinkStackPtr)malloc(sizeof(StackNode));
  temp -> data = e;
  temp -> next = s -> top;
  s -> top = temp;
  s -> count ++;
  printf("当前栈容量：%d、\n", s -> count);
  return OK;
}
//删除栈顶元素
Status Pop(LinkStack *s, SElemType *e) {
  LinkStackPtr p;
  if (!StackEmpty(*s)) return ERROR;
  p = s -> top;
  *e = s -> top -> data;
  printf("*e = s -> top -> data;%c\n", *e);
  s -> top = s -> top -> next;
  free(p);
  s -> count --;
  return OK;
}
//是否空栈
StackEmpty(LinkStack s) {
  //return s.count;
  if(s.top == NULL){
    return ERROR;
  }
  return OK;
}
void main(){
  LinkStack s;
  // printf("s.count: %d", s.count);
  SElemType c, del;
  InitStack(&s);
  printf("请输入要入栈的元素，以#结束\n");
  scanf("%c", &c);
  while(c != '#'){
    Push(&s,c);
    scanf("%c", &c);
  }
  printf("输入完毕,开始出栈\n");
  Pop(&s,&del);
  printf("开始出栈元素: %c", del);
}
