#include <stdio.h>
typedef struct {
  int r[11];
  int length;
}SqList;
void InsertSort (SqList *L) {
  int i, j;
  for (i = 2; i < L ->length; i++) {
    if (L ->r[i] < L ->r[i - 1]) {
        L->r[0] = L ->r[i];
        for (j = i - 1; L ->r[j] > L ->r[0]; j--) {
          L ->r[j + 1] = L ->r[j];
        }
        L ->r[j + 1] = L ->r[0];
    }
  }
}
void main() {
 // int i;
  SqList *L;
  int a[11] = {0, 5, 6, 9, 8, 7, 3, 2, 1, 4, 7}, i;
  L -> length = 11;
  for (i = 0; i <= 10; i++) {
    L ->r[i] = a[i];
  }
  InsertSort(L);
  printf("�����Ľ��\n");
  for(i = 1; i <= 10; i++) {
    printf("��%d��Ԫ����%d\n",i,L ->r[i]);
  }
}
