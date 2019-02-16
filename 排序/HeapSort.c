#include <stdio.h>
typedef struct {
  int r[10];
  int length;
} SqList;
void HeapAdjust (SqList *L, int s, int m) {
    printf("调整%d,\n", s);
  int j, temp;
  temp = L ->r[s];
  for (j = 2 * s; s <= m; j *= 2) {
    if (j < m && L ->r[j] < L ->r[j + 1])
       ++ j;
    if (temp >= L ->r[j])
       break;
    L ->r[s] = L ->r[j];
    s = j;
  }
  L ->r[s] = temp;
}
void swap (SqList *L, int i, int j) {
    printf("交换\n");
   int temp;
   temp = L ->r[i];
   L ->r[i] = L ->r[j];
   L ->r[j] = temp;
}
void HeapSort (SqList *L) {
  int i;
  for (i = L ->length /2; i > 0; i--) {
    printf("进入第一次排序\n");
    HeapAdjust(L, i, L ->length);
  }
  for (i = L ->length; i > 1; i --) {
      printf("进入第二次排序\n");
    swap(L, 1, i);             //将顶堆记录的第一个和最后一个进行排序
    HeapAdjust(L, 1, i - 1);
  }
}
void main () {
  int a[10] = {0, 2, 3, 1, 5, 6, 7, 8, 9, 4,}, i;
  SqList *L;
  L -> length = 10;
  for (i = 0; i <= 9; i++) {
    L ->r[i] = a[i];
  }
  HeapSort(L);
  printf("排序后的结果\n");
  for(i = 1; i <= 9; i++) {
    printf("第%d个元素是%d\n",i,L ->r[i]);
 }

}
