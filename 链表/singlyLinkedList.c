#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define  NULL  ((void *)0)
typedef int ElemType;
typedef int Status;
//��ʼ��������
typedef struct Node {
  ElemType data;
  struct Node *next;
} Node;
//����inkList
typedef struct Node* LinkList;
//LinkList ������
//������Ķ�ȡ(Ϊʲô*e???����LinkList *L)
//�������Ҫ�����Ա���в������������ô������ַ���������崦ʹ��ָ�룻
Status GetElem (LinkList L, int i, ElemType *e){
  printf ("�����ȡ����%d\n", i, L);
  int j;
  LinkList p;            //�����ڵ�p
  p = L -> next;         //ָ������ĵ�һ���ڵ㣨���������
  j = 1;
  //printf("p && j < i %d\n", p);
  while( p && j < i ){
    //printf("j�Ƕ���%d\n", j);
    p = p -> next;
    ++j;
  }
  if ( !p || j>i ){
    return ERROR;
  }
  *e = p -> data;
 // printf("*e��%d\n", *e);
  return OK;
}
Status ListInsert (LinkList* L, int i, ElemType e) {
  printf("Ҫ�����Ԫ�ؼ�λ��%d,%d,\n", e, i);
  int j;
  LinkList p, s;
  j = 1;
  p = *L;
  while ( p -> next && j<i ) { // 3 (5)
    p = p -> next; //3
    ++j;//2
  }
    if ( !p || j>i ) {
      return ERROR;
    }
  s = (LinkList)malloc(sizeof(Node));
  s -> data = e;
  s -> next = p -> next;  //null
  p -> next = s;
  printf("����Ԫ��%d�ɹ�,\n", s -> data);
  return OK;
}
Status ListDelete (LinkList *L, int i, ElemType *e) {
   int j;
   LinkList p, q;
   p = *L;
   j = 1;
   //Ϊʲô��p -> next:p�Ǳ�ɾ��Ԫ�ص�ǰһ���Ľڵ� 1 2 3
   while ( p -> next && j < i ) {  //  4
     p = p -> next;  // 1 2 p=3
     ++j;  //2 3 4
   }
   if ( !( p -> next ) || j > i ) {
    return ERROR;
   }
   q = p -> next;   //null
   p -> next = q -> next;
   *e = q -> data;
   printf("��ɾ��Ԫ��q -> data: %d\n", q -> data);
   free(q);
   return OK;
}
showAllData(LinkList L) {
  int j;
  LinkList p;
  p = L -> next;
  j = 1;
    while (p){
      printf("��%d��Ԫ����%d\n", j,p -> data);
      p = p -> next;
      j++;
    }
}
//�������������
void CreateListHeade (LinkList *L, int n) {
  LinkList p, r;
  int i;
  int temData;
  //Ϊ�������ڴ棬���ұ���ͷָ�룻
  * L = (LinkList)malloc(sizeof(Node));
  r = *L;
  for ( i = 0; i < n; i ++ ){
    printf("�������%d��Ԫ�أ�\n", i);
    scanf("%d",&temData);
    p = (LinkList)malloc(sizeof(Node));
    p -> data = temData;
    r -> next = p;
    r = p;
    printf("p -> data��%d,p: %d\n",p -> data, p);
  }
  r -> next = NULL;  //��ʾ��ǰ�������
}
//�����������ɾ��
Status ListClear (LinkList *L) {
  LinkList p, q;
  p = *L;
  while (p) {
    q = p -> next;
    free(p);
    p = q;
  }
  (*L) -> next = NULL;
  printf("ɾ������");
  return OK;
}
void main() {
  LinkList linkList;
  int i = 2;
  int result;
  int n = 2;
  int temp = 1;
  int mark;
  int delData;
    CreateListHeade(&linkList, n);
    showAllData(linkList);
    while ( temp < 3 ) {
      ListInsert(&linkList, i, temp + 5);
      temp++;
    }
    showAllData(linkList);
    GetElem(linkList, i, &result);
    printf("��ȡ����%dԪ��%d\n", i, result);
    printf("������Ҫɾ����Ԫ���±�\n");
    scanf("%d", &mark);
    ListDelete(&linkList, mark, &delData);
    printf("ɾ����Ľ����\n");
    showAllData(linkList);
    //ListClear(&linkList);
    //showAllData(linkList);

}
