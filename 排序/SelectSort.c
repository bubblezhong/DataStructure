#include <stdio.h>
#define MAXSIZE 10
typedef struct {
  int r[MAXSIZE];
  int length;
} SqList;
SelectSort (SqList *L) {
  int i, j, min;
  for (i = 0; i < L ->length; i++) {
    min = i;
    for (j = i + 1; j < L -> length - 1; j ++) {
        if (L->r[min] > L -> r[j]) {
            min = j;
        }
    }
    if(i != min) {
      swap(L, i, min);
    }
  }
}
swap (SqList *L, int i, int j) {
  int temp;
  temp = L -> r[i];
  L -> r[i] =  L -> r[j];
  L -> r[j] = temp;
}
void main () {
  int a[10] = {4, 2, 3, 3, 5, 6, 7, 8, 9, 0}, i;
  SqList *L;
  L -> length = MAXSIZE;
  for (i = 0; i <= 9; i++) {
    L ->r[i] = a[i];
  }
  printf("length：%d\n",L -> length);
  SelectSort(L);
  printf("排序后的结果\n");
  for(i = 0; i <= 9; i++) {
    printf("第%d个元素是%d\n",i,L ->r[i]);
 }
}




























