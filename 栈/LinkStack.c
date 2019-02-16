#define OK 1
#define ERROR 0
#define  NULL  ((void *)0)
typedef char SElemType;
typedef int Status;
typedef struct StackNode {
  SElemType data;
  struct StackNode *next;
} StackNode, *LinkStackPtr;
//LinkStackPtr��ָ��StackNode�͵�ָ��
typedef struct LinkStackPtr {
  LinkStackPtr top;
  int count;
} LinkStack;
//��ʼ��ջ
void InitStack(LinkStack *s) {
   // printf("s.count: %d", s.count);
 // s = (LinkStack)malloc(sizeof(StackNode));
  s -> top = NULL;
  s -> count = 0;
  printf("s.count: %d", s -> count);
}
//����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push (LinkStack *s, SElemType e) {
  printf("count%d", s -> count);
  LinkStackPtr temp = (LinkStackPtr)malloc(sizeof(StackNode));
  temp -> data = e;
  temp -> next = s -> top;
  s -> top = temp;
  s -> count ++;
  printf("��ǰջ������%d��\n", s -> count);
  return OK;
}
//ɾ��ջ��Ԫ��
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
//�Ƿ��ջ
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
  printf("������Ҫ��ջ��Ԫ�أ���#����\n");
  scanf("%c", &c);
  while(c != '#'){
    Push(&s,c);
    scanf("%c", &c);
  }
  printf("�������,��ʼ��ջ\n");
  Pop(&s,&del);
  printf("��ʼ��ջԪ��: %c", del);
}
