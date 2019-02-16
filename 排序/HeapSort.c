#include <stdio.h>
typedef struct {
  int r[10];
  int length;
} SqList;
void HeapAdjust (SqList *L, int s, int m) {
    printf("����%d,\n", s);
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
    printf("����\n");
   int temp;
   temp = L ->r[i];
   L ->r[i] = L ->r[j];
   L ->r[j] = temp;
}
void HeapSort (SqList *L) {
  int i;
  for (i = L ->length /2; i > 0; i--) {
    printf("�����һ������\n");
    HeapAdjust(L, i, L ->length);
  }
  for (i = L ->length; i > 1; i --) {
      printf("����ڶ�������\n");
    swap(L, 1, i);             //�����Ѽ�¼�ĵ�һ�������һ����������
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
  printf("�����Ľ��\n");
  for(i = 1; i <= 9; i++) {
    printf("��%d��Ԫ����%d\n",i,L ->r[i]);
 }

}
